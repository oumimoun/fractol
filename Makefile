# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oumimoun <oumimoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 05:28:16 by oumimoun          #+#    #+#              #
#    Updated: 2024/01/30 17:22:15 by oumimoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
HEADER = fractol.h
SRC = fractol.c fractol_utils.c ft_setup_the_env.c ft_the_sets.c ft_mapping.c
OBJ = $(SRC:.c=.o)
MLX = -lmlx -framework OpenGL -framework AppKit
CFLAGS = -g
# CFLAGS = -g

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)
   # clear

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean :
	@rm -f $(OBJ)
	clear

fclean : clean
	@rm -f $(OBJ) $(NAME)
	clear

re : fclean all