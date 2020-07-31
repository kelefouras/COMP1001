/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/

#include <Windows.h>
#include "MVM.h"
#include "MMM.h"
#include "if_cond.h"

#define TIMES_TO_RUN 1 //how many times the function will run

void print_message(char *s, unsigned short int outcome);

//using namespace std; 

char message[20];


int main() {

	unsigned short int output;

	//the following command pins the current process to the 1st core
	//otherwise, the OS tongles this process between different cores
	BOOL success = SetProcessAffinityMask(GetCurrentProcess(), 1);
	if (success == 0) {
		//cout << "SetProcessAffinityMask failed" << endl;
		printf("\nSetProcessAffinityMask failed\n");
		system("pause");
		return -1;
	}

	//initialize the arrays
	MVM_init();
	MMM_init();
	if_cond_init();

	//define the timers measuring execution time
	clock_t start_1, end_1; //ignore this for  now
	start_1 = clock(); //start the timer (THIS IS NOT A VERY ACCURATE TIMER) - ignore this for now

	//auto start = std::chrono::high_resolution_clock::now(); //ACCURATE timer provided in C++ only

	//run this several times because this routine runs very fast 
	//The execution time needs to be at least some seconds in order to have a good measurement (why?) 
	//			because other processes run at the same time too, preempting our thread
	//---Appropriately MODIFY the 'TIMES_TO_RUN' and the input size (defined in the appropriate header file)---
	for (int t = 0; t < TIMES_TO_RUN; t++) {

		//output=MVM_default();
		output=MVM_SSE();
		//output=MVM_AVX();

		//output=MMM_default();
		//output=MMM_SSE();
		//output=MMM_AVX();

		//output=if_cond_default();
		//output = if_cond_SSE();
		//output = if_cond_AVX();

	}



	//auto finish = std::chrono::high_resolution_clock::now(); 
	end_1 = clock(); //end the timer - ignore this for now

	if (output == 1) {
		snprintf(message, sizeof(message) - 1, "MVM Program");
		print_message(message, Compare_MVM());
	}
	else if (output == 0) {
		snprintf(message, sizeof(message) - 1, "MMM program");
		print_message(message, Compare_MMM());
	}
	else if (output == 2) {
		snprintf(message, sizeof(message) - 1, "If condition program");
		print_message(message, Compare_if_cond());
	}
	else {
		printf("\n Error\n");
	}

	printf(" clock() method: %ldms\n", (end_1 - start_1) / (CLOCKS_PER_SEC / 1000));
	//std::chrono::duration<double> elapsed = finish - start;
	//std::cout << "Elapsed time: " << elapsed.count() << " s\n";

	system("pause"); //this command does not let the output window to close
	return 0;
}




void print_message(char *s, unsigned short int outcome) {

	if (outcome == 0)
		printf("\n\n\r ----- %s output is correct -----\n\r", s);
	else
		printf("\n\n\r -----%s output is INcorrect -----\n\r", s);

}


