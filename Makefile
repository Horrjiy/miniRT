# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/17 16:55:42 by mpoplow           #+#    #+#              #
#    Updated: 2025/04/30 19:25:20 by tleister         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= miniRT

CFLAGS		:= -Wall -Wextra -Werror
CFLAGS		+= -fsanitize=address -g
EXTRAFLAGS	:= -MMD -MP -c

LIBMLX		:= MLX42
MLXFLAGS    := -ldl -lglfw -pthread -lm

# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#
# 	Directories																	#
# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#

SRC_DIR		:= src
MAIN_DIR	:= $(SRC_DIR)/main
PARS_DIR	:= $(SRC_DIR)/parsing
HOOK_DIR	:= $(SRC_DIR)/hooks
VEC_DIR		:= $(SRC_DIR)/vector
RAY_DIR		:= $(SRC_DIR)/ray
OBJ_DIR		:= $(SRC_DIR)/objects
OBJ_D_DIR	:= O_D_FILES

# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#
# 	FILES																		#
# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#

CFILES_MAIN	:= $(addprefix $(MAIN_DIR)/, main_minirt.c error.c free.c ft_init.c)
CFILES_PARS	:= $(addprefix $(PARS_DIR)/, argconvert.c convert.c parsing_utils.c ft_atox.c shapes.c surrounding.c)
CFILES_HOOK	:= $(addprefix $(HOOK_DIR)/, keyfunc.c)
CFILES_VEC	:= $(addprefix $(VEC_DIR)/, vector.c vector2.c vector_norm.c)
CFILES_RAY	:= $(addprefix $(RAY_DIR)/, rt.c lights.c hitpoint.c utils.c solve_quad_eq.c)
CFILES_OBJ	:= $(addprefix $(OBJ_DIR)/, sphere.c plane.c cylinder.c cone.c)

SRCS	= $(CFILES_MAIN) $(CFILES_PARS) $(CFILES_HOOK) $(CFILES_VEC) $(CFILES_RAY) $(CFILES_OBJ)
OFILES	= $(addprefix $(OBJ_D_DIR)/, $(SRCS:.c=.o))
DFILES	= $(addprefix $(OBJ_D_DIR)/, $(SRCS:.c=.d))

# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#
# 	COLOR																		#
# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#

BOLD	:= \033[1m
RED		:= \033[0;31m
GREEN	:= \033[0;32m
YELLOW	:= \033[0;33m
BLUE	:= \033[0;34m
END		:= \033[0m

# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#
# 	RULES																		#
# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#

all: $(NAME) 

$(OBJ_D_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(EXTRAFLAGS) -I$(LIBMLX)/include/MLX42 $< -o $@

$(LIBMLX):
	@echo "$(BLUE)$(BOLD)Downloading $(LIBMLX)...$(END)"
	@git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX) &>/dev/null

$(NAME): $(LIBMLX) $(OFILES)
	@make all -sC libft
	@cmake $(LIBMLX) -B $(LIBMLX)/build &>/dev/null
	@make all -sC $(LIBMLX)/build -j4 &>/dev/null
	@cc $(SRCS) libft/libft.a $(LIBMLX)/build/libmlx42.a $(MLXFLAGS) $(CFLAGS) -I$(LIBMLX)/include/MLX42 -o $(NAME) 
	@echo "$(GREEN)$(BOLD)CREATE PROGRAM: miniRT$(END)"

new:
	@rm -rf $(OBJ_D_DIR)
	@rm -f $(NAME)
	@make
	
clean:
	@echo "$(YELLOW)$(BOLD)CLEAN miniRT$(END)"
	@make fclean -sC libft
	@rm -rf $(LIBMLX)/build
	@rm -rf $(OBJ_D_DIR)

fclean: clean
	@[ -f $(NAME) ] && echo "$(YELLOW)$(BOLD)REMOVE PROGRAM $(NAME)$(END)" || true
	@rm -f $(NAME)
	@[ -d $(LIBMLX) ] && echo "$(YELLOW)$(BOLD)$(LIBMLX): delete complete folder$(END)" || true
	@rm -rf $(LIBMLX)

re: fclean all

prep: fclean all
	@make clean
	@clear

.SILENT:  $(OFILES) $(DFILES)
.PHONY: all clean fclean re prep