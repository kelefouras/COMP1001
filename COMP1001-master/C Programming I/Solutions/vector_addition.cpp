/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/


#include <stdio.h>
#include <windows.h> //this library is needed for pause() function


void initialize();
void vec_add();
void print();

int A[10], B[10], C[10]; //three int arrays of size 10

int main( ) {

initialize();

vec_add();

print();

system("pause"); //this command does not let the output window to close
return 0; //normally, by returning zero, we mean that the program ended successfully. 
}



void initialize(){

int j;

 for (j=0;j<10;j++){
  A[j]=j%4;//this is the modulo operation (remainder of division with 4)
  B[j]=j;
  C[j]=0;
}



}

void vec_add(){

int j;

 for (j=0;j<10;j++)
  C[j]=A[j]+B[j];

}



void print(){ 

int j;


printf("\nA follows");
 for (j=0;j<10;j++){
 printf("   %d", A[j] ); // the '/n' takes the cursor to the next line, while the '%d' states that an integer will be printed
}

printf("\n"); //print a new line

printf("\nB follows");
 for (j=0;j<10;j++){
 printf("   %d", B[j] ); // the '/n' takes the cursor to the next line, while the '%d' states that an integer will be printed
}

printf("\n"); //print a new line


printf("\nC follows");
 for (j=0;j<10;j++){
 printf("   %d", C[j] ); // the '/n' takes the cursor to the next line, while the '%d' states that an integer will be printed
}

printf("\n"); //print a new line

}



