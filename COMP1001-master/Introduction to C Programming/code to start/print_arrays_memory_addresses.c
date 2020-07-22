

#include <stdio.h>

#define N 4

void initialize();
void print();
void print_using_pointers1();
void print_using_pointers2();
void print_addresses();

int A[N][N];

int main( ) {

initialize();

print();
print_using_pointers1();
print_using_pointers2();

print_addresses();

system("pause"); //this command does not let the output window to close


return 0; //normally, by returning zero, we mean that the program ended successfully. 
}


//We will discuss the difference between virtual memory and physical memory, in detail, later on.
void print_addresses(){
int i,j;

for (i=0;i<N;i++)
 for (j=0;j<N;j++)
  printf("\n The virtual memory address of A[%d,%d] is %p", i, j, &A[i][j]); 

}


void initialize(){

int i,j,cnt=0;

for (i=0;i<N;i++)
 for (j=0;j<N;j++)
  A[i][j]=cnt++;

}

void print(){

int i,j;

printf("\n print() is just called");

for (i=0;i<N;i++)
 for (j=0;j<N;j++)
 printf("\n element (%d,%d) equals to %d", i, j, A[i][j]); // the '/n' takes the cursor to the next line, while the '%d' states that an integer will be printed

printf("\n print() is just ended\n\n");

}

void print_using_pointers1(){

int i,j;

printf("\n print_using_pointers1() is just called");

for (i=0;i<N;i++)
 for (j=0;j<N;j++)
  printf("\n element (%d,%d) equals to %d", i, j, *(*(A+i)+j) );

printf("\n print_using_pointers1() is just ended\n\n");

}


void print_using_pointers2(){

int i,j;
int *ptr; //this is a pointer to an integer. A pointer is a variable that stores a memory address.

ptr=&A[0][0]; // the '&' symbol stands for memory address of. Thus, 'ptr=&A[0][0]' means that the pointer shows to the memory address of A[0][0] 

printf("\n print_using_pointers2() is just called");

for (i=0;i<N;i++)
 for (j=0;j<N;j++)
 printf("\n element %d equals to %d",i, *(ptr + i*N + j) );

printf("\n print_using_pointers2() is just ended\n\n");

}


