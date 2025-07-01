/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:42:40 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/07/01 16:42:41 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	create_philosopher_threads(t_sim *sim)
{
	int	i;

	i = 0;
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
	return (SUCCES);
}

static int	create_monitor_thread(t_sim *sim, pthread_t *monitor)
{
	int	i;

	if (pthread_create(monitor, NULL, monitor_philosophers, sim) != 0)
	{
		sim->is_runing = 0;
		i = 0;
		while (i < sim->nb_philos)
		{
			pthread_join(sim->philos[i].thread, NULL);
			i++;
		}
		return (ERR_THREAD_CREATE);
	}
	return (SUCCES);
}

static void	wait_all_threads(t_sim *sim, pthread_t monitor)
{
	int	i;

	i = 0;
	while (i < sim->nb_philos)
	{
		pthread_join(sim->philos[i].thread, NULL);
		i++;
	}
	pthread_join(monitor, NULL);
}

int	start_simulation(t_sim *sim)
{
	pthread_t	monitor;
	int			error_code;

	sim->start_time = get_current_time();
	sim->is_runing = 1;
	error_code = create_philosopher_threads(sim);
	if (error_code != SUCCES)
		return (error_code);
	error_code = create_monitor_thread(sim, &monitor);
	if (error_code != SUCCES)
		return (error_code);
	wait_all_threads(sim, monitor);
	return (SUCCES);
}

// int	start_simulation(t_sim *sim)
// {
// 	int			i;
// 	pthread_t	monitor;

// 	sim->start_time = get_current_time();
// 	sim->is_runing = 1;
// 	i = 0;
// 	while (i < sim->nb_philos)
// 	{
// 		if (pthread_create(&sim->philos[i].thread, NULL,
// 				philosopher_routine, &sim->philos[i]) != 0)
// 		{
// 			sim->is_runing = 0;
// 			while (--i >= 0)
// 				pthread_join(sim->philos[i].thread, NULL);
// 			return (ERR_THREAD_CREATE);
// 		}
// 		i++;
// 	}
// 	if (pthread_create(&monitor, NULL, monitor_philosophers, sim) != 0)
// 	{
// 		sim->is_runing = 0;
// 		i = -1;
// 		while (++i < sim->nb_philos)
// 			pthread_join(sim->philos[i].thread, NULL);
// 		return (ERR_THREAD_CREATE);
// 	}
// 	i = -1;
// 	while (++i < sim->nb_philos)
// 		pthread_join(sim->philos[i].thread, NULL);
// 	pthread_join(monitor, NULL);
// 	return (SUCCES);
// }
