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
#include <pmmintrin.h> //this library is needed for SSE
//#include <process.h>
//#include <chrono>
//#include <iostream>
#include <immintrin.h> //this library is needed for AVX

void init();
void AVX();


#define N 256 //input size
__declspec(align(64)) float A[N][N], B[N][N],Btranspose[N][N],C[N][N],test[N][N];

#define TIMES_TO_RUN 1 //how many times the function will run
#define EPSILON 0.0001

int main() {

	//define the timers measuring execution time
	clock_t start_1, end_1; //ignore this for  now

	init();

	start_1 = clock(); //start the timer 

	for (int i = 0; i < TIMES_TO_RUN; i++)//this loop is needed to get an accurate ex.time value
		AVX();
		

	end_1 = clock(); //end the timer 

	printf(" clock() method: %ldms\n", (end_1 - start_1) / (CLOCKS_PER_SEC / 1000));//print the ex.time


	system("pause"); //this command does not let the output window to close

	return 0; //normally, by returning zero, we mean that the program ended successfully. 
}

void init() {

	float e = 0.1234f, p = 0.7264f, r = 0.11f;

	//MMM
	for (unsigned int i = 0; i < N; i++) { //printf("\n");
		for (unsigned int j = 0; j < N; j++) {
			C[i][j] = 0.0f;
			test[i][j] = 0.0f;
			A[i][j] = (j % 9) + p; //printf(" %3.1f",A[i][j]);
			B[i][j] = (j % 7) - p; //printf(" %3.1f",B[i][j]);
		}
	}


}





void AVX() {
	__m256 ymm0, ymm1, ymm2, ymm3, ymm4, ymm5, ymm6, ymm7, ymm8, ymm9, ymm10, ymm11, ymm12, ymm13, ymm14, ymm15;
	__m128 xmm1, xmm2;
	int i, j, k;
	float temp;


	for (j = 0; j < N; j++)
		for (k = 0; k < N; k++) {
			Btranspose[k][j] = B[j][k];
		}

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			ymm0 = _mm256_setzero_ps();
			for (k = 0; k < N; k += 8) {
				ymm1 = _mm256_load_ps(&A[i][k]);
				ymm2 = _mm256_load_ps(&Btranspose[j][k]);
				ymm0 = _mm256_fmadd_ps(ymm1, ymm2, ymm0);
			}

			ymm2 = _mm256_permute2f128_ps(ymm0, ymm0, 1);
			ymm0 = _mm256_add_ps(ymm0, ymm2);
			ymm0 = _mm256_hadd_ps(ymm0, ymm0);
			ymm0 = _mm256_hadd_ps(ymm0, ymm0);
			xmm2 = _mm256_extractf128_ps(ymm0, 0);
			_mm_store_ss(&C[i][j], xmm2);

		}

}

