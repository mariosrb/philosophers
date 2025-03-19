NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread

SRCS = src/main.c \
	   src/init.c \
	   src/simulation.c \
	   src/routine.c \
	   src/utils.c \
	   src/errors.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
