#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>

typedef struct s_sim t_sim;

typedef struct s_philo
{
	int				id;             // Identifiant du philosophe
	int				nb_meals;        // Nombre de repas consommes
	long			last_meal; // Timestamp du dernier repas en millisec
	pthread_t		thread; // Thread associe au philosophe 
	pthread_mutex_t	*left_fork; // Pointeur vers la fourchette (mutex) de gauche
	pthread_mutex_t	*right_fork;// Pointeur vers la fourchette (mutex) de droite
	t_sim			*sim; // Pointeur vers la simulation globales avec tt les paramatres
}	t_philo;

struct s_sim
{
	int				nb_philos; // Nombre de philo
	long			time_to_die;// Delai max sans manger avant de mourir
	long			time_to_eat;// Duree necessaire pour manger
	long			time_to_sleep;// Duree de sommeil apres avoir mange
	int				nb_must_eat;// Nombre max de repas que chacun doit manger
	long			start_time; // Timestamp de debut de simultion
	int				is_runing; // Boleen pour savoir si on continue 
	t_philo			*philos; // Tableau dynamique de philosophes 
	pthread_mutex_t	*forks; // Tableau de mutex rpz les fourchettes
	pthread_mutex_t	print_mutex; // Mutex dedie a la synchronisation des logs daffichage
	pthread_mutex_t	death_mutex; // Mutex pour proteger les acces lies a la mort
};

#endif
