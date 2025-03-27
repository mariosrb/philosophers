#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

void	*roll_dice()
{
	int value = (rand() % 6) + 1;
	//printf("value %d\n", value);
	return ((void*)&value);
}

int main (int argc, char **argv)
{
	srand(time(NULL));
	pthread_t	th;
	pthread_create(&th, NULL, &roll_dice, NULL);
	pthread_join(th, NULL);

	return (0);
}