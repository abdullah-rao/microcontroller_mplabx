/* 
 * File: main
 * 
 * Author: James A. Smith
 * 
 * Based on Oli Glaser's PIC16 files "Getting started with PIC Microcontrollers"
 * http://blog.irwellsprings.com/getting-started-with-pic-microcontrollers/
 * 
 * Life after PLIB and before Harmony.  The code in EECS 2021 has to be written
 * without the handy macros in PLIB.
 * 
 * While PLIB was really nice, it's not supported anymore.  Harmony is not ready
 * and is overkill... bad pedagogically. 
 * 
 *  References:
 *  1. http://ww1.microchip.com/downloads/en/DeviceDoc/61105E.pdf
 *  2. http://umassamherstm5.org/tech-tutorials/pic32-tutorials/pic32mx220-tutorials/interrupts
 *  3. http://www.johnloomis.org/microchip/pic32/include/peripheral/timer.h.html
 *  4. http://blog.irwellsprings.com/getting-started-with-pic-microcontrollers/
 *  5. http://www.eevblog.com/forum/microcontrollers/pic32mx-quickstart/10/?wap2
 *  6. http://microchip.wikidot.com/32bit:mx-osc-config
 *
 */

// xc.h is the main include file - this contains all the "friendly names"
// for the PIC32 pins and peripherals
#include <xc.h>


// ------------------------  Configuration (begin) ----------------------------
//  There are Four configuration words that need to be dealt with:
// Config. Word 3, Config. Word 2,  Config. Word 1 and Config. Word 0,
// in that order.

// Configuration Word 3 (User ID info)
// This is for the PIC32MX250 with internal fast RC clock @ 8 MHz
// Internal system clock ("sysclock") will run at 187.5 kHz
// using FNOSC, FPLLIDIV, FPLLMUL and FPLLODIV settings.

#pragma config   JTAGEN    = OFF    // JTAG Enable OFF (only use for '250)
#pragma config   FNOSC     = FRCPLL // Fast RC w PLL 8mHz internal rc Osc
#pragma config   FPLLIDIV  = DIV_2  // 
#pragma config   FPLLMUL   = MUL_16 // PLL mul 800 khz * 15 = 12 Mhz
#pragma config   FPLLODIV  = DIV_4  // PLL Out: 12MHz / 64 187.5 kHz
#pragma config   FPBDIV    = DIV_1  // Peripheral Bus Divisor
#pragma config   FCKSM     = CSECME // Clock Switch Enable, FSCM Enabled
#pragma config   POSCMOD   = OFF    // Primary osc disabled
#pragma config   IESO      = OFF    // Internal/external switch over
#pragma config   OSCIOFNC  = OFF    // CLKO Output Signal Active on the OSCO Pin
#pragma config   FWDTEN    = OFF    // Watchdog Timer Enable:

// ------------------------  Configuration (end) ----------------------------

int global_ctr = 1;     // a global variable counter.



// Main function
int main(int argc, char** argv) {

				// Set value of PORT B output to 0. 
    
    
    // Set all pins on PORT B to output

    int local=0;
    TRISBbits.TRISB2=1;
        PORTBbits.RB2=0;	

	// Infinite Loop.  Keeps repeating.
    while(1) 
    {
    
        if(local>=5){
            local =0;
            global_ctr++;
        }    
        else{
        local++;}
        
        if (global_ctr==3)
        {PORTBbits.RB2 = 1;}
    }
	return (EXIT_SUCCESS);
}



