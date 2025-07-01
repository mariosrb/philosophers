#include "../include/philo.h"

void	sleep_and_think(t_philo *philo)
{
	print_status(philo, "is sleeping");
	smart_usleep(philo, philo->sim->time_to_sleep);
	print_status(philo, "is thinking");
	smart_usleep(philo, 1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *) s1 - *(unsigned char *)s2);
}
