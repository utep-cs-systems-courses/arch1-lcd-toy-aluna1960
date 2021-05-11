	.arch msp430g2533
	.text
jt:
	
	.word case0
	.word case1
	.word case2
	.word case3
	.word end
	
	.balign 2
	.extern bState
	.global _state_advance
	
	
_state_advance:
	
	mov &bState, r12
	cmp #0,r12
	jeq case0
	cmp #1,r12
	jeq case1
	cmp #2,r12
	jeq case2
	cmp #3,r12
	jeq case3
	jmp end
	

case0:
	
	
	call #borders
	mov #4,r12
	
	jmp end

case1:
	call #manFig
	mov #4,r12
	jmp end

case2:	
	call #clearBlack
	call #drawFace
	mov #4,r12
	jmp end
case3:
	call #off
	mov #4,r12
		
end:
	mov r12,bState
	pop r0



	
