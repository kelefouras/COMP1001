/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/

//COMPILE WITH gcc phtreads_introduction.c -o p -lpthread

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //this library allows for using pthreads
#include <unistd.h>	/* needed to define getpid() */

void *print_message_function( void *ptr ); //this function takes as input a pointer to void, that is a pointer to everything (a pointer is a just a memory address). It returns a pointer to void too. A void pointer is a pointer that has no associated data type with it. A void pointer can hold address of any type and can be typcasted to any type.

int main() {

     pthread_t thread1, thread2, thread3, thread4; //declare the threads to be used

     char *message1 = "Thread 1"; //message to be passed to thread1. In C, a string is an array of characters
     char *message2 = "Thread 2"; //message to be passed to thread2
     char *message3 = "Thread 3"; //message to be passed to thread3
     char *message4 = "Thread 4"; //message to be passed to thread4

/*
___________
| message1 |     //this is an 8bytes variable containing the memory address of the string (pointer)
     |
     |--------------> |T|h|r|e|a|d| |1|\0|    //This is a string of 9 chars (9 bytes)  	

*/

     int  iret1, iret2, iret3, iret4; //these are the variables to hold the pthread_create() output values

     iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1); //create thread1 which will run its own print_message_function(). The 1st input operand must be a memory address and this is why the ampersand operator (&) is needed.
     iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2); //create thread2 which will run its own print_message_function()
     iret3 = pthread_create( &thread3, NULL, print_message_function, (void*) message3); //create thread3 which will run its own print_message_function()
     iret4 = pthread_create( &thread4, NULL, print_message_function, (void*) message4); //create thread4 which will run its own print_message_function()

       if (iret1!=0 || iret2!=0 || iret3!=0 || iret4!=0){ //if successful, pthread_create() must return 0. Thus, they must all return 0. Otherwise, at least one thread has not been created.
          printf("\nProblem with pthread_create()\n");
          exit(EXIT_FAILURE); //terminate the program and return an error message
       }

     pthread_join( thread1, NULL); //wait until thread1 finishes
     pthread_join( thread2, NULL);  //wait until thread2 finishes
     pthread_join( thread3, NULL);  //wait until thread3 finishes
     pthread_join( thread4, NULL);  //wait until thread4 finishes

     printf("\nThread 1 with ID= %ld completed, returned: %d\n",thread1, iret1);
     printf("Thread 2 with ID= %ld completed, returned: %d\n",thread2,iret2);
     printf("Thread 3 with ID= %ld completed, returned: %d\n",thread3,iret3);
     printf("Thread 4 with ID= %ld completed, returned: %d\n",thread4,iret4);

     exit(EXIT_SUCCESS); //terminate the program and return a success message 
}

void *print_message_function( void *ptr )
{
     char *message; //the string to store the input string
     message = (char *) ptr; //ptr is a pointer to everything; thus, we must inform the compiler that we need a pointer to char

    printf("%s has ID %ld --- The Process ID is %d \n",message,pthread_self(),getpid() );

}


