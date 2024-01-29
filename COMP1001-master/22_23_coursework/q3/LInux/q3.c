/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP3001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/

//compile with gcc gemver.c -o p -O3 -D_GNU_SOURCE  -march=native -mavx -lm -D_GNU_SOURCE

#include <stdio.h>
#include <stdint.h>	/* for uint64 definition */
#include <immintrin.h>
#include <math.h>
#include <stdio.h>
#include <emmintrin.h>
#include <limits.h>
#include <pmmintrin.h>

#include <sched.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <sys/mman.h>


#define N 8192
#define TIMES 1
#define BILLION 1000000000L
#define EPSILON 0.0001

void initialize();
void initialize_again();
void slow_routine(float alpha, float beta);//you will optimize this routine
unsigned short int Compare(float alpha, float beta);
unsigned short int equal(float const a, float const b) ;


float A[N][N], u1[N], u2[N], v1[N], v2[N], x[N], y[N], w[N], z[N], test[N] __attribute__((aligned(64))); ;
	

int main(){

float alpha=0.23, beta=0.45;


struct timespec start, end;
uint64_t diff;

//THIS CODE FORCES THIS PROCESS TO RUN ON CORE #0 ONLY
cpu_set_t mask;
CPU_ZERO(&mask);
CPU_SET(0,&mask);
if(sched_setaffinity(0,sizeof(mask),&mask) == -1)
       printf("WARNING: Could not set CPU Affinity, continuing...\n");

	  
initialize();



clock_gettime(CLOCK_MONOTONIC, &start);	/* mark start time */

for (unsigned int t=0;t<TIMES;t++)
 slow_routine(alpha,beta);

clock_gettime(CLOCK_MONOTONIC, &end);	/* mark the end time */
diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
printf("elapsed time = %llu nanoseconds or %llu msecs\n", (long long unsigned int) diff, (long long unsigned int) diff/1000000);


if (Compare(alpha,beta) == 0)
	printf("\nCorrect Result\n");
else 
	printf("\nINcorrect Result\n");


return 0;
}

void initialize(){

unsigned int    i,j;

//initialization
for (i=0;i<N;i++)
for (j=0;j<N;j++){
A[i][j]= 1.1;

}

for (i=0;i<N;i++){
z[i]=(i%9)*0.8;
x[i]=0.1;
u1[i]=(i%9)*0.2;
u2[i]=(i%9)*0.3;
v1[i]=(i%9)*0.4;
v2[i]=(i%9)*0.5;
w[i]=0.0;
y[i]=(i%9)*0.7;
}

}

void initialize_again(){

unsigned int    i,j;

//initialization
for (i=0;i<N;i++)
for (j=0;j<N;j++){
A[i][j]= 1.1;

}

for (i=0;i<N;i++){
z[i]=(i%9)*0.8;
x[i]=0.1;
test[i]=0.0;
u1[i]=(i%9)*0.2;
u2[i]=(i%9)*0.3;
v1[i]=(i%9)*0.4;
v2[i]=(i%9)*0.5;
y[i]=(i%9)*0.7;
}

}

//you will optimize this routine
void slow_routine(float alpha, float beta){

unsigned int i,j;

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      A[i][j] = A[i][j] + u1[i] * v1[j] + u2[i] * v2[j];


  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      x[i] = x[i] + beta * A[j][i] * y[j];

  for (i = 0; i < N; i++)
    x[i] = x[i] + z[i];


  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      w[i] = w[i] +  alpha * A[i][j] * x[j];


}


unsigned short int Compare(float alpha, float beta) {

unsigned int i,j;

initialize_again();


  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      A[i][j] = A[i][j] + u1[i] * v1[j] + u2[i] * v2[j];


  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      x[i] = x[i] + beta * A[j][i] * y[j];

  for (i = 0; i < N; i++)
    x[i] = x[i] + z[i];


  for (i = 0; i < N; i++){
    for (j = 0; j < N; j++){
     test[i]= test[i] + alpha * A[i][j] * x[j];
     } }



    for (j = 0; j < N; j++){
	if (equal(w[j],test[j]) == 1){
	  printf("\n %f %f",test[j], w[j]);
		return -1;
		}
		}

	return 0;
}






unsigned short int equal(float const a, float const b) {
	
	if (fabs(a-b)/fabs(a) < EPSILON)
		return 0; //success
	else
		return 1;
}





