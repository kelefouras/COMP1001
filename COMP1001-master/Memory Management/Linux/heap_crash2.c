/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/

//compile with gcc heap_crash2.c -o p
//run with ./exec

#include<stdio.h> 
#include <stdlib.h> //for malloc
  
#define N 4000000000

void heap_crash();

int main() 
{ 

printf("\nHi before crashing the heap\n");

heap_crash();    

printf("\nIt looks like the head did not crash. Put an extra zero in N\n");

return 0;
} 

void heap_crash(){


    int *ptr = (int *)malloc(sizeof(int)*N);  //try to allocate N*4 bytes of memory
    if (ptr == NULL) { // Check if the memory has been successfully allocated by malloc or not 
        printf("\nMemory not allocated.\n"); 
        exit(0); 
    } 


}

