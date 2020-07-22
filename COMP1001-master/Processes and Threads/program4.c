#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {

char *temp[] = {"Hi","mate",NULL};

execve("program3",temp,NULL);

printf("Error");
return -1;

}

