/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/

/*
if you are running this on Visual Studio, no action is needed.
if you are running this on Linux, comment lines #15 and #48
*/

#include <stdio.h> //this library is needed for printf function
#include <stdlib.h> //this library is needed for rand() function
#include <windows.h> //this library is needed for pause() function
#include <time.h> //this library is needed for clock() function
#include <math.h> //this library is needed for abs()


void init();
void q1();


#define N 256 //input size
float Y[N], X[N],A[N*N],test[N];

#define TIMES_TO_RUN 1 //how many times the function will run. If the ex.time you get is lower than 2 seconds, then increase this value accordingly

int main() {

	//define the timers measuring execution time
	clock_t start_1, end_1; //ignore this for  now

	init();//initialize the arrays

	start_1 = clock(); //start the timer 

	for (int i = 0; i < TIMES_TO_RUN; i++)//this loop is needed to get an accurate ex.time value
		q1();
		

	end_1 = clock(); //end the timer 

	printf(" clock() method: %ldms\n", (end_1 - start_1) / (CLOCKS_PER_SEC / 1000));//print the ex.time

	printf("\n The value of the 5th element is %f \n",Y[4]);
		
	system("pause"); //this command does not let the output window to close

	return 0; //normally, by returning zero, we mean that the program ended successfully. 
}


void init() {

	float e = 0.1234f, p = 0.7264f, r = 0.11f;//if you do not specify the 'f' after 0.0, then double precision data type is assumed (not float which single precision). 

	//MVM
	for (unsigned int i = 0; i < N; i++)
		for (unsigned int j = 0; j < N; j++)
			A[N*i+j] = ((i - j) % 9) + p;

	for (unsigned int j = 0; j < N; j++) {
		Y[j] = 0.0f; 
		test[j] = 0.0f;
		X[j] = (j % 7) + r;
	}
}



void q1() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Y[i] += A[N*i+j] * X[j];
		}
	}
	

}
