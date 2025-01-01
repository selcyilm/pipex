NAME = pipex

SRC = fn_cmd_clean.c  fn_cmds_init.c  fn_env_utils.c  fn_exec_cmd.c  fn_exec_pipe.c  fn_matrix_free.c  fn_matrix_print.c  main.c

SRC_DIR = src
OBJ_DIR = obj
INCLUDE = include
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
LIBFT = libft/libft.a
CC = cc -Wall -Werror -Wextra -g3 -fsanitize=address,undefined,leak

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -s -C libft/ all

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[32m$@\033[0m is ready."
	@echo "Usage: ./pipex [infile] [cmd1] [cmd2] [outfile]"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -I$(INCLUDE) -c $< -o $@
	@echo "$< \033[32mcompiled.\033[0m"

clean:
	@$(MAKE) -s -C libft/ clean
	@rm -rf $(OBJ_DIR)
	@echo "Object Files Removed!"

fclean: clean
	@$(MAKE) -s -C libft/ fclean
	@rm -rf $(NAME)
	@echo "Executable File Removed!"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

re: fclean all