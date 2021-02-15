#include <xc.h>

#pragma config FPLLIDIV = DIV_4 // 8/4=2
#pragma config FPLLMUL = MUL_20 //2*20=40M sysclk
#pragma config FPLLODIV = DIV_1 // 40M
#pragma config FNOSC = PRIPLL
#pragma config FSOSCEN = OFF
#pragma config POSCMOD = HS
#pragma config OSCIOFNC = OFF
#pragma config FPBDIV = DIV_2
#pragma config FCKSM = CSDCMD
#pragma config FWDTEN = OFF
#pragma config JTAGEN = OFF

extern void asmfunction(int myvariable);
volatile unsigned int glob_cVar=0;
main(){
  ANSELB = 0x0000;
  TRISB = 0xFF00;
  LATB = 0x00FF;
  // call the assembler file and shut off the same 8 bits
  
  
  int tempval=glob_cVar;
  asmfunction(0x0000);

  TRISB = 0x0000;
  ANSELB = 0x0000;
  LATBCLR = 0xFFFF;
    
  LATB = 0x0004;

  while(1){
    
      if (glob_cVar!=0){
             PORTBbits.RB2=1; // turn on all 8 bits in portb
      }
   
  
  }
}