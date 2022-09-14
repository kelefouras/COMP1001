; exercise 2.3.1
; A simple template for assembly programs.
.386  ; Specify instruction set
.model flat, stdcall  ; Flat memory model, std. calling convention
.stack 4096 ; Reserve stack space
ExitProcess PROTO, dwExitCode: DWORD  ; Exit process prototype

.data ; data segment
	; define your variables here
	sum DWORD 10000h	; 0x10000 is a hexadecimal number which requires
						; 17 bits. Therefore, we need 32 bit data type 
						; for holding its value. 
	 
	aVariable BYTE ?

.code ; code segment

main PROC ; main procedure
	; write your assembly code here

	INVOKE ExitProcess, 0 ; call exit function
  
main ENDP ; exit main procedure
END main  ; stop assembling
