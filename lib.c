#include <stdio.h>
#include <sys/time.h>

int main() {
	struct timeval a;
	for(int i = 0; i < 10000000; i++) {
		gettimeofday(&a, NULL);
	}
	return 0;
}
