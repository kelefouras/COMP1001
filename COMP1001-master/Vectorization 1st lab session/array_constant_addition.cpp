#include "array_constant_addition.h"

float  V1[M], V2[M], test3[M]; 

void initialization_ConstAdd() {

	float e = 0.1234f, p = 0.7264f, r = 0.11f; //the f after the number specifies that the literal is a float. Otherwise, a double is assumed
	unsigned int j;

	for ( j = 0; j != M; j++) {
		V1[j] = 0.0f;
		test3[j] = 0.0f;
		V2[j] = (j % 13) + e;
	}
}


unsigned short int ConstAdd_default() {
	int j;

	for (j = 0; j < M; j++) {
		V1[j] = V2[j] + 2.1234f;
	}


	return 2;
}

unsigned short int ConstAdd_SSE() {

	__m128 num1, num2, num3;
	int i;

	num1 = _mm_set_ps(2.1234f, 2.1234f, 2.1234f, 2.1234f); //set num1 values

	for (i = 0; i < M; i += 4) { //IMPORTANT: M MUST BE A MULTIPLE OF 4, OTHERWISE IT DOES NOT WORK
		num2 = _mm_loadu_ps(&V2[i]); //load 4 elements of V2[]
		num3 = _mm_add_ps(num1, num2); //num3 = num1 + num2
		_mm_storeu_ps(&V1[i], num3); //store num3 to Y[i]. num3 has 4 FP values which they are stored into Y[i], Y[i+1], Y[i+2], Y[i+3], respectively
	}


	return 2;
}


unsigned short int ConstAdd_AVX() {

	__m256  ymm1, ymm2, ymm3;
	int i;

	ymm1 = _mm256_set_ps(2.1234f, 2.1234f, 2.1234f, 2.1234f, 2.1234f, 2.1234f, 2.1234f, 2.1234f); //set num1 values
	for (i = 0; i < M; i += 8) { //IMPORTANT: M MUST BE A MULTIPLE OF 8, OTHERWISE IT DOES NOT WORK
		ymm2 = _mm256_loadu_ps(&V2[i]); //load 8 elements of X2[]
		ymm3 = _mm256_add_ps(ymm1, ymm2); //num3 = num1 + num2
		_mm256_storeu_ps(&V1[i], ymm3); //store num3 to Y[i]. num3 has 8 FP values which they are stored into Y[i], Y[i+1], Y[i+2], Y[i+3], .. Y[i+7]
	}


	return 2;
}


unsigned short int Compare_ConstAdd() {
	int j;

	for (j = 0; j < M; j++) {
		test3[j] = V2[j] + 2.1234f;
	}


	for (j = 0; j < M; j++)
		if (equal(V1[j], test3[j]) == 1) {
			//printf("\n j=%d\n", j);
			return 1;
		}

	return 0;
}

unsigned short int equal(float a, float b) {
	float temp = a - b;
	//printf("\n %f  %f", a, b);
	if ( (fabs(temp)/fabs(b)) < EPSILON)
		return 0; //success
	else
		return 1; //wrong result
}




