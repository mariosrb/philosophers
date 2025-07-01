/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:01:13 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/07/01 16:37:36 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_sim	sim;
	int		error_code;

	if (ac < 5 || ac > 6)
		return (ft_putstr_fd("Invalid number of arguments! 4 or 5 max.", 2), 1);
	error_code = init_param_simulation(&sim, ac, av);
	if (error_code != SUCCES)
	{
		print_error(error_code);
		return (1);
	}
	error_code = init_resources(&sim);
	if (error_code != SUCCES)
	{
		print_error(error_code);
		return (1);
	}
	error_code = start_simulation(&sim);
	if (error_code != SUCCES)
	{
		print_error(error_code);
		return (clean_resources(&sim, sim.nb_philos), 1);
	}
	clean_resources(&sim, sim.nb_philos);
	return (0);
}
