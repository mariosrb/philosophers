#ifndef ROUTINE_H
# define ROUTINE_H

typedef struct s_philo	t_philo;

void	*philosopher_routine(void *arg);
void	sleep_and_think(t_philo *philo);
void	print_status(t_philo *philo, char *mssg);
int		is_simulation_running(t_philo *philo);

#endif
