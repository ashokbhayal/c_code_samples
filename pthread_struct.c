#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//long long sum = 0;
struct sum
{
	long long limit;
	long long answer;
};

void* sum_runner(void* arg)
{
	struct sum *limit_ptr = (struct sum *)arg;

  long long sum = 0;
	for (int i = 0; i < limit_ptr->limit; i++)
	{
		sum += i;
	}
  limit_ptr->answer = sum;
	pthread_exit(0);
}
int main(int argc, char ** argv)
{
	if(argc <2)
	{
		printf("Usage %s <num>\n", argv[0]);
		exit(-1);
	}

  int num_args = argc - 1;

  struct sum args[num_args];

	pthread_t tid[num_args];

	for(int i = 0; i < num_args; i++)
	{

		args[i].limit = atoll(argv[i+1]);
		pthread_attr_t attr;
		pthread_attr_init(&attr);

		pthread_create(&tid[i], &attr, sum_runner, &args[i]);
	}

	printf("Waiting for the calculation to get over\n");

	for(int i = 0; i < num_args; i++)
	{
		pthread_join(tid[i], NULL);
		printf("The calculated value is %lld\n", args[i].answer);
  }
	printf("Calculation done\n");

	//printf("Sum is %lld\n", sum);

  return 0;
}
