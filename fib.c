#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "helper.h"

unsigned long long f(int n);

int main(int argc, char** argv) {
	const char* method = "nomemo";
	
	// make sure there's a cmd line arg
	if (argc != 2) {
		showUsage(method);
	}
	
	double time_taken;
	clock_t begin = clock();
	
	int N = atoi(argv[1]);
	int fN;
	if (N >= 0) {
		fN = f(N);
		printf("F%d = %llu\r\n", N, fN);	//terribly slow
	} else {
		showUsage(method);
	}
	
	clock_t end = clock();
	time_taken = (double)(end - begin) / CLOCKS_PER_SEC;

	
	makeOutput(method, N, fN, time_taken);

	return 0;
} 

// terribly slow
unsigned long long f(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;	
	return f(n-1) + f(n-2);
}


