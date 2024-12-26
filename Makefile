NAME = pipex

SRC = main.c

SRC_DIR = src
OBJ_DIR = obj
INCLUDE = include
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
LIBFT = libft/libft.a
CC = cc -Wall -Werror -Wextra -g3 -fsanitize=address,undefined,leak

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C libft/ all

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -I$(INCLUDE) -c $< -o $@

clean:
	$(MAKE) -C libft/ clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C libft/ fclean
	rm -rf $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

re: fclean all