#include <stdio.h> 
#include <pthread.h> 
#include <stdlib.h>
#include <unistd.h> //for sleep

int x=0;
int y=0;

pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

void * func1(void *temp) {

pthread_mutex_lock(&mutex1); //mutex1 is used for x

x++;
printf("\nthread1 entered crical section for x");

pthread_mutex_unlock(&mutex1);


pthread_mutex_lock(&mutex2); //mutex2 is used for y

y--;
printf("\nthread1 entered crical section for y");

pthread_mutex_unlock(&mutex2);


return 0;
}


void * func2(void *temp) {


pthread_mutex_lock(&mutex1); //mutex1 is used for x

x++;
printf("\nthread2 entered crical section for x");

pthread_mutex_unlock(&mutex1);


pthread_mutex_lock(&mutex2); //mutex2 is used for y

y--;
printf("\nthread2 entered crical section for y");

pthread_mutex_unlock(&mutex2);

return 0;
}




int main() {

pthread_t t1,t2;

int ret1,ret2;


ret1=pthread_create(&t1,NULL,&func1,NULL);
ret2=pthread_create(&t2,NULL,&func2,NULL);

pthread_join(t1,NULL);
pthread_join(t2,NULL);

printf("\nx=%d, y=%d\n",x,y);

return 0;
}



