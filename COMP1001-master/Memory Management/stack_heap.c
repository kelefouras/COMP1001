/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/

#include <stdio.h> 
#include <stdlib.h> //this library allows for malloc to run
 
void init(int *ptr, int n){

        printf("\nMemory successfully allocated using malloc.\n"); 

        // initialize the array 
        for (int i = 0; i < n; ++i) { 
            ptr[i] = i; 
        } 
}


void print(int *ptr, int n){

        // Print the array 
        printf("\nThe elements of the array are: "); 
        for (int i = 0; i < n; ++i) { 
            printf("%d, ", ptr[i]); 
        } 
}
 


int main() 
{ 
  
    int* ptr;  // This pointer will hold the base address of the block created 
    int n=5;     //array size
   

    printf("\nThe number of elements is: %d\n", n); 
   
    ptr = (int*)malloc(n * sizeof(int)); // Dynamically allocate memory using malloc() 
  
   
    
    if (ptr == NULL) { // Check if the memory has been successfully allocated by malloc or not 
        printf("\nMemory not allocated.\n"); 
        exit(0); 
    } 

    else {  // Memory has been successfully allocated
  
        
  	init(ptr,n);

  
	print(ptr,n);

        // Free the memory 
        free(ptr); 
        printf("\n\nMalloc Memory successfully freed.\n"); 
    } 
  
    return 0; 
} 

