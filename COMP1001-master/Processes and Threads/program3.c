/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/

//compile using gcc program3.c -o program3

#include <stdio.h>

int main(int argc,char *argv[]){

if (argc>1)
	printf("\n %s %s \n",argv[0],argv[1]);
else
 printf("\n not enough arguments \n");

return 0;

}
