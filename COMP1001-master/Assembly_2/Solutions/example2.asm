; A simple template for assembly programs.
.386  ; Specify instruction set
.model flat, stdcall  ; Flat memory model, std. calling convention
.stack 4096 ; Reserve stack space
ExitProcess PROTO, dwExitCode: DWORD  ; Exit process prototype

.data ; data segment
	; define your variables here
	power WORD 2200
	volt WORD 220
	zero WORD 0
	quotient WORD 0
	remainder WORD 0

.code ; code segment
	
main PROC ; main procedure
	; write your assembly code here
	mov dx, zero
	mov ax, power
	mov cx, volt
	div cx
	mov quotient, ax
	mov remainder, dx

	INVOKE ExitProcess, 0 ; call exit function
  
main ENDP ; exit main procedure
END main  ; stop assembling