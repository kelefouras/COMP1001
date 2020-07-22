; A simple template for assembly programs.
.386  ; Specify instruction set
.model flat, stdcall  ; Flat memory model, std. calling convention
.stack 4096 ; Reserve stack space
ExitProcess PROTO, dwExitCode: DWORD  ; Exit process prototype

.data ; data segment
	; define your variables here
	string BYTE "This is very exciting.",0  ; remember strings are byte arrays
	frequency BYTE 0  ; this is the counter


.code ; code segment

main PROC ; main procedure
	; write your assembly code here
	lea ebx, string ; load address of the first element
	mov al, 69h ; this is ascii value of 'i' -- it is a byte and that is why it is stored here
	mov edx, LENGTHOF string  ; get the number of elements in the array
	mov esi, 0  ; this is the index for looping
update: ; label for looping
	mov ah, [ebx + TYPE string * esi] ; it is a BYTE array so values need to be stored in bytes
	cmp ah, al ; compare to see if it it 'i' or not
	je increment  ; if it is 'i' then jump to increment label
	jmp conditionTest ; otherwise carry on
conditionTest:  ; label for testing condition
	inc esi ; increment index 
	cmp esi, edx  ; compare if we have looked into all elements or not
	jne update  ; if not jump to the start of the loop
	jmp done  ; otherwise finish the program
increment:
	inc frequency
	jmp conditionTest
done:
	INVOKE ExitProcess, 0 ; call exit function
  
main ENDP ; exit main procedure
END main  ; stop assembling