/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/

// compile with : gcc mmm.c -o p -O3 -fopenmp

#include <stdio.h>	/* for printf */
#include <stdint.h>	/* for uint64 definition */
#include <stdlib.h>	/* for exit() definition */
#include <time.h>	/* for clock_gettime */
#include <unistd.h> //for sleep
#include <pthread.h>//for cpu_set_t
#include <omp.h> //for openmp


#define N 1024 //input size
#define NUM_THREADS 4 //number of threads

//functions declaration
void MMM_init();
int MMM();


float  C[N][N], A[N][N], B[N][N]; //define the arrays


int main(){

    MMM_init(); //initialize the arrays

    MMM; //run the routine

    return 0;

}



void MMM_init() {

	float e = 0.1234f, p = 0.7264f;

	//MMM
	for (unsigned int i = 0; i < N; i++) { 
		for (unsigned int j = 0; j < N; j++) {
			C[i][j] = 0.0f;
			A[i][j] = ( (j+i) % 99) + e; 
			B[i][j] = ( (j-i) % 99) - p; 
		}
	}
	   

}


int MMM() {

int i,j,k;

omp_set_num_threads(NUM_THREADS);//specify the number of threads

   #pragma omp parallel for private (j,k) //parallelize i loop
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			for (k = 0; k < N; k++)
				C[i][j] += A[i][k] * B[k][j];
				

	return 0;
}







