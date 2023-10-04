; A simple template for assembly programs.
.386  ; Specify instruction set
.model flat, stdcall  ; Flat memory model, std. calling convention
.stack 4096 ; Reserve stack space
ExitProcess PROTO, dwExitCode: DWORD  ; Exit process prototype

.data ; data segment
	
	sum DWORD 10000h ; Initialise sum as hex value 0x10000 (32 bit)

	aVariable BYTE ? ; Declare unitialised aVariable (8 bit).

.code ; code segment

main PROC ; main procedure
	; write your assembly code here

	MOV EAX, sum ; Load the sum hex value into the register.

	INVOKE ExitProcess, 0 ; call exit function
  
main ENDP ; exit main procedure
END main  ; stop assembling