; A simple template for assembly programs.
.386  ; Specify instruction set
.model flat, stdcall  ; Flat memory model, std. calling convention
.stack 4096 ; Reserve stack space
ExitProcess PROTO, dwExitCode: DWORD  ; Exit process prototype

.data ; data segment
	; define your variables here
	array DWORD 5, 10, 15, 20


.code ; code segment

main PROC ; main procedure
	; write your assembly code here
	lea ebx, array  ; load address of the first element
	mov ecx, 8  ; store the multiplier
	mov esi, 0  ; this is for index
update: ; a label for looping
	mov eax, [ebx + TYPE array * esi] ; access index as in esi
	mul ecx ; multiply
	mov [ebx + TYPE array * esi], eax ; rewrite with the latest product value
	inc esi ; increment esi to go to next index
	cmp esi, 4  ; compare to see if we have looked into all indices or not
	jne update  ; if not, go to the start of the loop
	INVOKE ExitProcess, 0 ; otherwise call exit function
  
main ENDP ; exit main procedure
END main  ; stop assembling