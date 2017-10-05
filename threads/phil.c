#include <pthread.h>
 #include <stdio.h>
 #include<unistd.h>
 #include<stdlib.h>
 #include<semaphoro.h>

 #define NUM_PHIL  5
  #define NUM_FORK 5
  #define NUM_CHAIRS  NUM_FORL / 2

sem_t forks[NUM_FORK];
sem_t charis;
int getRand(int max)
{

  return 1+ (rand() * max) / RAND_MAX;
}

void eating(void)
{
  sleep(getRand(5.0));
}

void thinking(void)
{
  sleep(getRand(5.0));
}

void *phillive(void *threadid)
{
  long tid;
  tid = (long)threadid;
  while(1){

    printf("I am phil %ld , thinking \n", tid);
    thinking();
    sem_wait(&chairs);
    sem_wait(&forks[tid]);
    sem_wait(&forks[(tid+ 1) % NUM_PHIL]);
    printf("I am phil %ld , eating" \n, tid);
    eating();
    sem_post(&forks[tid]);
    sem_post(&forks[(tid+ 1) % NUM_PHIL]);
    sem_wait(&chairs);
  }
}

 int main (int argc, char *argv[])
 {
    pthread_t philosophers[NUM_THREADS];
    int rc;
    long t;
    srand(time(NULL));
    for(t=0; t<NUM_THREADS; t++){
        sem_init(&forks[t],0,1);
    }
    sem_init(&chairs, 0,NUM_CHAIRS)
    for(t=0; t<NUM_THREADS; t++){
       printf("In main: creating thread %ld\n", t);
       rc = pthread_create(&philosophers[t], NULL, phillive, (void *)t);
       if (rc){
          printf("ERROR; return code from pthread_create() is %d\n", rc);
          exit(-1);
       }
    }


    printf("El valor del saldo es %d\n ", saldo);
    /* Last thing that main() should do */
    pthread_exit(NULL);
 }
