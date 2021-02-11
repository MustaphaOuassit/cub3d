/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 09:53:48 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/11 19:07:33 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ptr_ln(char **str)
{
	int j;

	j = 0;
	while (str[j] != '\0')
		j++;
	fr_ee(str, j);
}

int		ft_check_y(int y, int wall_strip_height)
{
	int distance_from_top;

	distance_from_top = y + (wall_strip_height / 2) - (g_height_window / 2);
	return (distance_from_top * ((float)g_tile_size / wall_strip_height));
}

void	ft_3d_walls(int x)
{
	float	j;
	float	i;
	float	ray_distance;
	int		result;

	j = 0;
	i = 0;
	ray_distance = g_distance * cos(g_ray_angle - g_rotation_angle);
	g_distance_projection = (g_width_window / 2) / tan(1.0471975512 / 2);
	g_wall_height = (g_tile_size / ray_distance) * g_distance_projection;
	while (i < ((g_height_window / 2) - (g_wall_height / 2)))
	{
		my_mlx_pixel_put(&g_img, x, i, g_color_sky);
		i++;
	}
	i = (g_height_window / 2) - (g_wall_height / 2);
	if (g_was_vertical)
		result = fmod(g_wall_y, g_tile_size);
	else
		result = fmod(g_wall_x, g_tile_size);
	ft_app_colors(i, j, x, result);
}

int		deal_key_release(void)
{
	g_turn_direction = 0;
	g_walk_direction = 0;
	return (0);
}

int		deal_key(int key)
{
	int i;

	i = 0;
	if (key == 13)
		g_walk_direction = 1;
	if (key == 1)
		g_walk_direction = -1;
	if (key == 2)
	{
		g_walk_direction = 1;
		g_b = M_PI / 2;
	}
	if (key == 0)
	{
		g_walk_direction = -1;
		g_b = M_PI / 2;
	}
	if (key == 124)
		g_turn_direction = 1;
	if (key == 123)
		g_turn_direction = -1;
	if (key == 53)
		exit(1);
	ft_mov();
	return (0);
}
