// test epool thread pool project


#include "epoll.h"

int main() {

	int ret = pool_init(MAX_THREAD_NUM);
	assert(ret == 0); 
}
