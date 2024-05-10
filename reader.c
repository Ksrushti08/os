#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

sem_t w,r;
int rcount=0;
int rc=0;
int wc=0;
void *reader(void * arg)
{
	sem_wait(&r);
	rcount++;
	if(rcount==1){
	sem_wait(&w);
	}
	sem_post(&r);
	rc++;
	printf("\n%d:Reader is Reading",rc);
	//printf("%ld",pthread_self());
	sem_wait(&r);
	rcount--;
	if(rcount==0){
	sem_post(&w);
	}
	sem_post(&r);
	
}

void* writer(void * arg)
{

	sem_wait(&w);
	wc++;
	printf("\n%d:writer is writing",wc);
	//printf("%ld",pthread_self());
	sem_post(&w);

}


void main()
{
	sem_init(&r,0,1);
	sem_init(&w,0,1);
	
	pthread_t write[3],read[3];
	
	for(int i=0;i<3;i++)
	{
	 pthread_create(&write[i],NULL,writer,NULL);
	 pthread_create(&read[i],NULL,reader,NULL);
	
	}
	for(int i=0;i<3;i++)
	{
	 pthread_join(write[i],NULL);
	 pthread_join(read[i],NULL);
	
	}
	

}
