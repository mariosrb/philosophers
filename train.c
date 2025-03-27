#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int mails = 0;
pthread_mutex_t	mutex;
// Mutex = protger pour empecher lautre thread de toucher aux variables partages
void *routine_thread(void *arg)
{
	for (int i = 0; i < 200000; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

int main(int ac, char **av)
{
	pthread_t th[4];
	pthread_mutex_init(&mutex, NULL);
	// pthread_create(&p1, NULL, &routine_thread, NULL);
	// pthread_create(&p2, NULL, &routine_thread, NULL);
	int i = 0;
	while (i < 4)
	{
		pthread_create(th + i, NULL, &routine_thread, NULL);
		printf("thread %d has started\n", i);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		pthread_join(th[i], NULL);
		printf("thread %d has finished\n", i);
		i++;
	}
	// pthread_join(p1, NULL);
	// pthread_join(p2, NULL);
	pthread_mutex_destroy(&mutex);
	printf("Number of mails %d\n", mails);
    return (0);
}