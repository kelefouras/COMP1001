#include<stdio.h> 
#include <stdlib.h> //for malloc
  
#define N 1000000000

void heap_crash();

int main() 
{ 

printf("\nHi before crashing the heap\n");

heap_crash();    

printf("\nIt looks like the head did not crash\n");

return 0;
} 

void heap_crash(){

int i;

for ( i=0; i<N; i++) 
    {     
       int *ptr = (int *)malloc(sizeof(int));  // Allocating memory without freeing it 
    } 

}

