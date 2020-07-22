#include<stdio.h> 
#include <stdlib.h> //for malloc
  
#define N 4000000000

void heap_crash();

int main() 
{ 

printf("\nHi before crashing the heap\n");

heap_crash();    

printf("\nIt looks like the head did not crash\n");

return 0;
} 

void heap_crash(){


    int *ptr = (int *)malloc(sizeof(int)*N);  //try allocate this amount of memory
    if (ptr == NULL) { // Check if the memory has been successfully allocated by malloc or not 
        printf("\nMemory not allocated.\n"); 
        exit(0); 
    } 


}

