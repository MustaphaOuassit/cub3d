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
		int toll;
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
		int f_r;
		int f_g;
		int f_b;
		int c_r;
		int c_g;
		int c_b;
		char **sky;
		int tile_size;
		float x;
		float y;
		float loop_x;
		float loop_y;
		float new_playerx;
    	float new_playery;
		float rotation_angle;
		float ray_angle;
		int move_step;
		int turn_direction;
		int walk_direction;
		int stock_direction;
		int stock_walk;
		int is_player_change;
		float num_rays;
		float	closet_one_x;
		float	closet_one_y;
		float	next_one_x;
		float	next_one_y;
		float	next_one_v_x;
		float	next_one_v_y;
		int is_ray_facing_down;
		int is_ray_facing_up;
		int is_ray_facing_right;
		int is_ray_facing_left;
		float x_step;
		float y_step;
		int found_horizontal;
		int found_vertical;
		float	wall_horizontal_x;
		float 	wall_horizontal_y;
		float	wall_x;
		float	wall_y;
		float	wall_vertical_x;
		float 	wall_vertical_y;
		int ray_x;
		int ray_y;
		float horizontal_distance;
		float vertical_distance;
		float distance;
		int	was_vertical;
		float ray_distance;
		float wall_height;
		float distance_projection;
		float fo_v;
		void	*textur_one;
		int		*data_one;
		void	*textur_two;
		int		*data_two;
		void	*textur_three;
		int		*data_three;
		void	*textur_four;
		int		*data_four;
		void	*textur_five;
		int		*data_five;
		int		t;
		char	*text_error;
		int check_f;
		int check_c;
		int check_s;
		int check_ea;
		int check_we;
		int check_so;
		int check_no;
		char	*textur_sprite;
		char	*textur_ea;
		char	*textur_we;
		char	*textur_so;
		char	*textur_no;
		int		duplicate_r;
		int		duplicate_no;
		int		duplicate_so;
		int		duplicate_we;
		int		duplicate_ea;
		int		duplicate_s;
		int		duplicate_f;
		int		duplicate_c;
		int		all_info;
		int		duplicate_p;
		int		side_p;
		float		check_direction;
		int		color_floor;
		int		color_sky;
		int 	save;
		float		b;
		int			color_f;
		int			color_c ;
		int g_sprite_height;
		int g_sprite_width;
		typedef struct		s_sprite
		{
		int			x;
		int			y;
		float		distance;
		int			size;
		float		x_offset;
		float 		y_offset;
	}					t_sprite;
	typedef struct s_list
	{
		void *content;
		struct s_list *next;
	} t_list;
	t_list *g_sprite_h;

		typedef struct s_rays
		{
			float distance;
		}t_rays;
		t_rays *g_rays;
	typedef struct  s_data {
		void        *img;
    	char        *addr;
    	int         bits_per_pixel;
    	int         line_length;
    	int         endian;
}               t_data;
t_data img;

typedef	struct		s_header
{
	int				width;
	int				height;
	int				bitcount;
	int				w_in_b;
	int				image_size;
	int				bi_size;
	int				bf_off_bits;
	int				file_size;
	int				bi_planes;
	unsigned	char*	buf;
	int				*data;
	int				row;
	int				col;
}					t_header;

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
		int     ft_zero_space(char **separ_lines, size_t i, int j, int error);
		void	ft_window();
		void	ft_drawing();
		int		ft_atoi(const char *str);
		int		ft_same(char *str);
		void	ft_toll_line();
		float	ft_normalaize_angle(float angle);
		void	ft_cast();
		void	ft_check_ray_face();
		void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
		int		ft_continue_vrg_f(char **no_vrg, size_t i, const char *str);
		int		ft_continue_vrg_c(char **no_vrg, size_t i, const char *str);
		int		ft_extention(char *str);
		int		ft_strcmp(char *s1, const char *s2);
		void	ft_screenshot();
		void ft_sprite_position(int i,int j);
		void	ft_sprite();
		#endif