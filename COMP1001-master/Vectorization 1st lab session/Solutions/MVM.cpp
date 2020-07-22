#include "MVM.h"

void initialization_MVM() {

	float e = 0.1234, p = 0.7264, r = 0.11;

	//MVM
	for (unsigned int i = 0; i != M; i++)
		for (unsigned int j = 0; j != M; j++)
			A1[i][j] = ((i - j) % 9) + p;

	for (unsigned int j = 0; j != M; j++) {
		Y[j] = 0.0;
		test1[j] = 0.0;
		X[j] = (j % 7) + r;
	}
}


unsigned short int MVM_default() {

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			Y[i] += A1[i][j] * X[j];
		}
	}

	return 1;
}

unsigned short int MVM_SSE() {

	__m128 num0, num1, num2, num3, num4, num5, num6;

	for (int i = 0; i < M; i++) {

		num3 = _mm_setzero_ps();
		for (int j = 0; j < M; j += 4) { //IMPORTANT: M MUST BE A MULTIPLE OF 4, OTHERWISE IT DOES NOT WORK

			num0 = _mm_load_ps(&A1[i][j]);
			num1 = _mm_load_ps(&X[j]);
			num3 = _mm_fmadd_ps(num0, num1, num3);
		}

		num4 = _mm_hadd_ps(num3, num3);
		num4 = _mm_hadd_ps(num4, num4);

		_mm_store_ss(&Y[i], num4);
	}

	return 1;
}

unsigned short int MVM_AVX() {

	__m256 ymm0, ymm1, ymm2, ymm3, ymm4, ymm5, ymm6, num0, num1, num2, num3, num4, num5;
	__m128 xmm1, xmm2;

	for (int i = 0; i < M; i++) {
		num1 = _mm256_setzero_ps();

		for (int j = 0; j < M; j += 8) {//IMPORTANT: M MUST BE A MULTIPLE OF 8, OTHERWISE IT DOES NOT WORK

			num5 = _mm256_load_ps(&X[j]);
			num0 = _mm256_load_ps(&A1[i][j]);
			num1 = _mm256_fmadd_ps(num0, num5, num1);
		}


		ymm2 = _mm256_permute2f128_ps(num1, num1, 1);
		num1 = _mm256_add_ps(num1, ymm2);
		num1 = _mm256_hadd_ps(num1, num1);
		num1 = _mm256_hadd_ps(num1, num1);
		xmm2 = _mm256_extractf128_ps(num1, 0);
		_mm_store_ss(&Y[i], xmm2);
	}

	return 1;
}

unsigned short int Compare_MVM() {

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			test1[i] += A1[i][j] * X[j];
		}
	}

	for (int j = 0; j < M; j++)
		if (equal(Y[j], test1[j]) == 1) {
			//printf("\n j=%d\n", j);
			return 1;
		}

	return 0;
}


unsigned short int equal(float const a, float const b) {
	float temp = a - b;
	//printf("\n %f  %f", a, b);
	if (fabs(temp) < EPSILON)
		return 0; //success
	else
		return 1;
}
