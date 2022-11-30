/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/


#include <stdio.h>   //needed for printf
#include <stdlib.h> //needed for malloc, calloc, realloc, free
#include <windows.h>  
  
int main() 
{ 
  

    int* ptr; // This pointer will hold the memory address of the block to be created 
    int n; //initial array size 
    int i; 
  
    
    n = 5; // this is the array's size 
    printf("\nThe array size is: %d\n", n); 
  
    // Dynamically allocate memory using calloc() 
    ptr = (int*)calloc(n, sizeof(int)); 
  
    // Check if the memory has been successfully 
    // allocated by calloc or not 
    if (ptr == NULL) { 
        printf("\nMemory not allocated.\n"); 
        exit(0); 
    } 
    else { 
  
        // Memory has been successfully allocated 
        printf("\nMemory successfully allocated using calloc.\n"); 
  
        // initialize the array 
        for (i = 0; i < n; i++) { 
            ptr[i] = i; 
        } 
  
        // Print the elements of the array 
        printf("\nThe elements of the array are: "); 
        for (i = 0; i < n; i++) { 
            printf("%d, ", ptr[i]); 
        } 
  
        // Get the new size for the array 
        n = 10; 
        printf("\n\nThe new size of the array is: %d\n", n); 
  
        // Dynamically re-allocate memory using realloc() - re-allocation of memory maintains the already present value and new blocks will be initialized with default garbage value.
        ptr = (int*) realloc(ptr, n * sizeof(int)); 
        if (ptr == NULL) { 
        printf("\nMemory not allocated.\n"); 
        exit(0); 
        } 
  
        // Memory has been successfully allocated 
        printf("Memory successfully re-allocated using realloc.\n"); 
  

  
        // Print the elements of the array 
        printf("\nThe elements of the array are:"); 
        for (i = 0; i < n; ++i) { 
            printf("%d, ", ptr[i]); 
        } 
  
        free(ptr); 
	printf("\n");
    } 
  
system("pause");
 return 0; 
} 

