; A simple template for assembly programs.
.386  ; Specify instruction set
.model flat, stdcall  ; Flat memory model, std. calling convention
.stack 4096 ; Reserve stack space
ExitProcess PROTO, dwExitCode: DWORD  ; Exit process prototype

COMMENT!
Note. 
Here we need to rearrange the formula. This is because integer division 
in the current form would lead to wrong results. 
Rearranging the formula becomes:
(50xd + 50yc)/cd.
!
try to apply integer division in x/c and y/d, the result will be zero as 0<quotent<1. however, using the above formula 
this problem is eliminated as the quotent is percentage not 0<quotent<1

.data ; data segment
	; define your variables here
	cwMark DWORD 35 ; this is x
	cwTotal DWORD 60 ; this is c
	testMark DWORD 45 ; this is y
	testTotal DWORD 55 ; this is d
	pcw DWORD 50 ; this is coursework percentage contribution
	pt DWORD 50	; this is test pecentage contribution
	sumCw DWORD 0 ; variable to hold 50xd
	sumTest DWORD 0 ; varible to hold 50yc
	divisor DWORD 0 ; variable to hold cd
	quotient DWORD 0 ; division result
	remainder DWORD 0; division result
.code ; code segment

main PROC ; main procedure
	; write your assembly code here
	; compute 50xd
	mov eax, 50
	mov ecx, cwMark
	mul ecx ; product is in eax. we will ignore the higher part in edx as
			; the product is not going to be that big. The highest value of the
			; product can be 100^3 = 1000000, which requires 20 bits at most.
			; so 32 bit eax is sufficient to hold this value, and edx can be ignored.
	mov ecx, testTotal
	mul ecx 
	mov sumCw, eax	; save 50xd
	; compute 50yc
	mov eax, 50
	mov ecx, testMark
	mul ecx
	mov ecx, cwTotal
	mul ecx
	mov sumTest, eax ; save 50yc
	; compute divisor cd
	mov eax, cwTotal
	mov ecx, testTotal
	mul ecx
	mov divisor, eax
	; add
	mov eax, sumCw
	add eax, sumTest ; eax has the total sum
	; compute division
	mov edx, 0
	mov ecx, divisor
	div ecx
	mov quotient, eax
	mov remainder, edx

	INVOKE ExitProcess, 0 ; call exit function
  
main ENDP ; exit main procedure
END main  ; stop assembling