#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int chunksize=100;
int array[1000];
void *Addition(void *arg){

	int start=(int)arg;
	int sum=0;
	for(int i=start;i=start+chunksize;i++)
		sum=sum+array[i];

	return ((void*) sum);
}

int main()
{
int sum=0;
int s[10];
for(int i=0;i<1000;i++){
	array[i]=i+1;
}
pthread_t thread[10];
for(int i=0;i<10;i++)
{
	int k=i*chunksize;
	pthread_create(&thread[i],NULL,Addition,(void*)k);
}
for(int i=0;i<10;i++)
{
	pthread_join(thread[i],(void**) &s[i]);
}
for(int i=0;i<10;i++)
{
sum+=s[i];
}
printf("\nSum: %d\n",sum); 
return 0;
}
