/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:37:52 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/07/01 16:19:24 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	check_philosopher_death(t_sim *sim, int i)
{
	long	current_time;
	long	time_last_meal;

	current_time = get_current_time();
	pthread_mutex_lock(&sim->death_mutex);
	if (sim->philos[i].last_meal == 0)
		time_last_meal = current_time - sim->start_time;
	else
		time_last_meal = current_time - sim->philos[i].last_meal;
	if (time_last_meal > sim->time_to_die)
	{
		sim->is_runing = 0;
		pthread_mutex_unlock(&sim->death_mutex);
		pthread_mutex_lock(&sim->print_mutex);
		printf("%ld %d %s\n", current_time - sim->start_time,
			sim->philos[i].id, "is dead");
		pthread_mutex_unlock(&sim->print_mutex);
		return (1);
	}
	pthread_mutex_unlock(&sim->death_mutex);
	return (0);
}

static int	check_meals_completed(t_sim *sim, int i)
{
	int	meals_ok;

	pthread_mutex_lock(&sim->death_mutex);
	meals_ok = (sim->nb_must_eat != -1
			&& sim->philos[i].nb_meals >= sim->nb_must_eat);
	pthread_mutex_unlock(&sim->death_mutex);
	return (meals_ok);
}

static int	all_philosophers_ate_enough(t_sim *sim)
{
	int	i;
	int	all_ate;

	if (sim->nb_must_eat == -1)
		return (0);
	all_ate = 1;
	i = 0;
	while (i < sim->nb_philos)
	{
		if (!check_meals_completed(sim, i))
		{
			all_ate = 0;
			break ;
		}
		i++;
	}
	if (all_ate && sim->is_runing)
	{
		pthread_mutex_lock(&sim->death_mutex);
		sim->is_runing = 0;
		pthread_mutex_unlock(&sim->death_mutex);
		return (1);
	}
	return (0);
}

void	*monitor_philosophers(void *arg)
{
	t_sim	*sim;
	int		i;

	sim = (t_sim *)arg;
	while (sim->is_runing)
	{
		i = 0;
		while (i < sim->nb_philos && sim->is_runing)
		{
			if (check_philosopher_death(sim, i))
				return (NULL);
			i++;
		}
		if (all_philosophers_ate_enough(sim))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
