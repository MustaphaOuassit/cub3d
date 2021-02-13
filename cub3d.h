/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:03:11 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/13 08:34:01 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

int					g_check;
char				*g_get;
char				**g_map;
int					g_toll;
int					g_get_y;
int					g_width_window;
int					g_height_window;
void				*g_mlx_ptr;
void				*g_win_ptr;
int					g_pirmission;
int					g_info;
int					g_entre;
int					g_f_r;
int					g_f_g;
int					g_f_b;
int					g_c_r;
int					g_c_g;
int					g_c_b;
int					g_tile_size;
float				g_x;
float				g_y;
float				g_new_playerx;
float				g_new_playery;
float				g_rotation_angle;
float				g_ray_angle;
int					g_move_step;
int					g_turn_direction;
int					g_walk_direction;
int					g_stock_direction;
int					g_stock_walk;
float				g_num_rays;
float				g_closet_one_x;
float				g_closet_one_y;
float				g_next_one_x;
float				g_next_one_y;
float				g_next_one_v_x;
float				g_next_one_v_y;
int					g_is_ray_facing_down;
int					g_is_ray_facing_up;
int					g_is_ray_facing_right;
int					g_is_ray_facing_left;
float				g_x_step;
float				g_y_step;
int					g_found_horizontal;
int					g_found_vertical;
float				g_wall_horizontal_x;
float				g_wall_horizontal_y;
float				g_wall_x;
float				g_wall_y;
float				g_wall_vertical_x;
float				g_wall_vertical_y;
float				g_horizontal_distance;
float				g_vertical_distance;
float				g_distance;
int					g_was_vertical;
float				g_wall_height;
float				g_distance_projection;
float				g_fo_v;
void				*g_textur_one;
int					*g_data_one;
void				*g_textur_two;
int					*g_data_two;
void				*g_textur_three;
int					*g_data_three;
void				*g_textur_four;
int					*g_data_four;
void				*g_textur_five;
int					*g_data_five;
int					g_t;
char				*g_text_error;
int					g_check_f;
int					g_check_c;
int					g_check_s;
int					g_check_ea;
int					g_check_we;
int					g_check_so;
int					g_check_no;
char				*g_textur_sprite;
char				*g_textur_ea;
char				*g_textur_we;
char				*g_textur_so;
char				*g_textur_no;
int					g_duplicate_r;
int					g_duplicate_no;
int					g_g_duplicate_so;
int					g_duplicate_we;
int					g_duplicate_ea;
int					g_duplicate_s;
int					g_duplicate_f;
int					g_duplicate_c;
int					g_all_info;
int					g_duplicate_p;
int					g_side_p;
float				g_check_direction;
int					g_color_floor;
int					g_color_sky;
int					g_save;
float				g_b;
int					g_color_f;
int					g_color_c;
int					g_sprite_height;
int					g_sprite_width;
int					g_r;
int					g_error;
int					g_sec_error;
int					g_chose_error;
float				g_dx;
float				g_dy;
double				g_y1;
double				g_x1;
int					g_i;
int					g_j;
typedef struct		s_sprite
{
	int			x;
	int			y;
	float		distance;
	int			size;
	float		x_offset;
	float		y_offset;
}					t_sprite;
typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
t_list	*g_sprite_h;

typedef struct		s_rays
{
	float distance;
}					t_rays;
t_rays	*g_rays;
typedef struct		s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}					t_data;

t_data	g_img;

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

int					get_next_line(int fd, char **line);
char				*ft_strchr(const char*s, int c);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *str);
int					ft_check_errors(const char *str);
int					ft_check_all_errors(const char *str);
char				**ft_split(char const *s, char c);
char				**ft_split_n(char const *s, char c);
int					ft_isdigit(int c);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_check_one_on_line(char *firstr, char *endstr);
int					ft_continue(const char *str, int error);
int					ft_check_letter(char **no_space, int i);
int					ft_check_line_map(const char *str, int info);
int					ft_line_map(const char *str);
int					ft_pirmission(const char *str);
int					ft_continue_check(const char *str, int error);
int					ft_endstr(char *endstr);
int					ft_continue_line(char **separ_lines);
int					ft_zero_space(char **separ_lines
, size_t i, int j, int error);
void				ft_window();
void				ft_drawing();
int					ft_atoi(const char *str);
int					ft_same(char *str);
void				ft_toll_line();
float				ft_normalaize_angle(float angle);
void				ft_cast();
void				ft_check_ray_face();
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
int					ft_continue_vrg_f(char **no_vrg, size_t i, const char *str);
int					ft_continue_vrg_c(char **no_vrg, size_t i, const char *str);
int					ft_extention(char *str);
int					ft_strcmp(char *s1, const char *s2);
void				ft_screenshot();
void				ft_sprite_position(int i, int j);
void				ft_sprite();
void				*fr_ee(char **words, int j);
void				ft_ptr_ln(char **str);
int					ft_check_save(int argc, char *argv[], int error);
void				ft_take_informations(int fd, int error);
void				ft_write_argv(char *argv);
int					ft_check_r(const char *str, char **no_space);
int					ft_check_f(const char *str, char **no_vrg);
int					ft_check_c(const char *str, char **no_vrg);
int					ft_check_s(const char *str, char **no_space);
int					ft_check_ea(const char *str, char **no_space);
int					ft_check_we(const char *str, char **no_space);
int					ft_check_so(const char *str, char **no_space);
int					ft_check_no(const char *str, char **no_space);
int					ft_check_identifiers(const char *str
, char **no_space, char **no_vrg);
int					ft_errors_one(const char *str);
int					ft_check_id(const char *str
, char **no_space, char **no_vrg);
int					ft_check_all_errors(const char *str);
int					ft_check_one_on_line(char *firstr, char *endstr);
int					ft_ctn_line(const char *str);
int					ft_check_vrg(char **no_vrg, size_t i);
int					ft_check_next_vrg(char **no_space, char **no_vrg);
int					ft_else();
int					ft_else_f();
int					ft_check_vrg_f(char **no_vrg, size_t i);
int					ft_check_next_vrg_f(char **no_space, char **no_vrg);
void				ft_letter(char **no_space, int r);
void				ft_for_r();
int					ft_letter_r(char **no_space, int i);
void				ft_take_informations_r(char **no_space, int i);
int					ft_valid_check(int r, int error);
int					ft_valid_check_f(int r, int error);
int					ft_check_line_map(const char *str, int info);
int					ft_pirmission(const char *str);
int					ft_check_info_draw(char **separ_lines, int j, int error);
int					ft_strcmp(char *s1, const char *s2);
int					ft_extention(char *str);
int					ft_zero_two(char **separ_lines, int i, int j, int error);
int					ft_break(char **separ_lines, size_t i, int j, int error);
int					ft_check_player_map(char **separ_lines
, int i, int j, int error);
int					ft_zero_map(char **separ_lines, int i, int j, int error);
void				ft_organize();
int					ft_texturs(int error);
int					ft_colors(int error);
void				ft_put_data();
void				ft_direction_texturs(int i, int x, float result);
int					ft_check_y(int y, int wall_strip_height);
void				ft_app_colors(int i, int j, int x, float result);
void				ft_color_window();
void				ft_mov();
void				ft_horizontal();
int					ft_has_wallat(float i, float j);
void				ft_vertical();
void				ft_distance();
double				ft_between_points(float x1, float y1, float x2, float y2);
void				ft_3d_walls(int x);
int					deal_key_release();
int					deal_key(int key);
float				distance_two_points(float x_one
, float y_one, float x_two, float y_two);
void				*ft_calloc(size_t count, size_t size);
void				ft_error();
void				fill_image(unsigned char *header
, t_header header_info, char *buf);
void				ft_init_header(unsigned char *header
, t_header *info, int i);
void				ft_change_dup();
int					ft_continue_so(const char *str, char **no_space, int i);
int					ft_continue(const char *str, int error);
int					ft_check_i(int i);
int					ft_get(char **no_space);
int					ft_take_color_one(char **no_space);
int					ft_take_color_one_f(char **no_space);
void				ft_take_color_three_f(char **no_space);
void				ft_take_color_three(char **no_space);
int					ft_take_color_two(char **no_space);
int					ft_take_color_five(char **no_space);
int					ft_take_color_four_f(char **no_space);
int					ft_take_color_four(char **no_space);
void				ft_print_error(int chose_error);
void				ft_condition_errors();
void				ft_info_error(int j, size_t t, char **no_space);
int					ft_cnt_r_f(char **no_space);
int					ft_take_color_two_f(char **no_space);
int					ft_cnt_vrg_f(char **no_space, int j);
void				ft_error_f(int chose_error);
void				ft_info_error_f(int j, size_t t, char **no_space);
void				ft_condition_errors_f();
int					ft_dot(char **dot, int i, int j, int error);
int					ft_error_cl(int error);
int					ft_close();
void				ft_ctn_ds();
int					ft_has_wallat_p(float i, float j);
int					ft_has_wallat(float i, float j);
void				ft_draw_player();
void				ft_draw_map();
void				ft_draw_rays();
void				ft_sprite_distance();
void				ft_draw_sprite(t_sprite *sprite, int i, int j);
void				ft_sort_sprites();
void				ft_render_sprites();
int					ft_r_s_f_c(const char *str, char **no_space, char **no_vrg);
#endif
