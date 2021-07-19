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

char s[] = "Hi There";


int main() {
    
    approach1();
    approach2();
    
	system("pause"); //this command does not let the output window to close
    return 0;
}


void approach1(){

int i=0;

    while ( s[i] != '\0'){
     printf("\nThe element number %d is %c", i,s[i] );
     i++;
    }

    printf("\n\nThe total number of elements is %d\n", i );



}


void approach2(){

printf("\n\nThe total number of elements is %ld\n", strlen(s) );

}
