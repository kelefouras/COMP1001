/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/

//compile with : gcc sqrt.c -o p -lpthread -lm


#include <stdio.h>      //for printf
#include <stdlib.h>
#include <pthread.h>    //for pthreads
#include <math.h>       //for fabs()
#include <time.h>	/* for clock_gettime */
#include <stdint.h>	/* for uint64 definition */


#define NUM_THREADS 4 //NUMBER OF THREADS USED. In this example, this value must perfectly divide N

#define N 10000000 // INPUT SIZE

#define ITERATIONS 1 

#define BILLION 1000000000L

double test1[N], X[N], Y[N];


void initialization();
unsigned short int equal(double const a, double const b);
unsigned short int Compare_sqrt();
void *sqrt_funct(void* rank);


#define EPSILON 0.0001


int main( ) {

   long int thread_num;//this variable will be used to pass the thread number to each thread

   pthread_t thread_handles[NUM_THREADS]; //this is an array of threads

   struct timespec start, end; //the timers to measure the execution time of the program
   uint64_t diff;


   initialization(); //initialize the arrays

	/* measure monotonic time */
   clock_gettime(CLOCK_MONOTONIC, &start);	/* mark start time */

for (int iter=0; iter< ITERATIONS; iter++){ //This loop is needed just to get an accurate execution time. To get an accurate execution time time of a multi-threaded application, the execution time must be about a minute (at least 10 secs). 


   for (thread_num = 0; thread_num < NUM_THREADS; thread_num++) //for each thread do
      pthread_create(&thread_handles[thread_num], NULL, sqrt_funct, (void*) thread_num); //create and run the thread. The thread will run the sqrt_funct(). The thread_num will be passed as input to the sqrt_funct().


   for (thread_num = 0; thread_num < NUM_THREADS; thread_num++) //for each thread do
      pthread_join(thread_handles[thread_num], NULL); //wait for the thread to finish

}

   clock_gettime(CLOCK_MONOTONIC, &end);	/* mark the end time */

	diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec; 
	printf("elapsed time = %llu mseconds\n", (long long unsigned int) diff/1000000);




   if (Compare_sqrt() == 0) //this function checks whether the result is correct or not
		printf("\n\n\r -----  output is correct -----\n\r");
   else
		printf("\n\n\r ----- output is INcorrect -----\n\r");

   return 0;
}  





void initialization() {

	double r = 0.1156;


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

unsigned short int equal(double const a, double const b) {
	double temp = a - b;
	//printf("\n %f  %f", a, b);
	if (fabs(temp)/b < EPSILON)
		return 0; //success
	else
		return 1;
}



void *sqrt_funct (void* thread_num) { //this function will run by all the threads. SINGLE PROGRAM MULTIPLE DATA

   long int my_thread_num = (long int ) thread_num; //store the input of the function to my_thread_num
   int i, j;

   int local = N/NUM_THREADS; //the number of array elements that each thread must compute their sqrt

   int starting_element = my_thread_num * local; //first array element to be computed by this thread
   int ending_element = starting_element + local - 1; //last array element to be computed by this thread

   for (i = starting_element; i <= ending_element; i++) {   
          Y[i] = sqrt ( X[i] );
   }

   return 0;
}  





