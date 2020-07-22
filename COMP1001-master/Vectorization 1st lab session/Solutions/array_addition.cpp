#include "array_addition.h"

void initialization_Add() {

	float e = 0.1234, p = 0.7264, r = 0.11;


	for (unsigned int j = 0; j != M; j++) {
		Y1[j] = 0.0;
		test2[j] = 0.0;
		X1[j] = (j % 7) + r;
		X2[j] = (j % 13) + e;
	}
}


unsigned short int Add_default() {

		for (int j = 0; j < M; j++) {
			Y1[j] = X1[j] + X2[j];
		}
	

	return 0;
}

unsigned short int Add_SSE() {

	__m128 num0, num1, num2, num3, num4, num5, num6;

	for (int i = 0; i < M; i+=4) { //IMPORTANT: M MUST BE A MULTIPLE OF 4, OTHERWISE IT DOES NOT WORK
		num1 = _mm_load_ps(&X1[i]); //load 4 elements of X1[]
		num2 = _mm_load_ps(&X2[i]); //load 4 elements of X2[]
		num3 = _mm_add_ps(num1, num2); //num3 = num1 + num2
		_mm_store_ps(&Y1[i], num3); //store num3 to Y[i]. num3 has 4 FP values which they are stored into Y[i], Y[i+1], Y[i+2], Y[i+3], respectively
	}

		
	return 0;
}


unsigned short int Add_AVX() {

	__m256  ymm0, ymm1, ymm2, ymm3, ymm4;

		for (int i = 0; i < M; i += 8) { //IMPORTANT: M MUST BE A MULTIPLE OF 8, OTHERWISE IT DOES NOT WORK
			ymm1 = _mm256_load_ps(&X1[i]); //load 8 elements of X1[]
			ymm2 = _mm256_load_ps(&X2[i]); //load 8 elements of X2[]
			ymm3 = _mm256_add_ps(ymm1, ymm2); //num3 = num1 + num2
			_mm256_store_ps(&Y1[i], ymm3); //store num3 to Y[i]. num3 has 8 FP values which they are stored into Y[i], Y[i+1], Y[i+2], Y[i+3], .. Y[i+7]
		}


	return 0;
}


unsigned short int Compare_Add() {


		for (int j = 0; j < M; j++) {
			test2[j] = X1[j] + X2[j];
		}
	

	for (int j = 0; j < M; j++)
		if (equal(Y1[j], test2[j]) == 1) {
			//printf("\n j=%d\n", j);
			return 1;
		}

	return 0;
}



