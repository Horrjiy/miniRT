# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/17 16:55:42 by mpoplow           #+#    #+#              #
#    Updated: 2025/04/21 14:49:29 by mpoplow          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= miniRT

CFLAGS		:= -Wall -Wextra -Werror -MMD
EXTRAFLAGS	:= -MP -g -c
# -fsanitize=address -g

LIBMLX		:= ./MLX42
MLXFLAGS    := -ldl -lglfw -pthread -lm

# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#
# 	Directories																	#
# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#

SRC_DIR		:= src
MAIN_DIR	:= $(SRC_DIR)/main
PARS_DIR	:= $(SRC_DIR)/parsing
OBJ_D_DIR	:= O_D_FILES

# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#
# 	FILES																		#
# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#

CFILE_MAIN	:= $(addprefix $(MAIN_DIR)/, main_minirt.c)
CFILES_PARS	:= $(addprefix $(PARS_DIR)/, argvcheck.c argconvert.c)

SRCS	= $(CFILE_MAIN) $(CFILES_PARS)
OFILES	= $(addprefix $(OBJ_D_DIR)/, $(SRCS:.c=.o))
DFILES	= $(addprefix $(OBJ_D_DIR)/, $(SRCS:.c=.d))

# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#
# 	RULES																		#
# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#

all: $(NAME)

$(OBJ_D_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(EXTRAFLAGS) $< -o $@

$(LIBMLX)/.git:
	@echo "\033[1;34mDownloading MLX42...\033[0m"
	@git clone https://github.com/codam-coding-college/MLX42.git MLX42 > /dev/null 2>&1 

$(NAME): $(LIBMLX)/.git $(OFILES)
	@make all -C libft
	@cmake $(LIBMLX) -B $(LIBMLX)/build > /dev/null 2>&1
	@make all -C $(LIBMLX)/build -j4 > /dev/null 2>&1
	@cc $(SRCS) libft/libft.a \
		$(LIBMLX)/build/libmlx42.a $(MLXFLAGS) -I $(LIBMLX)/include -o $(NAME) 
	@echo "\033[1;32mCREATE PROGRAM: miniRT\033[0m"

clean:
	@echo "\033[1;33mCLEAN miniRT\033[0m"
	@make fclean -C libft
	@rm -rf MLX42/build
	@rm -rf $(OBJ_D_DIR);

fclean: clean
	@echo "\033[1;33mREMOVE PROGRAM miniRT\033[0m"
	@rm -f $(NAME)
	@rm -rf ./MLX42
	@echo "\033[1;33mMLX42: delete complete folder\033[0m"

re: clean all

prep: fclean all
	@make clean

.SILENT:  $(OFILES) $(DFILES)
.PHONY: all clean fclean re prep