/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:43:43 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/07/01 16:43:44 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

typedef struct s_philo	t_philo;

void	*philosopher_routine(void *arg);
void	sleep_and_think(t_philo *philo);
void	print_status(t_philo *philo, char *mssg);
int		is_simulation_running(t_philo *philo);

#endif
