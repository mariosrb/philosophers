/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:37:52 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/03/28 12:58:15 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int start_simulation(t_sim *sim)
{
	int	i;

	sim->start_time = get_current_time();
	sim->is_runing = 1;
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
