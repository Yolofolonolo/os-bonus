#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>


sem_t chopstick[5];
sem_t bowll;

void * philosopher(void *);

void createAndJoin(pthread_t tid[], void * philosopher, int a[]){
	int i = 0;
	while(i<5){
		a[i]=i;
		pthread_create(&tid[i],NULL,philosopher,(void *)&a[i]);
		i++;
	}
	i = 0;
	while(i<5){
		pthread_join(tid[i],NULL);
		i++;
	}
}

int main()
{
	int i,a[5];
	pthread_t tid[5];
	
	sem_init(&bowll,0,4);
	
	for(int i=0;i<5;i++){
		sem_init(&chopstick[i],0,1);}
		
	while(1){
		createAndJoin(tid,philosopher,a);
	}
}

void * philosopher(void * num)
{
	int phil=*(int *)num;
	
	sem_wait(&chopstick[phil]);
	sem_wait(&chopstick[(phil+1)%5]);
	sem_wait(&bowll);
	
	printf("\nPhilosopher %d is eating",phil+1);
	sleep(2);
	printf("\nPhilosopher %d has finished eating",phil+1);

	sem_post(&chopstick[(phil+1)%5]);
	sem_post(&chopstick[phil]);
	sem_post(&bowll);
	
}

