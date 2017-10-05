#include <pthread.h>
 #include <stdio.h>
 #include<unistd.h>
 #include<semaphoro.h>
 #define NUM_THREADS     10

#define MAX_SIZE
int buffer[MAX_SIZE];

sem_t ready;  // initial 0 producer indicate that there is something
sem_t slots;

void *producer(void *threadid)
{
  int i = 0;
  while(1){
    i = i % MAX_SIZE;
    sem_wait(&slots);
    buffer[i] = int getRand(10.0);
    printf("Producer %i \n", buffer);
    sem_post(&ready);
    i++;
  }
}
void *consumer(void *threadid){
  int i=0;
  int value;
  while(1){
    i = i % MAX_SIZE;
    sem_wait(&ready);
    value = buffer[i];
    printf("Consumer %i \n", value);
    sem_post(&slots);
    i++;
  }
}

 int main (int argc, char *argv[])
 {
    pthread_t consumer;
    pthread_t producer;
    long t;

    sem_init(&ready,0,0);
    sem_init(&slots,0,MAX_SIZE);
    pthread_create(&ptconsumer, NULL, consumer, NULL;
    pthread_create(&ptconsumer, NULL, consumer, NULL;

    printf("El valor del saldo es %d\n ", saldo);
    /* Last thing that main() should do */
    pthread_exit(NULL);
 }
