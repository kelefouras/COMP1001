; A simple example adding two numbers.
.386  ; Specify instruction set
.model flat, stdcall  ; Flat memory model, std. calling convention
.stack 4096 ; Reserve stack space
ExitProcess PROTO, dwExitCode: DWORD  ; Exit process prototype

.data ; data segment
	; define your variables here
  sum DWORD 0  ; define a variable sum (32-bit) with initial value 0
  
.code ; code segment

main PROC ; main procedure
	; write your assembly code here
  mov eax, 25 ; move literal value 25 to eax
  mov ebx, 30 ; move literal value 30 to ebx
  add eax, ebx  ; add eax and ebx, and put value in eax
  mov sum, eax  ; move eax value to sum
	INVOKE ExitProcess, 0 ; call exit function
  
main ENDP ; exit main procedure
END main  ; stop assembling