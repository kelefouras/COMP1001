; A simple template for assembly programs.
.386  ; Specify instruction set
.model flat, stdcall  ; Flat memory model, std. calling convention
.stack 4096 ; Reserve stack space
ExitProcess PROTO, dwExitCode: DWORD  ; Exit process prototype

.data ; data segment
	
	aVariable DWORD ? ; Declare variable to store answer.

.code ; code segment

main PROC ; main procedure
	
	MOV eax, 1 ; Move 1 into eax register.
	MOV ebx, 2 ; Move 2 into ebx register.
	MOV ecx, 3 ; Move 3 into ecx register.
	MOV edx, 4 ; Move 4 into edx register.

	ADD eax, ebx ; Add together eax and ebx - stored in eax
	ADD ecx, edx ; Add together ecx and edx - stored in exc.

	SUB eax, ecx ; Subtract eax and ecx (sums)

	MOV aVariable, eax ; Move answer (eax value) into variable.

	INVOKE ExitProcess, 0 ; call exit function

	; IMPORTANT
	; The resulting answer will be -4.
	; This means that the signed integer will be produced in two's complement.
	; This is why the value stored in eax will be FFFFFFC.
  
main ENDP ; exit main procedure
END main  ; stop assembling
