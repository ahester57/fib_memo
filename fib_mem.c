#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "helper.h"

void buildList(unsigned long long* R, int N);

int main(int argc, char** argv) {
	const char* method = "memo";

	// make sure there's a cmd line arg
	if (argc != 2) {
		showUsage(method);
	}
	
	double time_taken;
	clock_t begin = clock();
	
	// As big as big
	unsigned long long* R;
	int N = atoi(argv[1]);
	FILE* fp;
	
	if (N >= 0) {
		
		R = malloc((N+1) * sizeof(unsigned long long));
		
		// is this part cheating for efficiency?
		// fp = fopen("_fib.log", "r");
		// if (fp == NULL) {
			// buildList(R, N);		// memoize and memorize
		// } else {
			// if (N > getNumLines(fp)) {
				// buildList(R, N);
			// } else {
				// printf("list read from file\r\n");
				// setArray(R, fp);	//do magic
			// }
		// }
		buildList(R, N);
		
		
		printf("F%d = %llu\r\n", N, R[N]);
		
	} else {
		showUsage(method);
	}
	
	clock_t end = clock();
	time_taken = (double)(end - begin) / CLOCKS_PER_SEC;
	
	//makeOutput(method, N, R[N], time_taken);
	
	free(R);
	fclose(fp);
	return 0;
} 

void buildList(unsigned long long* R, int N) {
	FILE* fp;
	fp = fopen("_fib.log", "w");
	R[0] = 0;
	R[1] = 1;
	fprintf(fp, "%llu\r\n%lu\r\n", R[0], R[1]);
	for (int i = 2; i < N+1; i++) {
		R[i] = R[i-1] + R[i-2];
		fprintf(fp, "%llu\r\n", R[i]);
	}
	fflush(fp);
}


