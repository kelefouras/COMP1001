; A simple template for assembly programs.
.386  ; Specify instruction set
.model flat, stdcall  ; Flat memory model, std. calling convention
.stack 4096 ; Reserve stack space
ExitProcess PROTO, dwExitCode: DWORD  ; Exit process prototype

.data ; data segment
	; define your variables here
	array DWORD 4, 3, 5, 6

.code ; code segment

main PROC ; main procedure
	; write your assembly code here
	lea ebx, array  ; move the address of the first element in ebx
	mov ecx, [ebx + TYPE array * 1] ; get the value stored at the 2nd element: ecx = 3 
	mov edx, 10h ; store 10h in edx
	mov [ebx + TYPE array * 1], edx ; put 10h into the second element of the array
	INVOKE ExitProcess, 0 ; call exit function
  
main ENDP ; exit main procedure
END main  ; stop assembling