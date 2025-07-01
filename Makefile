NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread

SRC_DIR = src/
OBJ_DIR = obj/

SRCS =	main.c \
		init.c \
		simulation.c simulation2.c \
		routine.c routine_utils.c \
		utils.c \
		errors.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)

all: $(NAME)

# Règle pour créer les fichiers objets
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
