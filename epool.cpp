#include <sys/epool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#include "epool.h"


static cthread_pool_t* pool = NULL;
int pool_init(int max_thread_num)
{
	pool = (cthread_pool_t*)malloc(sizeof(cthread_pool_t));
	if (NULL == poll) {
		printf("failed to make pool");
		return -1;
	}
	pthread_mutex_init(&(pool->queue_lock), NULL);
	pthread_cond_init(&(pool->queue_ready), NULL);
	

	pool->queue_head = NULL;
	pool->max_thead_num = max_thread_num;
	pool->cur_queue_size = 0;
	pool->shutdown = 0;

	pool->thread_array = (pthread_t*)malloc(sizeof(pthread_t)*max_thread_num);

	// generate threads

	for (int i = 0; i < max_thread_num; i++) {
		pthread_create(&(pool->thread_array[i]), NULL, threadRoutine, NULL);
	}

	return 0;
}

