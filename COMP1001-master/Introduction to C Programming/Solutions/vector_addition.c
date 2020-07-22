

#include <stdio.h>

#define N 4

void initialize();
void print(int *);
void vec_add();
void print_using_pointers1();
void print_using_pointers2();

int A[N][N], B[N][N], C[N][N];

int main( ) {

int *ptr;

initialize();

ptr=&A[0][0];
printf("\narray A is:");
print(ptr); //print A

ptr=&B[0][0];
printf("\narray B is:");
print(ptr); //print B


vec_add();

ptr=&C[0][0];
printf("\narray C is:");
print(ptr);//print C

system("pause"); //this command does not let the output window to close
return 0; //normally, by returning zero, we mean that the program ended successfully. 
}



void initialize(){

int i,j,cnt=0;

for (i=0;i<N;i++)
 for (j=0;j<N;j++){
  A[i][j]=j%4;
  B[i][j]=i+j;
  C[i][j]=0;
}



}

void vec_add(){

int i,j;

for (i=0;i<N;i++)
 for (j=0;j<N;j++)
  *(*(C+j)+i) = *(*(A+j)+i) + *(*(B+j)+i);

}



void print(int *ptr){ //this function prints either A,B or C. 

int i,j;


for (i=0;i<N;i++){
printf("\n");
 for (j=0;j<N;j++){
 printf(" %d", *(ptr + i*N + j) ); // the '/n' takes the cursor to the next line, while the '%d' states that an integer will be printed
}
}
printf("\n");

}

void print_using_pointers1(){

int i,j;

printf("\n print_using_pointers1() is just called");

for (i=0;i<N;i++)
 for (j=0;j<N;j++)
  printf("\n element (%d,%d) equals to %d", i, j, *(*(C+i)+j) );

printf("\n print_using_pointers1() is just ended\n\n");

}


void print_using_pointers2(){

int i,j;
int *ptr; //this is a pointer to an integer. A pointer is a variable that stores a memory address.

ptr=&C[0][0]; // the '&' symbol stands for memory address of. Thus, 'ptr=&A[0][0]' means that the pointer shows to the memory address of A[0][0] 

printf("\n print_using_pointers2() is just called");

for (i=0;i<N;i++)
 for (j=0;j<N;j++)
 printf("\n element %d equals to %d",i, *(ptr + i*N + j) );

printf("\n print_using_pointers2() is just ended\n\n");

}


