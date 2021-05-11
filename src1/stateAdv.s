	.file	"stateAdv.c"
.text
	.local	switch_mask
	.comm	switch_mask,1,1
	.local	switches_last_reported
	.comm	switches_last_reported,1,1
	.local	switches_current
	.comm	switches_current,1,1
	.local	state
	.comm	state,1,1
	.balign 2
	.global	state_advance
	.type	state_advance, @function
state_advance:
; start of function
; framesize_regs:     0
; framesize_locals:   0
; framesize_outgoing: 0
; framesize:          0
; elim ap -> fp       2
; elim fp -> sp       0
; saved regs:(none)
	; start of prologue
	; end of prologue
	MOV.B	&bState, R12
	CMP.W	#1, R12 { JEQ	.L2
	MOV.B	#1, R13
	CMP.W	R12, R13 { JL	.L3
	CMP.W	#0, R12 { JEQ	.L4
	BR	#.L8
.L3:
	CMP.W	#2, R12 { JEQ	.L6
	CMP.W	#3, R12 { JEQ	.L7
	BR	#.L8
.L4:
	MOV.B	#0, R12
	CALL	#buzzer_set_period
	CALL	#borders
	MOV.B	#4, &bState
	BR	#.L5
.L2:
	CALL	#manFig
	MOV.B	#4, &bState
	BR	#.L5
.L6:
	CALL	#clearBlack
	CALL	#drawFace
	MOV.B	#4, &bState
.L7:
	MOV.B	#0, R12
	CALL	#buzzer_set_period
	CALL	#off
	MOV.B	#4, &bState
	BR	#.L8
.L5:
.L8:
	NOP
	; start of epilogue
	RET
	.size	state_advance, .-state_advance
	.ident	"GCC: (Mitto Systems Limited - msp430-gcc 8.2.0.52) 8.2.0"
