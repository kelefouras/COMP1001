/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/


#include <stdio.h> //this library is needed for printf() function
#include <windows.h> //this library is needed for pause() function

void main() {
	printf("Size of char: %lu\n", sizeof(char));
	printf("Size of short: %lu\n", sizeof(short));
	printf("Size of int: %lu\n", sizeof(int));
	printf("Size of long: %lu\n", sizeof(long));
	printf("Size of long long: %lu\n", sizeof(long long));
	printf("Size of float: %lu\n", sizeof(float));
	printf("Size of double: %lu\n", sizeof(double));
	printf("Size of long double: %lu\n", sizeof(long double));

	system("pause"); //this function prevents from closing the output window

}
