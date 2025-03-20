/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:37:26 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/03/20 11:31:18 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	verify_arg(char *arg)
{
	int		i;
	long	value;

	i = 0;
	value = 0;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (ERR_NOT_NUMERIC);
		i++;
	}
	value = ft_atol(arg);
	if (value <= 0)
		return (ERR_NEGATIVE_VALUE);
	if (value > INT_MAX)
		return (ERR_VALUE_TOO_LARGE);
	return (SUCCES);
}

int init_param_simulation(t_sim	*sim, int ac, char **av)
{
	int	i;
	int	error_code;
	
	i = 1;
	while (i < ac)
	{
		error_code = verify_arg(av[i]);
		if (error_code != SUCCES)
			return (error_code);
		i++;
	}
	sim->nb_philos = ft_atoi(av[1]);
	printf("nb_philos: %d\n", sim->nb_philos);
	sim->time_to_die = ft_atol(av[2]);
	printf("time_to_die: %ld\n", sim->time_to_die);
	sim->time_to_eat = ft_atol(av[3]);
	printf("time_to_eat: %ld\n", sim->time_to_eat);
	sim->time_to_sleep = ft_atol(av[4]);
	printf("time_to_sleep: %ld\n", sim->time_to_sleep);
	if (ac == 6)
		sim->nb_must_eat = ft_atoi(av[5]);
	else
		sim->nb_must_eat = -1;
	return (SUCCES);
}

// int init_resources(t_sim *sim)
// {
	
// }