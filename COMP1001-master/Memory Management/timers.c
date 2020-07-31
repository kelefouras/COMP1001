/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/


#include <stdio.h>	/* for printf */
#include <stdint.h>	/* for uint64 definition */
#include <stdlib.h>	/* for exit() definition */
#include <time.h>	/* for clock_gettime */
#include <unistd.h> //for sleep



#define BILLION 1000000000L

long int do_something();
void do_something_else();

int main( )
{
	uint64_t diff;
	struct timespec start, end;
	int i;
        long int output;

	/* measure monotonic time */
	clock_gettime(CLOCK_MONOTONIC, &start);	/* mark start time */

	//do_something_else();
	output=do_something();

	clock_gettime(CLOCK_MONOTONIC, &end);	/* mark the end time */

	diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
	printf("elapsed time = %llu nanoseconds\n", (long long unsigned int) diff);

	/* now the measure CPU time for this process only */
	/* the time spent sleeping will not count (but there is a bit of overhead */
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);	/* mark start time */

	 //do_something_else();
	output=do_something();

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);		/* mark the end time */

	diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
	printf("elapsed process CPU time = %llu nanoseconds\n", (long long unsigned int) diff);


}


long int do_something(){

int i;
long int tmp=0;


for (i=0;i<1000000;i++){
 if (i%3==0)
	tmp+=i;
 else tmp+=(i+1)*3;
}
 

}

void do_something_else(){

sleep(1);
}




