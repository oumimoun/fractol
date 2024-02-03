# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oumimoun <oumimoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 05:28:16 by oumimoun          #+#    #+#              #
#    Updated: 2024/02/02 18:43:55 by oumimoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# VARIABLES

NAME = fractol
CC = cc
HEADER = fractol.h
MLX = -lmlx -framework OpenGL -framework AppKit
CFLAGS	= -Wall -Wextra -Werror

# **************************************************************************** #
# COLORS

GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
END_COLOR	= \033[0;39m

# **************************************************************************** #
# SOURCES

SRC = fractol.c fractol_utils.c ft_setup_the_env.c ft_the_sets.c ft_mapping.c ft_close_win.c ft_parce_args.c
OBJ = $(SRC:.c=.o)

# **************************************************************************** #
# RULES

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled :)$(END_COLOR)"

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $<
	@echo "$(BLUE)Compiling $(notdir $<)$(END_COLOR)"

clean:
	@rm -rf $(OBJ)
	@echo "$(YELLOW)$(NAME) object & dependency files cleaned.$(END_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)$(NAME) executable file cleaned.$(END_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned all and rebuilt $(NAME)!$(END_COLOR)"

# **************************************************************************** #
# PHONY

.PHONY: all clean fclean re