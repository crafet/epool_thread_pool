


#define BUFFER_SIZE 100

typedef struct client_data {
	int sockfd;

	int mask;

	int chats[BUFFER_SIZE];
}client_data_t;

typedef void* (*thread_func_t)(void* arg);

typedef struct cthread_worker {
	thread_func_t process;

	// thread private data
	void* data;

	// next
	cthread_worker* next;

} cthread_worker_t;

typedef struct cthread_pool {

		pthread_mutex_t queue_lock;
		pthread_cond_t queue_ready;

		cthread_worker_t* queue_head;

		// thread array
		pthread_t* threads;
		int max_thread_num;

		int cur_queue_size;
} cthread_pool_t;


// function declare

int pool_init(int max_thread_num);

int pool_add_worker(thread_func_t process);

int pool_destroy();
