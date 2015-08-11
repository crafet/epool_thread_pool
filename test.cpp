// test epool thread pool project


#include "epool.h"

int main() {

	int ret = pool_init(MAX_THREAD_NUM);
	assert(ret == 0); 
}
