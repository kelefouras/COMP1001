/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/


#include <stdio.h> //this library is needed for printf
#include <windows.h> //this library is needed for pause() function

//declare all the functions before main()
void initialize(); //this is a function that takes nothing as an input and returns nothing
void print_values(); //this is a function that takes nothing as an input and returns nothing
void print_addresses(); //this is a function that takes nothing as an input and returns nothing

int A[40]; //This array is defined before main() and thus it is visible by all the functions

int main( ) { //this is the main function


initialize(); //call a function that initializes the array

print_values();

print_addresses();

system("pause"); //this command does not let the output window to close


return 0; //normally, by returning zero, we mean that the program ended successfully. 
}




//this is a function
void initialize(){

int j;

 for (j=0;j<40;j++)
  A[j]=j;

}

// this is another function
void print_values(){

int j;

printf("\n print_values() is just called");

 for (j=0;j<40;j++)
 printf("\n A[%d] equals to %d", j, A[j]); // the '/n' takes the cursor to the next line, while the '%d' states that an integer will be printed

printf("\n print_values() is just ended\n\n");

}


// this is another function
void print_addresses(){
int j;

 for (j=0;j<40;j++)
  printf("\n The memory address of A[%d] is %p", j, &A[j]); 

}



