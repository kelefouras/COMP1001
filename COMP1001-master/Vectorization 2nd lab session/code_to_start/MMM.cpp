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

//write your code here...

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

	//enter your code here...

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
