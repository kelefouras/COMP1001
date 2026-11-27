/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/


#include <stdio.h>
#include <time.h>
#include <pmmintrin.h>
#include <process.h>
#include <chrono>
#include <iostream>
#include <immintrin.h>
#include <omp.h>

#define M 1024*512
#define ARITHMETIC_OPERATIONS1 3*M
#define TIMES1 1

#define N 8192
#define ARITHMETIC_OPERATIONS2 4*N*N
#define TIMES2 1


//function declaration
void initialize();
void routine1(float alpha, float beta);
void routine2(float alpha, float beta);

__declspec(align(64)) float  y[M], z[M];
__declspec(align(64)) float A[N][N], x[N], w[N];

int main() {

    float alpha = 0.023f, beta = 0.045f;
    double run_time, start_time;
    unsigned int t;

    initialize();

    printf("\nRoutine1:");
    start_time = omp_get_wtime(); //start timer

    for (t = 0; t < TIMES1; t++)
        routine1(alpha, beta);

    run_time = omp_get_wtime() - start_time; //end timer
    printf("\n Time elapsed is %f secs \n %e FLOPs achieved\n", run_time, (double)(ARITHMETIC_OPERATIONS1) / ((double)run_time / TIMES1));

    printf("\nRoutine2:");
    start_time = omp_get_wtime(); //start timer

    for (t = 0; t < TIMES2; t++)
        routine2(alpha, beta);

    run_time = omp_get_wtime() - start_time; //end timer
    printf("\n Time elapsed is %f secs \n %e FLOPs achieved\n", run_time, (double)(ARITHMETIC_OPERATIONS2) / ((double)run_time / TIMES2));



    return 0;
}

void initialize() {

    unsigned int i, j;

    //initialize routine2 arrays
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) {
            A[i][j] = (i % 99) + (j % 14) + 0.013f;
        }

    //initialize routine1 arrays
    for (i = 0; i < N; i++) {
        x[i] = (i % 19) - 0.01f;
        w[i] = (i % 5) - 0.002f;
    }

    //initialize routine1 arrays
    for (i = 0; i < M; i++) {
        z[i] = (i % 9) - 0.08f;
        y[i] = (i % 19) + 0.07f;
    }


}

#include <emmintrin.h>


void routine1(float alpha, float beta) {

    const __m128 alpha_vec = _mm_set1_ps(alpha);
    const __m128 beta_vec = _mm_set1_ps(beta);

    for (unsigned int i = 0; i < M; i += 4) {
        __m128 y_vec = _mm_loadu_ps(&y[i]);
        __m128 z_vec = _mm_loadu_ps(&z[i]);

        y_vec = _mm_add_ps(_mm_mul_ps(alpha_vec, y_vec), _mm_mul_ps(beta_vec, z_vec));

        _mm_storeu_ps(&y[i], y_vec);
    }
}



void routine2(float alpha, float beta) {

    const __m128 alpha_vec = _mm_set1_ps(alpha);
    const __m128 beta_vec = _mm_set1_ps(beta);

    for (unsigned int i = 0; i < N; ++i) {
        __m128 w_vec = _mm_loadu_ps(&w[i]);

        for (unsigned int j = 0; j < N; j += 4) {
            __m128 A_vec = _mm_loadu_ps(&A[i][j]);
            __m128 x_vec = _mm_loadu_ps(&x[j]);

            w_vec = _mm_sub_ps(w_vec, beta_vec);
            w_vec = _mm_add_ps(w_vec, _mm_mul_ps(_mm_mul_ps(alpha_vec, A_vec), x_vec));
        }

        _mm_storeu_ps(&w[i], w_vec);
    }
}