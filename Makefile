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

NAME = cub3D

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
	  ft_screenshot.c \
	  ft_sprite.c \
	  ft_next_main.c \
	  ft_cnt_main.c \
	  ft_info.c \
	  ft_next_info.c \
	  ft_check.c \
	  ft_next_check.c \
	  ft_next_ctn.c \
	  ft_ctn.c \
	  ft_wr_info.c \
	  ft_next_wr_info.c \
	  ft_wr.c \
	  ft_next_wr.c \
	  ft_chek_all.c \
	  ft_next_all_check.c \
	  ft_handle.c \
	  ft_next_handle.c \
	  ft_organize.c \
	  ft_next_organize.c \
	  ft_walls.c \
	  ft_next_walls.c \
	  ft_rays.c \
	  ft_next_rays.c \
	  ft_start_sprite.c \
	  ft_next_sprite.c \
	  ft_player.c \

all : $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -g -fsanitize=address -I /Users/mouassit/Desktop/cub3d $(SRC) -D BUFFER_SIZE=1 -L /Users/mouassit/Desktop/cub3d -lmlx  -framework OpenGL -framework AppKit -lz -o $(NAME)


clean:
	@rm -rf $(OBJECT)

fclean: clean
	@rm -rf $(NAME)

re: fclean all