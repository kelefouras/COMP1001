#include <stdio.h> //needed for printf
#include <string.h> //needed for strlen()

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

int i;

    for (i = 0; s[i] != '\0'; i++)
     printf("\nThe element number %d is %c", i,s[i] );

    printf("\n\nThe total number of elements is %d\n", i );



}


void approach2(){

printf("\n\nThe total number of elements is %ld\n", strlen(s) );

}
