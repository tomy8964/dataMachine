//201835546_Hamgeonwook

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>
#include <unistd.h>

#define true 1
#define false 0

int cnt = 0;
pthread_mutex_t mutex;

int cntPrime(int num)
{
	int cnt = 0;
	int i = 0;
	if (num < 2) return false;

	for (i = 1; i * i < num; i++)
	{
		if (num % i == 0) cnt++;
	}
	if (i * i == num) cnt++;
	if (cnt == 1) return true;
	else return false;
}

void* partial_prime(void* param)
{
	int range = *(int*)param;
	printf("thread for range (%d ~ %d)\n", range, range + 99999);

	// cnt prime mutex lock
	for (int i = range; i <= range + 99999; i++)
	{
		if (cntPrime(i)==true)
		{
			//acquire the mutex lock
			pthread_mutex_lock(&mutex);
			//critical section
			cnt++;
			//release the mutex lock
			pthread_mutex_unlock(&mutex);
		}
	}
	
	pthread_exit(0);
}

int main(int argc, char* argv[])
{
	int range = atoi(argv[1]);
	
	struct timespec start, finish;
	double elasped;

	// create mutex lock
	pthread_mutex_init(&mutex, NULL);

	clock_gettime(CLOCK_MONOTONIC, &start);

	int num_thread = 0;
	pthread_t tids[1024];
	int thr_id;
	int limit[1024];
	int status;

	int idx = 0;
	while (idx < range)
	{
		limit[num_thread] = idx;
		// create thread
		thr_id =pthread_create(&tids[num_thread], NULL, partial_prime, &limit[num_thread]);
		if (thr_id < 0)
		{
			perror("thread create error : ");
			exit(0);
		}
		num_thread++;
		idx += 100000;
		if (idx + 1 > range)
		{
			idx = range;
		}
	}

	// wait thread
	for (int i = 0; i < num_thread; i++)
	{
		pthread_join(tids[i], NULL);
	}

	clock_gettime(CLOCK_MONOTONIC, &finish);
	elasped = (finish.tv_sec - start.tv_sec);
	elasped += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;


	printf("elapsd timee: %f sec \n", elasped);
	printf("The number of prime numbers between 1~%d is %d\n", range, cnt);
	

	return 0;
}

