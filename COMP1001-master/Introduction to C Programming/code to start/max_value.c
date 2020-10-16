

#include <stdio.h> //this library is needed for printf function
#include <stdlib.h> //this library is needed for rand() function


#define N 10 //the compiler will copy paste 20 where N is. 

void initialize();  //in C, functions must be declared
void print();	//in C, functions must be declared
int find_max();	//in C, functions must be declared

int A[N]; //array is shared among all routines


int main( ) {

int max;

initialize();

print();

//WRITE HERE YOUR ROUTINE
//max=find_max();

printf("\nMAX value is %d\n",max);

system("pause"); //this command does not let the output window to close

return 0; //normally, by returning zero, we mean that the program ended successfully. 
}



void initialize(){

int i;

for (i=0;i<N;i++)
 A[i]=rand()%10; //the array's values range within 0-9. Why?

}




void print(){

int i;

printf("\n print() is just called");

for (i=0;i<N;i++)
 printf("\n element %d equals to %d",i,A[i]); // the '/n' takes the cursor to the next line, while the '%d' states that an integer will be printed

printf("\n print() is just ended\n\n");

}




