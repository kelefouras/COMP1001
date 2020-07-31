/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/

#include <stdio.h> 
#include <stdlib.h> //this library allows for malloc to run
 
 
int main() 
{ 
  
    int* ptr;  // This pointer will hold the base address of the block created 
    int* ptr1;  // This pointer will hold the base address of the block created 
    int n;     //array size
    int i;
  
     
    n = 5;  // Get the number of elements for the array

    printf("\nThe number of elements is: %d\n", n); 
   
    ptr = (int*)malloc(n * sizeof(int)); // Dynamically allocate memory using malloc() 
    if (ptr == NULL) { // Check if the memory has been successfully allocated by malloc or not 
        printf("\nMemory not allocated.\n"); 
        exit(0); 
    } 
  
    ptr1 = (int*)calloc(n, sizeof(int));  // Dynamically allocate memory using calloc() - CALLOC INITIALIZES WITH ZERO
    if (ptr1 == NULL) { // Check if the memory has been successfully allocated by calloc or not 
        printf("\nMemory not allocated.\n"); 
        exit(0); 
    } 
    

         
        printf("\nMemory successfully allocated using malloc and calloc.\n"); 
  
        // Print the array - malloc does not initialize the array. Its values are trush. Sometimes, it happens to be zero, but this is not the case. 
        printf("\nThe elements of ptr are: "); 
        for (i = 0; i < n; ++i) { 
            printf("%d, ", ptr[i]); 
        } 

        // Print the array 
        printf("\nThe elements of ptr1 are: "); 
        for (i = 0; i < n; ++i) { 
            printf("%d, ", ptr1[i]); 
        } 

        // Free the memory 
        free(ptr); 
        printf("\n\nMalloc Memory successfully freed.\n"); 

        // Free the memory 
        free(ptr1); 
        printf("\n\nCalloc Memory successfully freed.\n"); 
    
  
    return 0; 
} 





