#include "MMM.h"

void MMM_init() {

	float e = 0.1234, p = 0.7264, r = 0.11;

	//MMM
	for (unsigned int i = 0; i < N; i++) { //printf("\n");
		for (unsigned int j = 0; j < N; j++) {
			C[i][j] = 0.0;
			test[i][j] = 0.0;
			A[i][j] = (j % 9) + p; //printf(" %3.1f",A[i][j]);
			B[i][j] = (j % 7) - p; //printf(" %3.1f",B[i][j]);
		}
	}
	   

}


unsigned short int MMM_default() {

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				C[i][j] += A[i][k] * B[k][j];

	return 0;
}



unsigned short int MMM_SSE() {
	int i, j, k;
	__m128 num0, num1, num2, num3, num4, num5, num6, num7, xmm1, xmm2;
	float temp;

	//B[][] array needs to be written in maim memory column-wise and not row-wise
	//SIMD hardware can load only consecutive main memory locations and the arrays are written in main memory row-wise
	//thus, this loop kernels copies the data from B[][] and stores them to Btranspose[][]
	//this loop kernel can be implemented using SSE too, thus boosting performance
	for (j = 0; j != N; j++)
		for (k = 0; k != N; k++) {
			Btranspose[k][j] = B[j][k];
		}

	//this is not the most efficient implementation but it is faster 
	for (i = 0; i != N; i++)
		for (j = 0; j != N; j++) {
			num3 = _mm_setzero_ps();
			for (k = 0; k != ((N / 4) * 4); k += 4) {
				num0 = _mm_load_ps(&A[i][k]);
				num1 = _mm_load_ps(&Btranspose[j][k]);
				num3 = _mm_fmadd_ps(num0, num1, num3);
			}
			num4 = _mm_hadd_ps(num3, num3);
			num4 = _mm_hadd_ps(num4, num4);
			_mm_store_ss(&C[i][j], num4);


			for (; k < N; k++) { //equivalently you could write ' for (k=(N/4)*4; k < N; k++) '
				C[i][j] += A[i][k] * Btranspose[j][k];
			}

		}

	return 0;
}


//this routine is shown just for consistency. You do not have to study it
unsigned short int MMM_AVX() {
	__m256 ymm0, ymm1, ymm2, ymm3, ymm4, ymm5, ymm6, ymm7, ymm8, ymm9, ymm10, ymm11, ymm12, ymm13, ymm14, ymm15;
	__m128 xmm1, xmm2;
	int i, j, k;
	float temp;
	//B[][] array needs to be written in maim memory column-wise and not row-wise
//SIMD hardware can load only consecutive main memory locations and the arrays are written in main memory row-wise
//thus, this loop kernels copies the data from B[][] and stores them to Btranspose[][]
//this loop kernel can be implemented using SSE too, thus boosting performance
	for (j = 0; j != N; j++)
		for (k = 0; k != N; k++) {
			Btranspose[k][j] = B[j][k];
		}

	//this is not the most efficient implementation but it is faster
	for (i = 0; i != N; i++)
		for (j = 0; j != N; j++) {
			ymm0 = _mm256_setzero_ps();
			for (k = 0; k != ((N / 8) * 8); k += 8) {
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

			for (; k < N; k++) {
				C[i][j] += A[i][k] * Btranspose[j][k];
			}
		}

	return 0;
}


unsigned short int Compare_MMM() {

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				test[i][j] += A[i][k] * B[k][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (equal(C[i][j], test[i][j]) == 1)
				return 1;

	return 0;
}
