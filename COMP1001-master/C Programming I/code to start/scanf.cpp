/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/

#include <stdio.h>
#include <windows.h> //this library is needed for pause() function


void main()
{
    char name[20];

    printf("\nEnter your name: "); //get input from keyboard

    scanf_s("%19s", name, sizeof(name));

    printf("\nYour name is %s\n", name);

system("pause"); //this command does not let the output window to close

}
