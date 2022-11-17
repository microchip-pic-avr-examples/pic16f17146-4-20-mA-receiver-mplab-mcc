/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.0.0
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

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RA2 aliases
#define boost_CS2_TRIS                 TRISAbits.TRISA2
#define boost_CS2_LAT                  LATAbits.LATA2
#define boost_CS2_PORT                 PORTAbits.RA2
#define boost_CS2_WPU                  WPUAbits.WPUA2
#define boost_CS2_OD                   ODCONAbits.ODCA2
#define boost_CS2_ANS                  ANSELAbits.ANSA2
#define boost_CS2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define boost_CS2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define boost_CS2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define boost_CS2_GetValue()           PORTAbits.RA2
#define boost_CS2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define boost_CS2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define boost_CS2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define boost_CS2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define boost_CS2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define boost_CS2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define boost_CS2_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define boost_CS2_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set IO_RA5 aliases
#define boost_EN_TRIS                 TRISAbits.TRISA5
#define boost_EN_LAT                  LATAbits.LATA5
#define boost_EN_PORT                 PORTAbits.RA5
#define boost_EN_WPU                  WPUAbits.WPUA5
#define boost_EN_OD                   ODCONAbits.ODCA5
#define boost_EN_ANS                  ANSELAbits.ANSA5
#define boost_EN_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define boost_EN_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define boost_EN_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define boost_EN_GetValue()           PORTAbits.RA5
#define boost_EN_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define boost_EN_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define boost_EN_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define boost_EN_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define boost_EN_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define boost_EN_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define boost_EN_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define boost_EN_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set IO_RB4 aliases
#define RB4_IN_N_TRIS                 TRISBbits.TRISB4
#define RB4_IN_N_LAT                  LATBbits.LATB4
#define RB4_IN_N_PORT                 PORTBbits.RB4
#define RB4_IN_N_WPU                  WPUBbits.WPUB4
#define RB4_IN_N_OD                   ODCONBbits.ODCB4
#define RB4_IN_N_ANS                  ANSELBbits.ANSB4
#define RB4_IN_N_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_IN_N_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_IN_N_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_IN_N_GetValue()           PORTBbits.RB4
#define RB4_IN_N_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_IN_N_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_IN_N_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_IN_N_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_IN_N_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define RB4_IN_N_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define RB4_IN_N_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define RB4_IN_N_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set IO_RB7 aliases
#define IO_RB7_TRIS                 TRISBbits.TRISB7
#define IO_RB7_LAT                  LATBbits.LATB7
#define IO_RB7_PORT                 PORTBbits.RB7
#define IO_RB7_WPU                  WPUBbits.WPUB7
#define IO_RB7_OD                   ODCONBbits.ODCB7
#define IO_RB7_ANS                  ANSELBbits.ANSB7
#define IO_RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define IO_RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define IO_RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define IO_RB7_GetValue()           PORTBbits.RB7
#define IO_RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define IO_RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define IO_RB7_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define IO_RB7_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define IO_RB7_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define IO_RB7_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define IO_RB7_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define IO_RB7_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set IO_RC2 aliases
#define IO_RC2_TRIS                 TRISCbits.TRISC2
#define IO_RC2_LAT                  LATCbits.LATC2
#define IO_RC2_PORT                 PORTCbits.RC2
#define IO_RC2_WPU                  WPUCbits.WPUC2
#define IO_RC2_OD                   ODCONCbits.ODCC2
#define IO_RC2_ANS                  ANSELCbits.ANSC2
#define IO_RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define IO_RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define IO_RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define IO_RC2_GetValue()           PORTCbits.RC2
#define IO_RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define IO_RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define IO_RC2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define IO_RC2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define IO_RC2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define IO_RC2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define IO_RC2_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define IO_RC2_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set IO_RC3 aliases
#define RC3_IN_P_TRIS                 TRISCbits.TRISC3
#define RC3_IN_P_LAT                  LATCbits.LATC3
#define RC3_IN_P_PORT                 PORTCbits.RC3
#define RC3_IN_P_WPU                  WPUCbits.WPUC3
#define RC3_IN_P_OD                   ODCONCbits.ODCC3
#define RC3_IN_P_ANS                  ANSELCbits.ANSC3
#define RC3_IN_P_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_IN_P_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_IN_P_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_IN_P_GetValue()           PORTCbits.RC3
#define RC3_IN_P_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_IN_P_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_IN_P_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_IN_P_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_IN_P_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define RC3_IN_P_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define RC3_IN_P_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define RC3_IN_P_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set IO_RC4 aliases
#define IO_RC4_TRIS                 TRISCbits.TRISC4
#define IO_RC4_LAT                  LATCbits.LATC4
#define IO_RC4_PORT                 PORTCbits.RC4
#define IO_RC4_WPU                  WPUCbits.WPUC4
#define IO_RC4_OD                   ODCONCbits.ODCC4
#define IO_RC4_ANS                  ANSELCbits.ANSC4
#define IO_RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define IO_RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define IO_RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define IO_RC4_GetValue()           PORTCbits.RC4
#define IO_RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define IO_RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define IO_RC4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define IO_RC4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define IO_RC4_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define IO_RC4_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define IO_RC4_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define IO_RC4_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set IO_RC5 aliases
#define IO_RC5_TRIS                 TRISCbits.TRISC5
#define IO_RC5_LAT                  LATCbits.LATC5
#define IO_RC5_PORT                 PORTCbits.RC5
#define IO_RC5_WPU                  WPUCbits.WPUC5
#define IO_RC5_OD                   ODCONCbits.ODCC5
#define IO_RC5_ANS                  ANSELCbits.ANSC5
#define IO_RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IO_RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IO_RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IO_RC5_GetValue()           PORTCbits.RC5
#define IO_RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IO_RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define IO_RC5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define IO_RC5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define IO_RC5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define IO_RC5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define IO_RC5_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define IO_RC5_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set IO_RC6 aliases
#define IO_RC6_TRIS                 TRISCbits.TRISC6
#define IO_RC6_LAT                  LATCbits.LATC6
#define IO_RC6_PORT                 PORTCbits.RC6
#define IO_RC6_WPU                  WPUCbits.WPUC6
#define IO_RC6_OD                   ODCONCbits.ODCC6
#define IO_RC6_ANS                  ANSELCbits.ANSC6
#define IO_RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define IO_RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define IO_RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define IO_RC6_GetValue()           PORTCbits.RC6
#define IO_RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define IO_RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define IO_RC6_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define IO_RC6_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define IO_RC6_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define IO_RC6_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define IO_RC6_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define IO_RC6_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set IO_RC7 aliases
#define boost_CS1_TRIS                 TRISCbits.TRISC7
#define boost_CS1_LAT                  LATCbits.LATC7
#define boost_CS1_PORT                 PORTCbits.RC7
#define boost_CS1_WPU                  WPUCbits.WPUC7
#define boost_CS1_OD                   ODCONCbits.ODCC7
#define boost_CS1_ANS                  ANSELCbits.ANSC7
#define boost_CS1_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define boost_CS1_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define boost_CS1_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define boost_CS1_GetValue()           PORTCbits.RC7
#define boost_CS1_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define boost_CS1_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define boost_CS1_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define boost_CS1_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define boost_CS1_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define boost_CS1_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define boost_CS1_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define boost_CS1_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/