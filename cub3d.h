/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:03:11 by mouassit          #+#    #+#             */
/*   Updated: 2020/11/27 13:03:14 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

		#ifndef CUB3D_H
		# define CUB3D_H
		# include <stdarg.h>
		# include <unistd.h>
		# include <stdlib.h>
        # include <fcntl.h>
		# include <stdio.h>
		# include <mlx.h>
		# include <math.h>

		
		int check;
		char *get;
		char **map;
		int lenget;
		const char *stock_line;
		int get_y;
		int width_window;
		int height_window;
		void *mlx_ptr;
    	void *win_ptr;
		int pirmission;
		int info;
		int entre;
		char **resolution;
		int tile_size;
		int turn_direction;
		int stock_direction;

	typedef struct  s_data {
		void        *img;
    	char        *addr;
    	int         bits_per_pixel;
    	int         line_length;
    	int         endian;
}               t_data;

		int		get_next_line(int fd, char **line);
        char	*ft_strchr(const char*s, int c);
        char	*ft_strdup(const char *s1);
		size_t	ft_strlen(const char *str);
		int     ft_check_errors(const char *str);
		int     ft_check_all_errors(const char *str);
		char	**ft_split(char const *s, char c);
		char	**ft_split_n(char const *s, char c);
		int		ft_isdigit(int c);
		char	*ft_strjoin(char const *s1, char const *s2);
		int		ft_check_one_on_line(char *firstr, char *endstr);
		int    ft_continue(const char *str, int error);
		int    ft_check_letter(char **no_space, int i);
		int		ft_check_line_map(const char *str, int info);
		int     ft_line_map(const char *str);
		int		ft_pirmission(const char *str);
		int     ft_continue_check(const char *str, int error);
		int     ft_endstr(char *endstr);
		int     ft_continue_line(char **separ_lines);
		int     ft_zero_space(char **separ_lines, int i, int j, int error);
		void	ft_window(char **resolution);
		void	ft_draw(char **resolution, int get_y);
		int		ft_atoi(const char *str);
		#endif