

#include <stdio.h> //this library is needed for printf function
#include <stdlib.h> //this library is needed for rand() function
#include <windows.h> //this library is needed for pause() function

#define N 10 

void initialize();  //in C, functions must be declared before main()
void print();	//in C, functions must be declared
int find_max();	//in C, functions must be declared
int find_min();	//in C, functions must be declared

int A[N]; 

int main( ) {

int max,min;

initialize();

print();
max=find_max();
min=find_min();
printf("\nMAX value is %d, while MIN value is %d\n",max,min);

system("pause"); //this command does not let the output window to close

return 0; //normally, by returning zero, we mean that the program ended successfully. 
}



void initialize(){

int i;

for (i=0;i<N;i++)
 A[i]=rand()%20; //rand() is a function that generates random numbers. The array's values range within 0-19. Why?

}


int find_max(){//this function returns an int

int i, max;

max=A[0];//initialize the max with the value of the first element

for (i=1;i<N;i++){ 
 if (A[i]>max)  //compare max to all the elements with max starting from the 1st. 
   max=A[i];
}

return max;
}


int find_min(){//this function returns an int

int i, min;

min=A[0];//initialize the min with the value of the first element

for (i=1;i<N;i++){ 
 if (A[i]<min)  //compare max to all the elements with max starting from the 1st. 
   min=A[i];
}

return min;
}


void print(){

int i;

printf("\n print() is just called");

for (i=0;i<N;i++)
 printf("\n element %d equals to %d",i,A[i]); // the '/n' takes the cursor to the next line, while the '%d' states that an integer will be printed

printf("\n print() is just ended\n\n");

}


