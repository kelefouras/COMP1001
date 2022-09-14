; A simple example adding two numbers.
.386  ; Specify instruction set
.model flat, stdcall  ; Flat memory model, std. calling convention
.stack 4096 ; Reserve stack space
ExitProcess PROTO, dwExitCode: DWORD  ; Exit process prototype



.data ; data segment

; define your variables here

my_byte_array BYTE 1,2,3,4,5,6,7,8,9 ; this an array of bytes
my_dword_array DWORD 1,2,3,4,5,6,7,8,9 ;this is an array of DWORDS
my_var DWORD 99 ; this is DWORD variable

; WHAT IS THE SIZE OF THE ABOVE ARRAYS IN BYTES?

.code ; code segment


main PROC ; main procedure

; write your assembly code here

lea eax, my_byte_array ; store to eax the memory address of the array
lea ebx, my_dword_array ; store to eax the memory address of the array
lea ecx, my_var

    INVOKE ExitProcess, 0 ; call exit function

main ENDP ; exit main procedure
END main  ; stop assembling 
