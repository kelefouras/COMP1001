/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/



#include<stdio.h> 
#include <stdlib.h> //for malloc
#include <windows.h>  
  
#define N 1000000000

void heap_crash();

int main() 
{ 

printf("\nHi before crashing the heap\n");

heap_crash();    

printf("\nIt looks like the heap did not crash\n");

system("pause");
return 0;
} 

void heap_crash(){

int i;

for ( i=0; i<N; i++) // do the following for N times
    {     
       int *ptr = (int *)malloc(sizeof(int));  // Allocate 4 bytes of memory without freeing it 
    } 

}

