; A simple example adding two numbers.
.386  ; Specify instruction set
.model flat, stdcall  ; Flat memory model, std. calling convention
.stack 4096 ; Reserve stack space
ExitProcess PROTO, dwExitCode: DWORD  ; Exit process prototype

.data ; data segment
	; define your variables here
answer SDWORD ?; Reserve 32 bits for the output. The output can be negative, thus a signed data type is needed.


.code ; code segment

main PROC ; main procedure
	; write your assembly code here

mov eax, 10 		; Value for A stored in eax
mov ebx, 2 		; Value for B stored in ebx
mov ecx, 3 		; Value for C stored in ecx
mov edx, 4 		; Value for D stored in edx

add eax, ebx 		; Add 10 + 2 and store in eax
add ecx, edx 		; Add 3 + 4 and store in ecx

sub eax, ecx 		; Subtract ecx from eax and store in eax

mov answer, eax 	; Move value from eax into variable

	INVOKE ExitProcess, 0 ; call exit function
  
main ENDP ; exit main procedure
END main  ; stop assembling



; In VS, under the registers tab you can see the following flag registers:
; Overflow flag(OV): Set to 1, when given instruction is for e.g of 32bit and resultant value is of 33bit.
; Sign(PL): Set to 1, when negative result
; Zero(ZR): set to 1, if result is zero 
