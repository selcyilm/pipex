NAME = pipex
NAMEB = pipex_bonus

SRC = fn_cmd_clean.c  fn_cmds_init.c  fn_env_utils.c  fn_exec_cmd.c \
	fn_exec_pipe.c  fn_matrix_free.c  fn_matrix_print.c  main.c
SRCB = fn_args_parse.c       fn_cmds_parse.c       fn_exec_heredoc.c        fn_pipex_clear_bonus.c \
fn_cmd_clear_bonus.c  fn_env_utils_bonus.c  fn_matrix_free_bonus.c   fn_pipex_init.c \
fn_cmd_new.c          fn_exec_cmd_bonus.c   fn_matrix_print_bonus.c  main_bonus.c

SRCB_DIR = bonus
OBJB_DIR = obj_bonus
SRC_DIR = src
OBJ_DIR = obj
INCLUDE = include
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJB = $(SRCB:%.c=$(OBJB_DIR)/%.o)
LIBFT = libft/libft.a
CC = cc -Wall -Werror -Wextra -g3 -fsanitize=address,undefined,leak

all: $(LIBFT) $(NAME)

bonus: $(LIBFT) $(NAMEB)

$(LIBFT):
	@$(MAKE) -s -C libft/ all

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[32m$@\033[0m is ready."
	@echo "Usage: ./pipex [infile] [cmd1] [cmd2] [outfile]"

$(NAMEB): $(OBJB_DIR) $(OBJB)
	@$(CC) $(OBJB) $(LIBFT) -o $(NAMEB)
	@echo "\033[32m$@\033[0m is ready."
	@echo "Usage: ./pipex_bonus [infile] [cmd1] ... [cmd2] [outfile]"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -I$(INCLUDE) -c $< -o $@
	@echo "$< \033[32mcompiled.\033[0m"

$(OBJB_DIR)/%.o: $(SRCB_DIR)/%.c
	@$(CC) -I$(INCLUDE) -c $< -o $@
	@echo "$< \033[32mcompiled.\033[0m"

clean:
	@$(MAKE) -s -C libft/ clean
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJB_DIR)
	@echo "Object Files Removed!"

fclean: clean
	@$(MAKE) -s -C libft/ fclean
	@rm -rf $(NAME)
	@rm -rf $(NAMEB)
	@echo "Executable File Removed!"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJB_DIR):
	@mkdir -p $(OBJB_DIR)

re: fclean all