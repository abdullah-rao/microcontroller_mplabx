#include <xc.h>

.text

.set noreorder




    .global asmfunction
.ent asmfunction
    asmfunction:
	/*4a*/
	addiu	sp,sp,-4
	sw	s0,0(sp)
	/*4b*/
	addiu	t1,zero,4 // load 4
	addiu	t2,zero,2 // load 2
	addiu	t3,zero,3 // load 3
	add	t4,t1,t2 // t4 <--4+2
	sub	t5,t4,t3 // t5 <-- t4-t3
	la	s0,glob_cVar
	sw	t5,0(s0)
	/*4c*/
	lw	s0,0(sp)
	addiu	sp,sp,4
	/*4d*/
	jr	ra
	nop
.end asmfunction