
#include <xc.h>


#pragma config   JTAGEN    = OFF    // JTAG Enable OFF (only use for '250)
#pragma config   FNOSC     = PRIPLL // Fast RC w PLL 8mHz internal rc Osc
#pragma config   FPLLIDIV  = DIV_4  // 2
#pragma config   FPLLMUL   = MUL_20 // 40
#pragma config   FPLLODIV  = DIV_4  // 10
#pragma config   FPBDIV    = DIV_1  // Peripheral Bus Divisor
#pragma config   FCKSM     = CSECME // Clock Switch Enable, FSCM Enabled
#pragma config   POSCMOD   = HS    // Primary osc disabled
#pragma config   IESO      = OFF    // Internal/external switch over
#pragma config   OSCIOFNC  = OFF    // CLKO Output Signal Active on the OSCO Pin
#pragma config   FWDTEN    = OFF    // Watchdog Timer Enable:
// ------------------------  Configuration (end) ----------------------------
// Function prototypes
void delay(int d); // This is the prototype declaration for the Delay function

int global_ctr = 0;                 // a global variable counter.
int global_delay_val = (16000);        // vary this to change the pulse's delay.


//init timer1


// Main function
int main(int argc, char** argv) {	
	TRISB = 0;				// Set all pins on PORT A to output
    ANSELB = 0x0000;
    int constant = 2000;	
    while(1) // Infinite Loop.  Keeps repeating.
    {   LATBCLR=0x0004;
        delay(global_delay_val);
        LATBSET=0x0004;
        delay(global_delay_val);
      /*  while(1){
      if ( TMR1 > constant){
      LATB=0x0004; }
      }       
        */     
    }

	return (EXIT_SUCCESS);
}


void delay(int d)
{
    int i;  // Declare variable to be used in the loop

    while(d)    // While d > 0
    {
        i = 100;    // set i to 100 for inner loop
        while(i)    // while i > 0
        {
            i--;    // decrement i (e.g. i will equal 99, 98, 97,...)
        }

        d--;    // decrement d
    }
}