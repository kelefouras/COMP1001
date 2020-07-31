/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/

//how to compile : gcc ex1.c -o p
//how to run : ./p arg1 arg2 etc

#include <stdio.h>

int
main(int argc, char **argv) //argc stands for arguments count and argv stands for arguments vector 
{
	int i;

	printf("argc = %d\n", argc);
	for (i=0; i<argc; i++) 
		printf("arg[%d] = \"%s\"\n", i, argv[i]);
}
