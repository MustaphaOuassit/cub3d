# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mouassit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/27 13:01:35 by mouassit          #+#    #+#              #
#    Updated: 2020/11/27 13:01:38 by mouassit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

SRC = main.c \
	  get_next_line.c \
	  get_next_line_utils.c \
	  outils.c \
	  cub3d_functions.c \
	  cub3d_utils.c \
	  ft_split_n.c \
	  ft_errors.c \
	  ft_zero_space.c \
	  ft_drawing.c \

all : $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -I /Users/mouassit/Desktop/cub3d $(SRC) -D BUFFER_SIZE=1 -L /Users/mouassit/Desktop/cub3d -lmlx  -framework OpenGL -framework AppKit -lz -o $(NAME)


clean:
	@rm -rf $(OBJECT)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
