/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/



#include <stdlib.h>	/* needed to define exit() */
#include <unistd.h>	/* needed to define getpid() */
#include <stdio.h>	/* needed for printf() */

int main(int argc, char **argv) {

char *temp1,*temp2;

temp1="Hi";
temp2="There";

	printf("About to \n");
	execlp("echo", "echo", temp1, temp2, NULL); //the 1st argument is the command to run, the 2nd is the command name, the others are arguments passed to execlp. the last must be NULL
	perror("execlp");	/* if we get here, execlp failed */
	exit(1);
}


