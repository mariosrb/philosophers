/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:38:37 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/03/19 16:03:48 by mdodevsk         ###   ########.fr       */
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
		ft_putstr_fd("Erreur: le nombre de philosophes ne peut pas être zéro\n", 2);
}