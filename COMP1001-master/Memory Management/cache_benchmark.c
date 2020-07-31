/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/

// compile with : gcc cache_benchmark.c -o p -D_GNU_SOURCE  -g  -pthread 

#include <stdio.h>	/* for printf */
#include <stdint.h>	/* for uint64 definition */
#include <stdlib.h>	/* for exit() definition */
#include <time.h>	/* for clock_gettime */
#include <unistd.h> //for sleep
#include <pthread.h>

#define N 1000

#define TIMES 1000

int X[N];


#define BILLION 1000000000L

void cache_benchmark();

int main( )
{
	uint64_t diff;
	struct timespec start, end;
	int i;
        long int output;

        //the following code binds this thread to code number 0. Without this code, the OS will tongle the thread among the cores, to reduce heat dissipation
	cpu_set_t mask;
	CPU_ZERO(&mask);
	CPU_SET(0,&mask);
	if(sched_setaffinity(0,sizeof(mask),&mask) == -1)
          printf("WARNING: Could not set CPU Affinity, continuing...\n");


	/* measure monotonic time */
	clock_gettime(CLOCK_MONOTONIC, &start);	/* mark start time */

	cache_benchmark();

	clock_gettime(CLOCK_MONOTONIC, &end);	/* mark the end time */

	diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
	printf("elapsed time = %llu nanoseconds\n", (long long unsigned int) diff);

	/* now the measure CPU time for this process only */
	/* the time spent sleeping will not count (but there is a bit of overhead */
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);	/* mark start time */

	cache_benchmark();

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);		/* mark the end time */

	diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
	printf("elapsed process CPU time = %llu nanoseconds\n", (long long unsigned int) diff);


}


void cache_benchmark(){

int i,j;

 for (i=0; i<TIMES; i++)
  for (j=0; j<N; j++){
   X[j]=i;
}
 


}





