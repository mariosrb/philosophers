/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:38:11 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/03/31 12:09:55 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Fonciton pour afficher les messages detat des philosophes de facon synchronise 
static void	print_status(t_philo *philo, char *mssg)
{
	long	timestamp;

	pthread_mutex_lock(&philo->sim->print_mutex);
	timestamp = get_current_time() - philo->sim->start_time;\
	if (philo->sim->is_runing)
		printf("%ld %d %s\n", timestamp, philo->id, mssg);
	pthread_mutex_unlock(&philo->sim->print_mutex);
}

// Verifier si la simulation est toujours en cours
static int	is_simulation_running(t_philo *philo)
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
	//Mise a jour du timestamp du dernier repas
	pthread_mutex_lock(&philo->sim->death_mutex);
	philo->last_meal = current_time;
	philo->nb_meals++;
	pthread_mutex_unlock(&philo->sim->death_mutex);
	//simuluer le temps de manger
	usleep(philo->sim->time_to_eat * 1000);
	//liberer les fourchettes
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	sleep_and_think(t_philo *philo)
{
	print_status(philo, "is sleeping");
	usleep(philo->sim->time_to_sleep * 1000);
	print_status(philo, "is thinking");
	// test petit delai pour eviter qque le meme philsoophe ne prenne immediatement les fourchettes
	usleep(500);
}

// Routine principale du philosophe
void *philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = get_current_time();
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