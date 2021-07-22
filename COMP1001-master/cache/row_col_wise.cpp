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

void row_wise();
void column_wise();

#define N 4000
#define TIMES_TO_RUN 1000 //how many times the function will run

int A[N][N];

int main() {

	//define the timers measuring execution time
	clock_t start_1, end_1; //ignore this for  now

	
	start_1 = clock(); //start the timer (THIS IS NOT A VERY ACCURATE TIMER) - ignore this for now

	for (int i = 0; i < TIMES_TO_RUN; i++)//this loop is needed to get an accurate ex.time value
		column_wise();
		//row_wise();

	end_1 = clock(); //end the timer - ignore this for now

	printf(" clock() method: %ldms\n", (end_1 - start_1) / (CLOCKS_PER_SEC / 1000));//print the ex.time


	system("pause"); //this command does not let the output window to close

	return 0; //normally, by returning zero, we mean that the program ended successfully. 
}



void row_wise() {

	float p = 0.7264f;//the 'f' makes sure that these numbers are of type float and not double

	for (unsigned int i = 0; i != N; i++)
		for (unsigned int j = 0; j != N; j++)
			A[i][j] = j;

}

void column_wise() {

	float p = 0.7264f;//the 'f' makes sure that these numbers are of type float and not double

	for (unsigned int i = 0; i != N; i++)
		for (unsigned int j = 0; j != N; j++)
			A[j][i] = j;

}

