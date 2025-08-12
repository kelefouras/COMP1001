/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/


#include <stdio.h> //this library is needed for printf function
#include <stdlib.h> //this library is needed for rand() function
#include <windows.h> //this library is needed for pause() function
#include <time.h> //this library is needed for clock() function
#include <math.h> //this library is needed for abs()
#include <omp.h> //this library is needed for the timer

unsigned short int equal(float a, float b); //in C, functions must be declared before main()
void init();
void q1();
void q2();
void q3();


#define N 256 //input size
#define EPSILON 1e-6 //relative error margin

float A[N][N], u1[N], u2[N], v1[N], v2[N], x[N], y[N], w[N], z[N] ;
float alpha=0.23, beta=0.45;	


int main() {

	double start_1, end_1; //define the timers measuring execution time

	init();//initialize the arrays

	//start_1 = omp_get_wtime(); //start the timer 
	 
	q1(); 
	q2();
	q3();
		
	//end_1 = omp_get_wtime(); //end the timer 

	//printf(" Time in seconds is %f\n", end_1 - start_1 );//print the ex.time
	
	system("pause"); //this command does not let the output window to close
	
	return 0; //normally, by returning zero, we mean that the program ended successfully. 
}


void init() {

int i,j;

        for (i=0;i<N;i++)
        for (j=0;j<N;j++){
            A[i][j]= 0.0f;

        }

        for (i=0;i<N;i++){
            u1[i]=(i%9)*0.22f;
            u2[i]=(i%9)*0.33f;
            v1[i]=(i%9)*0.44f;
            v2[i]=(i%9)*0.55f;
            w[i]=0.0f;
        }
        
}



void q1() {

   for (int i = 0; i < N; i++) { 
       w[i] = beta * u1[i] + alpha; 

   } 
	

}


void q2(){

int i,j;

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      A[i][j] = u1[i] * v1[j] - u2[i] * v2[j];

}


void q3(){

int i,j;

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      w[i] +=  beta * A[i][j] * u1[j];

}


//this function becomes problematic when b is zero or when both a and b are zero
unsigned short int equal(float a, float b) {
	float temp = a - b;

	if (fabs(temp/b) < EPSILON)
		return 0; //success
	else
		return 1; //wrong result
}



