#ifndef HELPER_H_
#define HELPER_H_

void setArray(unsigned long long* A, FILE* fp);
void makeOutput(const char* method, int N, unsigned long long F, double time_taken);
int getNumLines(FILE* fp);
void showUsage(const char* method);


#endif
