/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:01:13 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/03/20 11:33:25 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// int compteur_partage = 0;

// void *incremente(void *arg)
// {
// 	for (int i = 0; i < 500; i++)
// 	{
// 		pthread_mutex_lock(&mutex);
// 		compteur_partage++;
// 		pthread_mutex_unlock(&mutex);
// 	}
// 	return (NULL);
// }

// void	*bonjour(void *arg)
// {
// 	int nombre = *(int *)arg;
// 	printf("Le thread a recu %d\n", nombre);
// 	return (NULL);
// }

int main(int ac, char **av)
{
	// pthread_t	thread1, thread2;
	// int nombre = 42;
	// pthread_create(&thread1, NULL, incremente, NULL);
	// pthread_create(&thread2, NULL, incremente, NULL);
	// pthread_join(thread1, NULL);
	// pthread_join(thread2, NULL);
	// printf("Le thread est termine avec %d\n", compteur_partage);
	
	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////
	
	// 2 400 700 700 5
	
	if (ac < 5 || ac > 6)
	{
		ft_putstr_fd("Invalid number of arguments!\nMust be 4 or 5.", 2);
		return (0);
	}
	t_sim	sim;
	int		error_code;

	error_code = init_param_simulation(&sim, ac, av);
	if (error_code != SUCCES)
	{
		print_error(error_code);
		return (0);
	}
	return (0);
}
