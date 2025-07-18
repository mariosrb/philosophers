/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:43:52 by mdodevsk          #+#    #+#             */
/*   Updated: 2025/07/01 16:43:53 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define SUCCES 0
# define ERR_NUM_ARGS 1
# define ERR_NOT_NUMERIC 2
# define ERR_NEGATIVE_VALUE 3
# define ERR_VALUE_TOO_LARGE 4
# define ERR_ZERO_PHILOSOPHERS 5
# define ERR_MEMORY_ALLOCATION 6
# define ERR_MUTEX_INIT 7
# define ERR_THREAD_CREATE 8
# define ERR_THREAD_JOIN 9

typedef struct s_sim	t_sim;

void	print_error(int error_code);
void	clean_resources(t_sim *sim, int mutex_count);

#endif
