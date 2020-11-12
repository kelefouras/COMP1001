#include "array_addition.h"

float  X1[M2], X2[M2], Y1[M2], test2[M2];

void initialization_Add() {

	float e = 0.1234f, p = 0.7264f, r = 0.11f;

	for (unsigned int j = 0; j != M2; j++) {
		Y1[j] = 0.0f;
		test2[j] = 0.0f;
		X1[j] = (j % 7) + r;
		X2[j] = (j % 13) + e;
	}
}


unsigned short int Add_default() {

	for (int j = 0; j < M2; j++) {
		Y1[j] = X1[j] + X2[j];
	}


	return 0;
}

unsigned short int Add_SSE() {

	__m128 num1, num2, num3;

	for (int i = 0; i < M2; i += 4) { //IMPORTANT: M MUST BE A MULTIPLE OF 4, OTHERWISE IT DOES NOT WORK
		num1 = _mm_loadu_ps(&X1[i]); //load 4 elements of X1[]
		num2 = _mm_loadu_ps(&X2[i]); //load 4 elements of X2[]
		num3 = _mm_add_ps(num1, num2); //num3 = num1 + num2
		_mm_storeu_ps(&Y1[i], num3); //store num3 to Y[i]. num3 has 4 FP values which they are stored into Y[i], Y[i+1], Y[i+2], Y[i+3], respectively
	}


	return 0;
}


unsigned short int Add_SSE_all_sizes() {

	__m128 num1, num2, num3;
int i;

	for (i = 0; i < (M2/4)*4; i += 4) { //e.g., if M2==10, then ((10/4)*4)=8 as the division is between integers
		num1 = _mm_loadu_ps(&X1[i]); //load 4 elements of X1[]
		num2 = _mm_loadu_ps(&X2[i]); //load 4 elements of X2[]
		num3 = _mm_add_ps(num1, num2); //num3 = num1 + num2
		_mm_storeu_ps(&Y1[i], num3); //store num3 to Y[i]. num3 has 4 elements which they are stored into Y[i], Y[i+1], Y[i+2], Y[i+3], respectively
	}

	//padding code
	for (i= ((M2/4)*4); i < M2; i++) { //equivalently you could write 'for ( ; i < M2; i++)'
	  Y1[i] = X1[i] + X2[i];
	}


	return 0;
}

unsigned short int Add_AVX() {

	__m256  ymm1, ymm2, ymm3;

	for (int i = 0; i < M2; i += 8) { //IMPORTANT: M MUST BE A MULTIPLE OF 8, OTHERWISE IT DOES NOT WORK
		ymm1 = _mm256_loadu_ps(&X1[i]); //load 8 elements of X1[]
		ymm2 = _mm256_loadu_ps(&X2[i]); //load 8 elements of X2[]
		ymm3 = _mm256_add_ps(ymm1, ymm2); //ymm3 = ymmm1 + ymm2
		_mm256_storeu_ps(&Y1[i], ymm3); //store ymm3 to Y. ymm3 has 8 elements which they are stored into Y[i], Y[i+1], Y[i+2], Y[i+3], .. Y[i+7]
	}


	return 0;
}


unsigned short int Add_AVX_all_sizes() {

	__m256  ymm1, ymm2, ymm3;
int i;
	for (i = 0; i < (M2/8)*8; i += 8) { //e.g., if M2==10, then ((10/8)*8)=8 as the division is between integers
		ymm1 = _mm256_loadu_ps(&X1[i]); //load 8 elements of X1[]
		ymm2 = _mm256_loadu_ps(&X2[i]); //load 8 elements of X2[]
		ymm3 = _mm256_add_ps(ymm1, ymm2); //num3 = num1 + num2
		_mm256_storeu_ps(&Y1[i], ymm3); //store ymm3 to Y. ymm3 has 8 elements which they are stored into Y[i], Y[i+1], Y[i+2], Y[i+3], .. Y[i+7]
	}

	//padding code
	for (i=(M2/8)*8; i < M2; i++) { //equivalently you could write 'for ( ; i < M2; i++)'
	  Y1[i] = X1[i] + X2[i];
	}


	return 0;
}



unsigned short int Compare_Add() {


	for (int j = 0; j < M2; j++) {
		test2[j] = X1[j] + X2[j];
	}


	for (int j = 0; j < M2; j++)
		if (equal(Y1[j], test2[j]) == 1) {
			//printf("\n j=%d\n", j);
			return 1;
		}

	return 0;
}



