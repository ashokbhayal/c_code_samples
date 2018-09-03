#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long long sum = 0;

void* sum_runner(void* arg)
{
	long long *limit_ptr = (long long*)arg;
}
int main()
{
  printf("This is the test code\n");

  return 0;
}
