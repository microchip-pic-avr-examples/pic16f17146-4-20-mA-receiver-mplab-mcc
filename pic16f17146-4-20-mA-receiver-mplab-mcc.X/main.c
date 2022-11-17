 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2022] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include "boost/boost.h"
#include "application/application.h"

#define SENSOR_MAX_VALUE                (100.0F)    //sensor value corresponding to 20mA
#define SENSOR_MIN_VALUE                (0.0F)      //sensor value corresponding to 4mA
#define CURRENT_MAX                     (20.0F)   
#define CURRENT_MIN                     (4.0F)     
#define SENSOR_VALUE_RANGE              (SENSOR_MAX_VALUE - SENSOR_MIN_VALUE)
#define CURRENT_RANGE                   (CURRENT_MAX - CURRENT_MIN)
#define SENSOR_VALUE_PER_UNIT_CURRENT   (SENSOR_VALUE_RANGE / CURRENT_RANGE)
#define ADCC_MAX_COUNT                  (4095U)
#define ADCC_REFERENCE_VOLATGE          (2.048F)
#define SENSE_RESISTANCE                (82.0F)
#define SENSE_RESISTANCE_kOhm           (SENSE_RESISTANCE / 1000)
#define ADCC_STEP_SIZE                  (ADCC_REFERENCE_VOLATGE / ADCC_MAX_COUNT)

float ConvertAdccCountToVoltage(uint16_t count);
float ConvertVoltageToCurrent(float voltage);
float ConvertLoopCurrrenttoSensorParameter(float current);
void ADCC_UserThresholdInterruptHandler(void);

volatile bool currentOutOfRangeError = false;

/*
    Main application
*/
int main(void)
{
    uint16_t adccCount = 0;
    float adccOutputVoltage = 0;
    float loopCurrentValue = 0;
    float sensorValue = 0;
    double boostVoltage = 0;
    
    SYSTEM_Initialize();
    
    ADCC_SetADTIInterruptHandler(ADCC_UserThresholdInterruptHandler);
      
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

    // Enable the Peripheral Interrupts 
    INTERRUPT_PeripheralInterruptEnable(); 

    // Disable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptDisable(); 

    Boost_Enable();
    
    printf("\n\t\t**** 4-20 mA Receiver ****\n\n\r");
    printf("Setting up Voltage Required \n\r");
    Boost_SetVoltage(16);
     
    boostVoltage = Boost_ReadVoltage();
    printf("Voltage Set = %.1f V\n\r", boostVoltage);

    while (1) 
    {
        ADCC_StartConversion(channel_OPA1OUT); //start sampling opamp output
        while (!ADCC_IsConversionDone()); //wait until conversion is completed
        adccCount = ADCC_GetFilterValue(); //get average value of adcc samples
        printf("ADCC Count : %d \n\r", adccCount);

        if (!currentOutOfRangeError) 
        {
            adccOutputVoltage = ConvertAdccCountToVoltage(adccCount);
            printf("Equivalent Voltage : %.1f V\n\r", adccOutputVoltage);

            loopCurrentValue = ConvertVoltageToCurrent(adccOutputVoltage);
            printf("Equivalent Current : %.1f mA\n\r", loopCurrentValue);

            sensorValue = ConvertLoopCurrrenttoSensorParameter(loopCurrentValue);
            printf(PARAMETER_NAME " : %.1f C\n\n\r", sensorValue);
        } 
        else 
        {
            printf("\n\r---Error Detected---\n\r");          

            currentOutOfRangeError = false;
        }

        //delay is added to stop continuous operation. User can remove or modify delay according to application needs
        __delay_ms(2000);
    }
}    

/**
 * @brief This function converts ADCC count into equivalent voltage.
 * @param count - ADCC count
 * @return equivalent voltage
*/
float ConvertAdccCountToVoltage(uint16_t count)
{
    float voltage;
    
    voltage = (float) count * ADCC_STEP_SIZE;
    
    return voltage;
}

/**
 * @brief This function converts voltage into current.
 * @param voltage in volts
 * @return current
*/
float ConvertVoltageToCurrent(float voltage)
{
    float current;
    
    current = voltage / SENSE_RESISTANCE_kOhm ; //current in mA 
    
    return current;
}

/**
 * @brief This function converts measured current into equivalent sensor parameter.
 * @param urrent - measured current
 * @return equivalent sensor parameter
*/
float ConvertLoopCurrrenttoSensorParameter(float current)
{
    float convertedSensorParameter;
    
    convertedSensorParameter = (SENSOR_VALUE_PER_UNIT_CURRENT * (current - CURRENT_MIN)) + SENSOR_MIN_VALUE;
    
    return convertedSensorParameter;    
}

/**
 * @brief User interrupt handler for ADCC threshold interrupt. Interrupt occurs when current goes out of 4-20 mA range.
 * @param none
 * @return none
*/
void ADCC_UserThresholdInterruptHandler(void)
{
    currentOutOfRangeError = true;
}
