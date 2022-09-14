/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/
#include <stdio.h> //needed for printf
#include <string.h> //needed for strlen()
#include <windows.h> //this library is needed for pause() function
void approach1();
void approach2();

char s[] = "Hi There";//input string


int main() {

    approach1();
    approach2();

    system("pause"); //this command does not let the output window to close
    return 0;
}


void approach1() {

    unsigned int i=0;
    unsigned int counter = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        printf("\nThe element number %u is %c", i, s[i]);
        counter++;
    }

    printf("\n\nThe total number of elements is %u\n", counter);


}


void approach2() {

    printf("\n\nThe total number of elements is %ld\n", strlen(s));

}
