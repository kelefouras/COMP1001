/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/

#include <stdio.h>
#include <pthread.h>

int x= 0;


void* function( );

int main()
{
    pthread_t t1, t2, t3, t4;
    printf("In the beginning x value is: %d\n", x);

    pthread_create(&t1, NULL, function, NULL);
    pthread_create(&t2, NULL, function, NULL);
    pthread_create(&t3, NULL, function, NULL);
    pthread_create(&t4, NULL, function, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    printf("In the end x value is: %d\n", x);
    return 0;
}


void* function( )
{
    int i;
    for ( i = 0; i < 1000000; i++ )
    {
        x++;
    }
}
