/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:43:30 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/07/01 16:43:31 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
long	ft_atol(char *str);
int		get_current_time(void);
int		ft_strcmp(const char *s1, const char *s2);
void	smart_usleep(t_philo *philo, long duration_ms);

#endif
