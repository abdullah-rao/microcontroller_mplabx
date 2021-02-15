
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
int global_delay_val = (20000);        // vary this to change the pulse's delay.
int main(int argc, char** argv) {
    TRISB = 0x0000;
   ANSELB = 0x0000;
    LATBCLR = 0xffff;
    T1CONCLR = 0x8000;
    T1CONSET = 0x0030;
    TMR1 = 0x00;
    PR1 = 0xffff;
    T1CONSET = 0x8000;
    const int constant = 40000; //was 40k
   while(1){
        if ( TMR1 > constant ){
        LATBINV = 0x004;
        TMR1= 0x00;
        }
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

