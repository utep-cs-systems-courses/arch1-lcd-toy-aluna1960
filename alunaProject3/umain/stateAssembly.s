	.arch msp430g2553

	.p2alighn 1,0

JT:
	.word default
	.word case1
	.word case2
	.word case3
	.word case4

	.text
	.global state_advance

state_advance:
	cmp#5, &switch_state_changed
	jhs default
	mov &switch_state_changed,r12
	add r12,r12
	mov JT(r12),r0

case1:
	add #1, redrawScreen
	call #noise
	jmp end

case2:
	add #1, redrawScreen
	call #lightPattern
	jmp end
case3:
	add #1,redrawScreen
	call #reset

case4:
	add #1,redrawScreen
	call #clearScreen
	jmp end
default:
	jmp end

end:
	ret
