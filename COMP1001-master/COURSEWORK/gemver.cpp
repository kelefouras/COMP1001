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
#include <pmmintrin.h>
#include <process.h>
//#include <chrono>
#include <iostream>
#include <immintrin.h>

void initialization();
unsigned short int gemver_default();
unsigned short int gemver_vectorized();
unsigned short int Compare_Gemver();
inline unsigned short int equal(float const a, float const b);

#define P 4096 //input size
__declspec(align(64)) float A2[P][P], test4[P][P], u1[P], v1[P], u2[P], v2[P];

#define TIMES_TO_RUN 1 //how many times the function will run
#define EPSILON 0.0001

int main() {

	//define the timers measuring execution time
	clock_t start_1, end_1; //ignore this for  now

	initialization();

	start_1 = clock(); //start the timer 

	for (int i = 0; i < TIMES_TO_RUN; i++)//this loop is needed to get an accurate ex.time value
		gemver_default();
		

	end_1 = clock(); //end the timer 

	printf(" clock() method: %ldms\n", (end_1 - start_1) / (CLOCKS_PER_SEC / 1000));//print the ex.time

	if (Compare_Gemver() == 0)
		printf("\nCorrect Result\n");
	else 
		printf("\nINcorrect Result\n");

	system("pause"); //this command does not let the output window to close

	return 0; //normally, by returning zero, we mean that the program ended successfully. 
}



void initialization() {

	float e = 0.1234f, p = 0.7264f, r = 0.11f;

	//gemver
	for (int i = 0; i < P; i++)
		for (int j = 0; j < P; j++) {
			A2[i][j] = 0.0f;
			test4[i][j] = 0.0f;
		}

	for (int j = 0; j < P; j++) {
		u1[j] = e + (j % 9);
		v1[j] = e - (j % 9) + 1.1f;
		u2[j] = p + (j % 9) - 1.2f;
		v2[j] = p - (j % 9) + 2.2f;
	}


}



unsigned short int gemver_default() {

	for (int i = 0; i < P; i++)
		for (int j = 0; j < P; j++)
			A2[i][j] += u1[i] * v1[j] + u2[i] * v2[j];

	return 0;
}



unsigned short int Compare_Gemver() {

	for (int i = 0; i < P; i++)
		for (int j = 0; j < P; j++)
			test4[i][j] += u1[i] * v1[j] + u2[i] * v2[j];

	for (int i = 0; i < P; i++)
		for (int j = 0; j < P; j++)
			if (equal(test4[i][j], A2[i][j]) == 1)
				return -1;

	return 0;
}






unsigned short int equal(float const a, float const b) {
	
	if (fabs(a-b)/fabs(a) < EPSILON)
		return 0; //success
	else
		return 1;
}



