#include <ctime>
using namespace std;

void perf_time(){
	clock_t t = clock();
	// function
	t = clock() - t;
	printf("%0.4f\n", (double) t / CLOCKS_PER_SEC);
}