
// File: simple_asm.S
    #include <xc.h>

   /* define all global symbols here */
   .global main

   /* define which section (for example "text")
     * does this portion of code resides in. Typically,
     * all your code will reside in .text section as
     * shown below.
    */
   .text

   /* This is important for an assembly programmer. This
     * directive tells the assembler that don't optimize
     * the order of the instructions as well as don't insert
     * 'nop' instructions after jumps and branches.
    */
   .set noreorder

/*********************************************************************
 * main()
 * This is where the PIC32 start-up code will jump to after initial
 * set-up.  Works with Simulator + PIC32mx250128B for chipKIT dp32.
 ********************************************************************/

.ent main /* directive that marks symbol 'main' as function in ELF
           * output
           */
main:
	addi t0,$0,1;
	nop		/* "no operation"... replace this. */
	nop		/* "no operation"... replace this. */    
.end main /* directive that marks end of 'main' function and registers
           * size in ELF output
           */
