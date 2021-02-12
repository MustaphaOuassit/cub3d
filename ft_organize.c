/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_organize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:59:00 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/12 15:22:08 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_colors(int error)
{
	if ((g_color_f == 0) && ((g_f_r <= 255) && ((g_f_r >= 0)))
	&& ((g_f_g <= 255) && ((g_f_g >= 0))) && ((g_f_b <= 255)
	&& ((g_f_b >= 0))))
		g_color_floor = g_f_r * 65536 + g_f_g * 256 + g_f_b;
	else
	{
		if (error == 0)
		{
			write(1, "Error\n", 7);
			write(1, "Color no valid in F\n", 20);
			error = 1;
		}
	}
	if ((g_color_c == 0) && ((g_c_r <= 255) && ((g_c_r >= 0)))
	&& ((g_c_g <= 255) && ((g_c_g >= 0)))
	&& ((g_c_b <= 255) && ((g_c_b >= 0))))
		g_color_sky = g_c_r * 65536 + g_c_g * 256 + g_c_b;
	else
		error = ft_error_cl(error);
	return (error);
}

void	ft_put_data(void)
{
	g_data_one = (int *)mlx_get_data_addr(g_textur_four, &g_t, &g_t, &g_t);
	g_data_two = (int *)mlx_get_data_addr(g_textur_two, &g_t, &g_t, &g_t);
	g_data_three = (int *)mlx_get_data_addr(g_textur_one, &g_t, &g_t, &g_t);
	g_data_four = (int *)mlx_get_data_addr(g_textur_three, &g_t, &g_t, &g_t);
	g_data_five = (int *)mlx_get_data_addr(g_textur_five, &g_t, &g_t, &g_t);
	g_x = 0;
	g_y = 0;
	g_num_rays = g_width_window;
	g_rays = malloc((g_num_rays) * sizeof(t_rays));
	g_win_ptr = mlx_new_window(
g_mlx_ptr, g_width_window, g_height_window, "cub3D");
	g_img.img = mlx_new_image(g_mlx_ptr, g_width_window, g_height_window);
	g_img.addr = mlx_get_data_addr(g_img.img, &g_img.bits_per_pixel
, &g_img.line_length, &g_img.endian);
	ft_toll_line();
	ft_drawing();
	if (g_save == 1)
		ft_screenshot();
	else
		mlx_loop(g_mlx_ptr);
}

void	ft_direction_texturs(int i, int x, float result)
{
	int n;

	n = (ft_check_y(i, g_wall_height) * g_tile_size) + result;
	if ((n >= 4096) || (n < 0))
		n = 4095;
	if ((g_was_vertical) && (g_is_ray_facing_left))
		my_mlx_pixel_put(&g_img, x, i, g_data_one[n]);
	if ((g_was_vertical) && (g_is_ray_facing_right))
		my_mlx_pixel_put(&g_img, x, i, g_data_two[n]);
	if ((g_was_vertical == 0) && (g_is_ray_facing_up))
		my_mlx_pixel_put(&g_img, x, i, g_data_three[n]);
	if ((g_was_vertical == 0) && (g_is_ray_facing_down))
		my_mlx_pixel_put(&g_img, x, i, g_data_four[n]);
}

void	ft_app_colors(int i, int j, int x, float result)
{
	while (j < g_wall_height && i < g_height_window)
	{
		if (i > 0)
			ft_direction_texturs(i, x, result);
		i++;
		j++;
	}
	while (i < g_height_window)
	{
		my_mlx_pixel_put(&g_img, x, i, g_color_floor);
		i++;
	}
}

void	ft_color_window(void)
{
	int j;
	int i;

	j = 0;
	i = 0;
	while (j < g_height_window)
	{
		i = 0;
		while (i < g_width_window)
		{
			my_mlx_pixel_put(&g_img, i, j, 0x000000);
			i++;
		}
		j++;
	}
}
