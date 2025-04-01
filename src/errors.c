/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:38:37 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/04/01 14:23:47 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_error(int error_code)
{
	if (error_code == ERR_NUM_ARGS)
		ft_putstr_fd("Erreur: nombre d'arguments incorrect\n", 2);
	else if (error_code == ERR_NOT_NUMERIC)
		ft_putstr_fd("Erreur: les arguments doivent être numériques\n", 2);
	else if (error_code == ERR_NEGATIVE_VALUE)
		ft_putstr_fd("Erreur: les valeurs doivent être positives\n", 2);
	else if (error_code == ERR_VALUE_TOO_LARGE)
		ft_putstr_fd("Erreur: les valeurs sont trop grandes\n", 2);
	else if (error_code == ERR_ZERO_PHILOSOPHERS)
		ft_putstr_fd("Erreur: nombre de philosophes ne peut être zéro\n", 2);
	else if (error_code == ERR_MEMORY_ALLOCATION)
		ft_putstr_fd("Erreur : allocation de la mémoire a échoué\n", 2);
	else if (error_code == ERR_MUTEX_INIT)
		ft_putstr_fd("Erreur : initialisation du mutex a échoué\n", 2);
	else if (error_code == ERR_THREAD_CREATE)
		ft_putstr_fd("Erreur : création du thread a échoué\n", 2);
	else if (error_code == ERR_THREAD_JOIN)
		ft_putstr_fd("Erreur : jointure du thread a échoué\n", 2);
}

void	clean_resources(t_sim *sim, int mutex_count)
{
	int	i;

	i = 0;
	if (mutex_count >= 0)
	{
		while (i < mutex_count)
			pthread_mutex_destroy(&sim->forks[i++]);
		pthread_mutex_destroy(&sim->print_mutex);
		pthread_mutex_destroy(&sim->death_mutex);
	}
	if (sim->forks)
		free(sim->forks);
	if (sim->philos)
		free(sim->philos);
}
