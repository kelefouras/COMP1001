#include "if_cond.h"

void if_cond_init() {

	float e = 0.1234, p = 0.7264, r = 0.11;

	//if_cond()
	for (int j = 0; j < N_IF; j++) {
		array2[j] = (float)(j % 99);
		array1[j] = (j % 3) + e;
		testt[j] = array1[j];
	}


}




unsigned short int if_cond_default() {

	int i;

	for (i = 0; i < N_IF; i++) {
		if (array2[i] > 60.0 || array2[i] < 20.0)
			array1[i] += array2[i];
	}

	return 2;
}


unsigned short int if_cond_SSE() {

	int i;
	const __m128 sixty = _mm_set1_ps(60.0);
	const __m128 twenty = _mm_set1_ps(20.0);
	__m128 ar1, ar2, c1, c2, c;

	for (i = 0; i < ((N_IF / 4) * 4); i += 4) { //e.g., if N_IF==10, then ((10/4)*4)=8 as the division is between integers
		ar1 = _mm_load_ps(array1 + i);
		ar2 = _mm_load_ps(array2 + i);

		c1 = _mm_cmpgt_ps(ar2, sixty);
		c2 = _mm_cmplt_ps(ar2, twenty);
		c = _mm_or_ps(c1, c2);

		ar2 = _mm_and_ps(c, ar2);
		ar2 = _mm_add_ps(ar2, ar1);

		_mm_store_ps(array1 + i, ar2);
	}

	for (; i < N_IF; i++) {
		if (array2[i] > 60.0 || array2[i] < 20.0)
			array1[i] += array2[i];
	}

	return 2;
}


unsigned short int if_cond_AVX() {

	int i;
	const __m256 sixty = _mm256_set1_ps(60.0);
	const __m256 twenty = _mm256_set1_ps(20.0);
	__m256 ar1, ar2, c1, c2, c;

	for (i = 0; i < ((N_IF / 8) * 8); i += 8) {
		ar1 = _mm256_load_ps(array1 + i);
		ar2 = _mm256_load_ps(array2 + i);

		c1 = _mm256_cmp_ps(ar2, sixty, _CMP_GT_OQ);
		c2 = _mm256_cmp_ps(ar2, twenty, _CMP_LT_OQ);
		c = _mm256_or_ps(c1, c2);

		ar2 = _mm256_and_ps(c, ar2);
		ar2 = _mm256_add_ps(ar2, ar1);

		_mm256_store_ps(array1 + i, ar2);

	}

	for (; i < N_IF; i++) {
		if (array2[i] > 60.0 || array2[i] < 20.0)
			array1[i] += array2[i];
	}

	return 2;
}

unsigned short int Compare_if_cond() {

	int i;

	for (i = 0; i < N_IF; i++) {
		if (array2[i] > 60.0 || array2[i] < 20.0)
			testt[i] += array2[i];
	}

	for (int j = 0; j < N_IF; j++)
		if (equal(testt[j], array1[j]) == 1)
			return 1;

	return 0;
}

