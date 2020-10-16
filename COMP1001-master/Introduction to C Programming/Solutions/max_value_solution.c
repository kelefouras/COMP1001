

#include <stdio.h> //this library is needed for printf function
#include <stdlib.h> //this library is needed for rand() function


#define N 10 //the compiler will copy paste 20 where N is. 

void initialize();  //in C, functions must be declared
void print();	//in C, functions must be declared
void print_using_pointers1();	//in C, functions must be declared
void print_using_pointers2();	//in C, functions must be declared
int find_max();	//in C, functions must be declared

int A[N]; //array is shared among all routines


int main( ) {

int max;

initialize();

print();
max=find_max();
printf("\nMAX value is %d\n",max);

system("pause"); //this command does not let the output window to close

return 0; //normally, by returning zero, we mean that the program ended successfully. 
}



void initialize(){

int i;

for (i=0;i<N;i++)
 A[i]=rand()%10; //the array's values range within 0-9. Why?

}


int find_max(){

int i, max;

max=A[0];//initialize the max with the value of the first element

for (i=1;i<N;i++){ 
 if (A[i]>max)  //compare max to all the elements with max starting from the 1st. 
   max=A[i];
}

return max;
}


void print(){

int i;

printf("\n print() is just called");

for (i=0;i<N;i++)
 printf("\n element %d equals to %d",i,A[i]); // the '/n' takes the cursor to the next line, while the '%d' states that an integer will be printed

printf("\n print() is just ended\n\n");

}

void print_using_pointers1(){

int i;

printf("\n print_using_pointers1() is just called");

for (i=0;i<N;i++)
 printf("\n element %d equals to %d",i, *(A+i) );

printf("\n print_using_pointers1() is just ended\n\n");

}


void print_using_pointers2(){

int i;
int *ptr; //this is a pointer to an integer. A pointer is a variable that stores a memory address.

ptr=&A[0]; // the '&' symbol stands for memory address of. Thus, 'ptr=&A[0]' means that the pointer shows to the memory address of A[0] 

printf("\n print_using_pointers2() is just called");

for (i=0;i<N;i++)
 printf("\n element %d equals to %d",i, *(ptr+i) );

printf("\n print_using_pointers2() is just ended\n\n");

}


