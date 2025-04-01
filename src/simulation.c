/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:37:52 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/04/01 14:20:59 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// On verifie sil un philo est mort 
static void	*monitor_philosophers(void *arg)
{
	t_sim	*sim;
	int		i;
	int		all_ate;
	long	current_time;

	sim = (t_sim *)arg;
	while (sim->is_runing)
	{
		i = 0;
		all_ate = 1;
		while (i < sim->nb_philos && sim->is_runing)
		{
			current_time = get_current_time();
			pthread_mutex_lock(&sim->death_mutex);
			if (current_time - sim->philos[i].last_meal > sim->time_to_die)
			{
				sim->is_runing = 0;
				pthread_mutex_unlock(&sim->death_mutex);
				pthread_mutex_lock(&sim->print_mutex);
				printf("%ld %d %s\n", current_time - sim->start_time,
					sim->philos[i].id, "is dead");
				pthread_mutex_unlock(&sim->print_mutex);
				return (NULL);
			}
			if (sim->nb_must_eat != -1 && sim->philos[i].nb_meals
				< sim->nb_must_eat)
				all_ate = 0;
			pthread_mutex_unlock(&sim->death_mutex);
			i++;
		}
		if (sim->nb_must_eat != -1 && all_ate && sim->is_runing)
		{
			pthread_mutex_lock(&sim->death_mutex);
			sim->is_runing = 0;
			pthread_mutex_unlock(&sim->death_mutex);
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}

int	start_simulation(t_sim *sim)
{
	int			i;
	pthread_t	monitor;

	sim->start_time = get_current_time();
	sim->is_runing = 1;
	i = 0;
	// Lancement du thread des philosophes
	while (i < sim->nb_philos)
	{
		if (pthread_create(&sim->philos[i].thread, NULL,
			philosopher_routine, &sim->philos[i]) != 0)
		{
			sim->is_runing = 0;
			while (--i >= 0)
				pthread_join(sim->philos[i].thread, NULL);
			return (ERR_THREAD_CREATE);
		}
		i++;
	}
	// Lancement du thread de surveillance
	if (pthread_create(&monitor, NULL, monitor_philosophers, sim) != 0)
	{
		sim->is_runing = 0;
		i = -1;
		while (++i < sim->nb_philos)
			pthread_join(sim->philos[i].thread, NULL);
		return (ERR_THREAD_CREATE);
	}
	i = -1;
	while (++i < sim->nb_philos)
		pthread_join(sim->philos[i].thread, NULL);
	pthread_join(monitor, NULL);
	return (SUCCES);
}
