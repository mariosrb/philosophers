/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:37:26 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/03/28 10:02:37 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	init_philosophers(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->nb_philos)
	{
		sim->philos[i].id = i + 1;
		sim->philos[i].nb_meals = 0;
		sim->philos[i].last_meal = 0;
		sim->philos[i].left_fork = &sim->forks[i];
		sim->philos[i].right_fork = &sim->forks[(i + 1) % sim->nb_philos];
		sim->philos[i].sim = sim;
		i++;
	}
}

static int	verify_arg(char *arg)
{
	int		i;
	long	value;

	i = 0;
	value = 0;
	if (arg[i] == '+')
		i++;
	if (!arg[i])
		return (ERR_NOT_NUMERIC);
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

static int	init_mutex(t_sim *sim)
{
	int	i;

	if (pthread_mutex_init(&sim->print_mutex, NULL) != 0 ||
		pthread_mutex_init(&sim->death_mutex, NULL) != 0)
		return (-1);
	i = -1;
	while (++i < sim->nb_philos)
		if (pthread_mutex_init(&sim->forks[i], NULL) != 0)
			return (i);
	return (-2);
}

int	init_param_simulation(t_sim *sim, int ac, char **av)
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

int	init_resources(t_sim *sim)
{
	int	mutex_init;

	sim->philos = malloc(sizeof(t_philo) * sim->nb_philos);
	if (!sim->philos)
		return (ERR_MEMORY_ALLOCATION);
	sim->forks = malloc(sizeof(pthread_mutex_t) * sim->nb_philos);
	if (!sim->forks)
	{
		clean_resources(sim, -1);
		return (ERR_MEMORY_ALLOCATION);
	}
	mutex_init = init_mutex(sim);
	if (mutex_init != -2)
	{
		clean_resources(sim, mutex_init);
		return (ERR_MUTEX_INIT);
	}
	init_philosophers(sim);
	return (SUCCES);
}
