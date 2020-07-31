.386					; Specify instruction set

.MODEL FLAT, stdcall			; Flat memory model, std calling convention

.STACK 4096				; Reserve stack space

ExitProcess PROTO, dwExitCode:DWORD	; Exit process prototype

.DATA
outString BYTE "The answer is: ",0 	; Output string
answer DWORD ?			 	; Reserve 1 DWORD for the solution


.CODE

_main PROC		; _main procedure

mov eax, 1 		; Value for A stored in eax
mov ebx, 2 		; Value for B stored in ebx
mov ecx, 3 		; Value for C stored in ecx
mov edx, 4 		; Value for D stored in edx

add eax, ebx 		; Add 1 + 2 and store in eax
add ecx, edx 		; Add 3 + 4 and store in ecx

sub eax, ecx 		; Subtract ecx from eax and store in eax

mov answer, eax 	; Move value from eax into variable

INVOKE ExitProcess, 0	; Call exit function

_main ENDP		; End of the main procedure

END			; Stop assembling
