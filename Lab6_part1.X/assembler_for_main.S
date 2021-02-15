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
	addiu	t1,zero,45
	/*4c*/
	lw	s0,0(sp)
	addiu	sp,sp,4
	/*4d*/
	jr	ra
	nop
.end asmfunction