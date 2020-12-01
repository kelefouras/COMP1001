#include "coursework.h"

float  V1[M], V2[M], test[M]; 

void initialization() {

	float e = 0.1234f, p = 0.7264f, r = 0.11f;
	int i, j;
	
	for (j = 0; j != M; j++) {
		V1[j] = (j % 17) + p;
		V2[j] = (j % 13) + e;
		test[j] = V1[j];
	}
}


unsigned short int default_routine() {
	int i,j;

	 for (j = 0; j < M; j++) {
		V1[j] = V1[j] + V2[j] + 2.12f;
	}


	return 2;
}

unsigned short int SSE() {

//WRITE YOUR CODE HERE
	

	return 2;
}





unsigned short int Compare() {
	int i, j;

	 for (j = 0; j < M; j++) {
		test[j] = test[j] + V2[j] + 2.12f;
	}


		for (j = 0; j < M; j++)
		 if (equal(V1[j], test[j]) == 1) {
			//printf("\n i,j=%d,%d\n", i,j);
			return 1;
		}

	return 0;
}

unsigned short int equal(float a, float b) {
	float temp = a - b;
	//printf("\n %f  %f", a, b);
	if (fabs(temp) < EPSILON)
		return 0; //success
	else
		return 1; //wrong result
}




