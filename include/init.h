/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:43:50 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/07/01 16:43:51 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include <limits.h>

typedef struct s_sim	t_sim;

int	init_param_simulation(t_sim	*sim, int ac, char **av);
int	init_resources(t_sim *sim);

#endif
