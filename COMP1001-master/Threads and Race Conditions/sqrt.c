//compile with : gcc sqrt.c -o p -lpthread -lm


#include <stdio.h>      //for printf
#include <stdlib.h>
#include <pthread.h>    //for pthreads
#include <math.h>       //for fabs()
#include <time.h>	/* for clock_gettime */
#include <stdint.h>	/* for uint64 definition */


#define NUM_THREADS 4 //NUMBER OF THREADS USED

#define N 10000000 // INPUT SIZE

#define ITERATIONS 1

#define BILLION 1000000000L

float test1[N], X[N], Y[N];


void initialization();
unsigned short int equal(float const a, float const b);
unsigned short int Compare_sqrt();
void *sqrt_funct(void* rank);


#define EPSILON 0.01


int main( ) {

   long thread;
   pthread_t* thread_handles;

   struct timespec start, end; //timers
   uint64_t diff;

   thread_handles = malloc(NUM_THREADS * sizeof(pthread_t)); //dynamicaly allocate the thread ids

   initialization();

	/* measure monotonic time */
   clock_gettime(CLOCK_MONOTONIC, &start);	/* mark start time */

for (int iter=0; iter< ITERATIONS; iter++){ //run this many times to get an accurate measurement

   for (thread = 0; thread < NUM_THREADS; thread++) 
      pthread_create(&thread_handles[thread], NULL, sqrt_funct, (void*) thread); //create and run the threads

   for (thread = 0; thread < NUM_THREADS; thread++)
      pthread_join(thread_handles[thread], NULL); //wait for the threads to finish
}

   clock_gettime(CLOCK_MONOTONIC, &end);	/* mark the end time */

	diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
	printf("elapsed time = %llu nanoseconds\n", (long long unsigned int) diff);


   free(thread_handles); //free the array allocated with malloc


   if (Compare_sqrt() == 0) //this function checks whether the result is correct or not
		printf("\n\n\r -----  output is correct -----\n\r");
   else
		printf("\n\n\r ----- output is INcorrect -----\n\r");

   return 0;
}  





void initialization() {

	float e = 0.1234, p = 0.7264, r = 0.11;


	for (unsigned int j = 0; j != N; j++) {
		Y[j] = 0.0; //initialize the output with zero
		test1[j] = 0.0; //initialize the output with zero
		X[j] = (j % 7) + r; //initialize with some floating point values
	}

}

unsigned short int Compare_sqrt() {

	for (int i = 0; i < N; i++) {
			test1[i] += sqrt ( X[i] );
		}
	

	for (int j = 0; j < N; j++)
		if (equal(Y[j], test1[j]) == 1) {
			printf("\n j=%d\n", j);
			return 1; //values are not equal
		}

	return 0; //success
}

unsigned short int equal(float const a, float const b) {
	float temp = a - b;
	//printf("\n %f  %f", a, b);
	if (fabs(temp) < EPSILON)
		return 0; //success
	else
		return 1;
}



void *sqrt_funct (void* rank) {

   long my_rank = (long) rank;
   int i, j;

   int local = N/NUM_THREADS; 

   int starting_row = my_rank * local;
   int ending_row = starting_row + local - 1;

   for (i = starting_row; i <= ending_row; i++) {   
          Y[i] = sqrt ( X[i] );
   }

   return 0;
}  





