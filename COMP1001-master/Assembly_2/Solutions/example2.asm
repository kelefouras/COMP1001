; A simple template for assembly programs.
.386  ; Specify instruction set
.model flat, stdcall  ; Flat memory model, std. calling convention
.stack 4096 ; Reserve stack space
ExitProcess PROTO, dwExitCode: DWORD  ; Exit process prototype

.data ; data segment
	; define your variables here
	power DWORD 2200
	volt DWORD 220
	zero DWORD 0
	quotient DWORD 0
	remainder DWORD 0

.code ; code segment
	
main PROC ; main procedure
	; write your assembly code here
	mov edx, zero
	mov eax, power
	mov ecx, volt
	div ecx
	mov quotient, eax
	mov remainder, edx

	INVOKE ExitProcess, 0 ; call exit function
  
main ENDP ; exit main procedure
END main  ; stop assembling
