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

char *args[] = {0};

execve("program1",args,NULL);

printf("Error");

return -1;
}

