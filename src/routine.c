/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:38:11 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/07/01 16:16:37 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Messages detat des philosophes de facon synchronise
void	print_status(t_philo *philo, char *mssg)
{
	long	timestamp;
	char	*color;
	int		should_print;

	if (ft_strcmp(mssg, "has taken a fork") == 0)
		color = "\033[33m";
	else if (ft_strcmp(mssg, "is eating") == 0)
		color = "\033[32m";
	else if (ft_strcmp(mssg, "is sleeping") == 0)
		color = "\033[34m";
	else if (ft_strcmp(mssg, "is thinking") == 0)
		color = "\033[36m";
	else if (ft_strcmp(mssg, "is dead") == 0)
		color = "\033[31m";
	else
		color = "\033[0m";
	pthread_mutex_lock(&philo->sim->print_mutex);
	timestamp = get_current_time() - philo->sim->start_time;
	pthread_mutex_lock(&philo->sim->death_mutex);
	should_print = philo->sim->is_runing;
	pthread_mutex_unlock(&philo->sim->death_mutex);
	if (should_print)
		printf("%s%ld %d %s\033[0m\n", color, timestamp, philo->id, mssg);
	pthread_mutex_unlock(&philo->sim->print_mutex);
}

// Verifier si la simulation est toujours en cours
int	is_simulation_running(t_philo *philo)
{
	int	running;

	pthread_mutex_lock(&philo->sim->death_mutex);
	running = philo->sim->is_runing;
	pthread_mutex_unlock(&philo->sim->death_mutex);
	return (running);
}

static int	take_forks(t_philo *philo)
{
	if (philo->sim->nb_philos == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		while (is_simulation_running(philo))
			usleep(1000);
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
	}
	return (1);
}

static void	eat(t_philo *philo)
{
	long	current_time;

	current_time = get_current_time();
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->sim->death_mutex);
	philo->last_meal = current_time;
	philo->nb_meals++;
	pthread_mutex_unlock(&philo->sim->death_mutex);
	smart_usleep(philo, philo->sim->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

// Routine principale du philosophe
void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (is_simulation_running(philo))
	{
		if (!take_forks(philo))
			return (NULL);
		eat(philo);
		sleep_and_think(philo);
	}
	return (NULL);
}
