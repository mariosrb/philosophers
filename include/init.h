#ifndef INIT_H
# define INIT_H

# include <limits.h>

typedef struct s_sim	t_sim;

int	init_param_simulation(t_sim	*sim, int ac, char **av);
int	init_resources(t_sim *sim);

#endif
