; A simple example adding two numbers.
.386  ; Specify instruction set
.model flat, stdcall  ; Flat memory model, std. calling convention
.stack 4096 ; Reserve stack space
ExitProcess PROTO, dwExitCode: DWORD  ; Exit process prototype



.data ; data segment

; define your variables here

  lower_sum DWORD 0  ; define a variable sum (32-bit) with initial value 0
  higher_sum DWORD 0  ; define a variable sum (32-bit) with initial value 0
  a DWORD 1001 ; multiplier 
  b DWORD 999 ; multiplicand 

 
.code ; code segment
 

main PROC ; main procedure

; write your assembly code here

  mov eax, a ; move multiplicand to eax
  mul b ; do a x b and put the result into edx:eax
  mov lower_sum, eax  ; move eax value to sum
  mov higher_sum, edx  ;

    INVOKE ExitProcess, 0 ; call exit function
 
main ENDP ; exit main procedure
END main  ; stop assembling



