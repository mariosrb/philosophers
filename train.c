#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int mails = 0;
int	lock = 0;

void *routine_thread(void *arg)
{
	for (int i = 0; i < 200000; i++)
	{
		if (lock == 1)
		{
			// wait until lock is 0
		}
		lock = 1;
		mails++;
		lock = 0;
	}
	return (NULL);
}

int main(int ac, char **av)
{
	pthread_t p1, p2;
	pthread_create(&p1, NULL, &routine_thread, NULL);
	pthread_create(&p2, NULL, &routine_thread, NULL);
	
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	printf("Number of mails %d\n", mails);
    return (0);
}