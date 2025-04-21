# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 20:46:28 by mpoplow           #+#    #+#              #
#    Updated: 2025/04/02 15:41:44 by mpoplow          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= libft.a
CC 		:= cc
CFLAGS 	:= -Wall -Wextra -Werror

# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#
# 	FILES																		#
# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#

GNL		= $(addprefix $(GNL_DIR)/, get_next_line.c get_next_line_utils.c get_next_text.c )	
PRINTF	= $(addprefix $(PRINTF_DIR)/, ft_pf_putstrchar_sc_perc.c ft_pf_putnbr_di.c ft_pf_putunbr_u.c ft_pf_puthex_lowx.c ft_pf_puthex_capx.c ft_pf_puthexaddress_p.c ft_printf.c )
STRING	= $(addprefix $(STRING_DIR)/, ft_strjoin_free.c ft_strjoin.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_strlen.c ft_strmapi.c ft_striteri.c ft_substr.c ft_strdup.c ft_strstrdup.c)
MEM		= $(addprefix $(MEM_DIR)/, ft_bzero.c ft_calloc.c ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c )
ISX		= $(addprefix $(ISX_DIR)/, ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_toupper.c ft_tolower.c )
PUTX	= $(addprefix $(PUTX_DIR)/, ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c )
CPLX	= $(addprefix $(CPLX_DIR)/, ft_atoi.c ft_split.c ft_itoa.c )

CFILES	= $(STRING) $(GNL) $(PRINTF) $(MEM) $(ISX) $(PUTX) $(CPLX)

OFILES	= $(CFILES:%.c=OandD_FILES_LIBFT/%.o)
DFILES	= $(CFILES:%.c=OandD_FILES_LIBFT/%.d)

# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#
# 	Directories																	#
# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#

GNL_DIR 	:= gnl
PRINTF_DIR 	:= ft_printf
STRING_DIR	:= str_functions
MEM_DIR		:= memory
ISX_DIR		:= is_x
PUTX_DIR	:= put_x
CPLX_DIR	:= complex

# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#
# 	RULES																		#
# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#

all: $(NAME)

OandD_FILES_LIBFT/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -MMD -MP -g -c $< -o $@

$(NAME): $(OFILES)
	@echo "\033[1;32mlibft: create libft.a\033[0m"
	@ar rcs $(NAME) $(OFILES)

clean:
	@echo "\033[1;33mlibft: rm .o files\033[0m"
	@ [ -d OandD_FILES_LIBFT ] && rm -rf OandD_FILES_LIBFT || true

fclean: clean
	@echo "\033[1;33mlibft: remove libft.a\033[0m"
	@rm -f $(NAME)
	

re: fclean all

.SILENT: $(OFILES) $(DFILES)
.PHONY:  all clean fclean re