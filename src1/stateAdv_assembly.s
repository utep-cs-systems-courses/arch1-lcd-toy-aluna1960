	.arch msp430g2533
	.text
jt:
	.word case0
	.word case1
	.word case2
	.word case3
	
	
	.balign 2
	.global state_advance
	.global clearScreen
	.global drawChar11x16

drawChar11x16:
	push 40
	push 60
	push '$'
	push 0xffff
	push 0x001f
	
clearScreen:
	push COLOR_BLACK
	
state_advance:
	mov.b &bState,r12
	cmp #0,bState
	je case0
	cmp #1,bState
	je case1
	cmp #2,bState
	je case2
	cmp #3,bState
	je case3

case0:
	mov.b &bState,r12
	
	call #borders
	add #4,bState

case1:
	call #manFig
	add #3,bState

case2:	
	call #clearScreen
	call #drawChar11x16
	add #2,bState
case3:
	call #off
	add #1,bState
	



	
