#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "helper.h"

// file helper

void setArray(unsigned long long* A, FILE* fp) {
	int n = 0;
	char* line = malloc(24*sizeof(char));

	fseek(fp, 0, SEEK_SET);
	while (fgets(line, 24, (FILE*)fp)) {
		A[n] = strtoull(line, NULL, 10);	// hope for numbers
		//printf("%d, ", A[n]);
		n++;
	}	
	free(line);
}

void makeOutput(const char* method, int N, unsigned long long F, double time_taken) {
	char file[12];
	strcpy(file, "./_");
	strcat(file, method);
	strcat(file, ".log");
	
	FILE* fq = fopen(file, "a");
	
	// make table data in LaTeX
	if (fq != NULL) {
		fprintf(fq, "\t%d & %llu & %.3f \\\\ \r\n", N, F, time_taken);
	}
	fclose(fq);
	
	
	printf("---------------------------\r\n");
	printf("Method:\t%s\r\n", method);
	printf("N:\t%d\r\n", N);
	printf("f(N):\t%llu\r\n", F);
	printf("Time:\t%.3f\r\n", time_taken);
	printf("---------------------------\r\n");
	
}

int getNumLines(FILE* fp) {
	int n = 0;
	char* line = malloc(80*sizeof(char));
	
	fseek(fp, 0, SEEK_SET);
	while (fgets(line, 80, (FILE*)fp)) {
		n++;
	}
	free(line);
	fseek(fp, 0, SEEK_SET);
	return n;
}

void showUsage(const char* method) {
		printf("\r\n<------USAGE------>\r\n");
		printf("%s <number>\r\n", method);
		exit(1);
}

