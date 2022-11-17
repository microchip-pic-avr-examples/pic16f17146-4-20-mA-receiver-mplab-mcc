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

#include "boost.h"
#include "../mcc_generated_files/spi/mssp1.h"
#include "../mcc_generated_files/spi/spi_interface.h"
#include "../mcc_generated_files/system/pins.h"
#include "../mcc_generated_files/system/config_bits.h"

// Control register values for Boost_DAC
#define CTRL_DACA       0x00
#define CTRL_UNBUFFERED	0x00
#define CTRL_BUFFERED	0x40
#define CTRL_GAIN_1X	0x20
#define CTRL_GAIN_2X	0x00
#define CTRL_ENABLED	0x10
#define CTRL_DISABLED	0x00

// Macro Declarations for Boost_ADC
#define POWER_UP_DELAY_us          300     
#define CONVERSION_TIME_ms         75     

#define ADC_REFERENCE           2.048
#define ADC_HIGHEST_COUNT       2097151.0
#define VOLTAGE_DEVIDER_FACTOR  33.33

#define CONVERSION_SLOPE    133.51135
#define CONVERSION_CONSTANT 5128.171

static uint32_t Boost_ReadADC(void);
static void Boost_WriteDAC(uint16_t value);

void Boost_Enable()
{
    boost_EN_SetHigh();
}

void Boost_Disable()
{
    boost_EN_SetLow();
}

void Boost_SetVoltage(float value)
{
    double dacCount = 0;
    uint16_t dacCount_int = 0;
    
    dacCount = CONVERSION_SLOPE * (double)value;
    dacCount = CONVERSION_CONSTANT - dacCount;
    
    dacCount_int = (uint16_t)dacCount;
    Boost_WriteDAC(dacCount_int); 
}

double Boost_ReadVoltage()
{
    uint32_t adcResult = 0;
    double boostVolatge = 0;
    
    adcResult = Boost_ReadADC();
    
    adcResult = adcResult >> 7;
    adcResult = adcResult & 0b111111111111111111111 ;
    
    boostVolatge = ADC_REFERENCE * (double)adcResult;
    boostVolatge = boostVolatge / ADC_HIGHEST_COUNT;
    boostVolatge = boostVolatge * VOLTAGE_DEVIDER_FACTOR ;
    
    return(boostVolatge);
}

static void Boost_WriteDAC(uint16_t value)
{
    uint8_t ctrl_byte = CTRL_DACA | CTRL_UNBUFFERED | CTRL_GAIN_1X | CTRL_ENABLED;
	
    boost_CS1_SetLow(); /* set Boost_DAC chip select low */
    while(!SPI1.Open(MSSP1_DEFAULT));

    SPI1.ByteExchange(((uint8_t)(value >> 8) & 0x0F) | (ctrl_byte & 0xF0));
    SPI1.ByteExchange((uint8_t) (value & 0x00FF));

    SPI1.Close();
    boost_CS1_SetHigh(); /* set Boost_DAC chip select high */
}

static uint32_t Boost_ReadADC()
{
    uint8_t  readData[4];
    uint8_t byteCounter = 0;
    uint32_t conversionResult;
    
    boost_CS2_SetHigh();
    while(!SPI1.Open(MSSP1_DEFAULT));
    boost_CS2_SetLow();
    __delay_us(POWER_UP_DELAY_us);
    boost_CS2_SetHigh();
    __delay_ms(CONVERSION_TIME_ms);
        
    boost_CS2_SetLow();
    
    for (byteCounter = 0 ; byteCounter < 4; byteCounter++)
    {
        readData[byteCounter] = SPI1.ByteExchange(0xF5);
    }
    
    boost_CS2_SetHigh();    /* set Boost_ADC chip select high */
    SPI1.Close();
    
    conversionResult = readData[0];
    conversionResult = (conversionResult << 8) | readData[1];
    conversionResult = (conversionResult << 8) | readData[2];
    conversionResult = (conversionResult << 8) | readData[3];
              
    return conversionResult;
}
