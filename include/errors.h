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

void	print_error(int error_code);

#endif
