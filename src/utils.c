/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:38:26 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/03/19 15:32:08 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s && fd >= 0)
	{
		write(fd, &*s, 1);
		s++;
	}
}