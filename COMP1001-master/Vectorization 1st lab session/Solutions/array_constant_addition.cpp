#include "array_constant_addition.h"

void initialization_ConstAdd() {

	float e = 0.1234, p = 0.7264, r = 0.11;


	for (unsigned int j = 0; j != M; j++) {
		V1[j] = 0.0;
		test3[j] = 0.0;
		V2[j] = (j % 13) + e;
	}
}


unsigned short int ConstAdd_default() {

	for (int j = 0; j < M; j++) {
		V1[j] = V2[j] + 2.1234;
	}


	return 2;
}

unsigned short int ConstAdd_SSE() {

	__m128 num0, num1, num2, num3, num4, num5, num6;

	num1 = _mm_set_ps(2.1234, 2.1234, 2.1234, 2.1234); //set num1 values

	for (int i = 0; i < M; i += 4) { //IMPORTANT: M MUST BE A MULTIPLE OF 4, OTHERWISE IT DOES NOT WORK
		num2 = _mm_load_ps(&V2[i]); //load 4 elements of V2[]
		num3 = _mm_add_ps(num1, num2); //num3 = num1 + num2
		_mm_store_ps( &V1[i], num3); //store num3 to Y[i]. num3 has 4 FP values which they are stored into Y[i], Y[i+1], Y[i+2], Y[i+3], respectively
	}


	return 2;
}


unsigned short int ConstAdd_AVX() {

	__m256  ymm0, ymm1, ymm2, ymm3, ymm4;

	ymm1 = _mm256_set_ps(2.1234, 2.1234, 2.1234, 2.1234, 2.1234, 2.1234, 2.1234, 2.1234); //set num1 values
	for (int i = 0; i < M; i += 8) { //IMPORTANT: M MUST BE A MULTIPLE OF 8, OTHERWISE IT DOES NOT WORK
		ymm2 = _mm256_load_ps(&V2[i]); //load 8 elements of X2[]
		ymm3 = _mm256_add_ps(ymm1, ymm2); //num3 = num1 + num2
		_mm256_store_ps(&V1[i], ymm3); //store num3 to Y[i]. num3 has 8 FP values which they are stored into Y[i], Y[i+1], Y[i+2], Y[i+3], .. Y[i+7]
	}


	return 2;
}


unsigned short int Compare_ConstAdd() {


	for (int j = 0; j < M; j++) {
		test3[j] = V2[j] + 2.1234;
	}


	for (int j = 0; j < M; j++)
		if (equal(V1[j], test3[j]) == 1) {
			//printf("\n j=%d\n", j);
			return 1;
		}

	return 0;
}



