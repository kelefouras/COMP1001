/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {

char *temp[] = {"Hi","mate",NULL}; //This is an array of pointers to strings. This is an array of character pointers where each pointer points to the first character of the string or the base address of the string. temp[0] points to this array 'Hi\n', temp[1] points to 'mate\0'.

execve("program3",temp,NULL);

printf("Error");
return -1;

}

