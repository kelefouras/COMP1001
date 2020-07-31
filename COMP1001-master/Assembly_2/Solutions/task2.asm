; A simple template for assembly programs.
.386  ; Specify instruction set
.model flat, stdcall  ; Flat memory model, std. calling convention
.stack 4096 ; Reserve stack space
ExitProcess PROTO, dwExitCode: DWORD  ; Exit process prototype

.data ; data segment
	; define your variables here
	array DWORD 5, 10, 15, 20 ; define array

.code ; code segment

main PROC ; main procedure
	; write your assembly code here
	lea ebx, array  ; load address of the first element
	mov ecx, 8  ; load multiplier
	mov eax, [ebx + TYPE array * 0] ; load multiplicand
	mul ecx ; multiply
	mov [ebx + TYPE array * 0], eax ; get the product and put it in the array
                                  ; (ignoring top bytes as they will be zero in this case)
  ; repeat the process for the rest of the elements.
  ; 2nd element
	mov eax, [ebx + TYPE array * 1]
	mul ecx
	mov [ebx + TYPE array * 1], eax
  ; 3rd element
	mov eax, [ebx + TYPE array * 2]
	mul ecx
	mov [ebx + TYPE array * 2], eax
  ; 4th element
	mov eax, [ebx + TYPE array * 3]
	mul ecx
	mov [ebx + TYPE array * 3], eax
	INVOKE ExitProcess, 0 ; call exit function
  
main ENDP ; exit main procedure
END main  ; stop assembling
