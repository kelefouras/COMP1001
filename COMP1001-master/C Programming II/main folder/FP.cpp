/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/

#include <stdio.h> //this library is needed for printf function
#include <stdlib.h> //this library is needed for rand() function
#include <windows.h> //this library is needed for pause() function
#include <omp.h> //this library is needed for the timer
#include <math.h> //this library is needed for abs()

void initialize();  //in C, functions must be declared before main()
unsigned short int equal(float a, float b); //in C, functions must be declared before main()
void MVM();
unsigned short int Compare_MVM();

#define EPSILON 1e-7 //relative error margin

#define N 10
#define TIMES_TO_RUN 1 //how many times the function will run

float A[N][N],Y[N],X[N],Test[N];

int main() {

	//define the timers measuring execution time
	double start_1, end_1; 


	initialize();

	
	start_1 = omp_get_wtime(); //start the timer 

	for (int i = 0; i < TIMES_TO_RUN; i++)//this loop is needed to get an accurate ex.time value
		MVM();

	end_1 = omp_get_wtime(); //end the timer 

	printf(" Time in seconds is %f\n", end_1 - start_1 );//print the ex.time

	if (Compare_MVM() == 0)
		printf("\n Results are correct\n");
	else 
		printf("\n Results are Incorrect\n");


	system("pause"); //this command does not let the output window to close

	return 0; //normally, by returning zero, we mean that the program ended successfully. 
}



void initialize() {

	float e = 0.1234f, p = 0.7264f, r = 0.11f;//the 'f' makes sure that these numbers are of type float and not double

	//MVM
	for (unsigned int i = 0; i != N; i++)
		for (unsigned int j = 0; j != N; j++)
			A[i][j] = ((i - j) % 9) + p;

	for (unsigned int j = 0; j != N; j++) {
		Y[j] = 0.0f;
		Test[j] = 0.0f;
		X[j] = (j % 7) + r;
	}
}

//
void MVM() {
	//MVM original code
	/*
		for (int i = 0; i < N; i++) {
		for (int j = 0; j <N; j++) {
			Y[i] += A[i][j] * X[j];
		}
	}
*/
	//MVM code with different order of executed instructions
	for (int i = 0; i < N; i++) {
		for (int j = N-1; j >= 0; j--) {//this loop is reversed
			Y[i] += A[i][j] * X[j];
		}
	}

}


unsigned short int Compare_MVM() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Test[i] += A[i][j] * X[j];
		}
	}

	for (int j = 0; j < N; j++)
		if (equal(Y[j], Test[j]) == 1) {//if not equal return 1
			return 1;
		}

	return 0;
}

//this function becomes problematic when b is zero or when both a and b are zero
unsigned short int equal(float a, float b) {
	float temp = a - b;

	if (fabs(temp/b) < EPSILON)
		return 0; //success
	else
		return 1; //wrong result
}


