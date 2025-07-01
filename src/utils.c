/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:38:26 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/07/01 16:14:17 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s && fd >= 0)
	{
		write(fd, &*s, 1);
		s++;
	}
}

long	ft_atol(char *str)
{
	long	number;
	int		i;
	int		sign;

	i = 0;
	sign = 0;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		number = (number * 10) + str[i] - '0';
		i++;
	}
	if (sign == 1)
		number = number * (-1);
	return (number);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	n;

	i = 0;
	sign = 0;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0' && str[i] != '\0')
	{
		n = (n * 10) + str[i] - '0';
		i++;
	}
	if (sign == 1)
		n = n * (-1);
	return (n);
}

int	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	smart_usleep(t_philo *philo, long duration_ms)
{
	long	start_time;
	long	current_time;
	long	elapsed;

	start_time = get_current_time();
	while (1)
	{
		if (!is_simulation_running(philo))
			break ;
		current_time = get_current_time();
		elapsed = current_time - start_time;
		if (elapsed >= duration_ms)
			break ;
		if (duration_ms - elapsed > 1)
			usleep(1000);
		else
			usleep((duration_ms - elapsed) * 1000);
	}
}
