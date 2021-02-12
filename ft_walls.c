/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:24:38 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/12 15:44:59 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_continue_ds(void)
{
	if (g_found_horizontal == 1)
		g_horizontal_distance = ft_between_points
(g_x, g_y, g_wall_horizontal_x, g_wall_horizontal_y);
	else
		g_horizontal_distance = INT64_MAX;
	if (g_found_vertical == 1)
		g_vertical_distance = ft_between_points
(g_x, g_y, g_wall_vertical_x, g_wall_vertical_y);
	else
		g_vertical_distance = INT64_MAX;
	if (g_horizontal_distance < g_vertical_distance)
		g_wall_x = g_wall_horizontal_x;
	else
		g_wall_x = g_wall_vertical_x;
	if (g_horizontal_distance < g_vertical_distance)
		g_wall_y = g_wall_horizontal_y;
	else
		g_wall_y = g_wall_vertical_y;
	if (g_horizontal_distance < g_vertical_distance)
		g_distance = g_horizontal_distance;
	else
		g_distance = g_vertical_distance;
	ft_ctn_ds();
}

void	ft_distance(void)
{
	g_next_one_v_x = g_closet_one_x;
	g_next_one_v_y = g_closet_one_y;
	while ((g_next_one_v_x >= 0) && (g_next_one_v_x <=
	((g_toll - 1) * g_tile_size)) && (g_next_one_v_y >= 0)
	&& (g_next_one_v_y <= ((g_get_y - 1) * g_tile_size)))
	{
		if (ft_has_wallat(g_next_one_v_x
	- g_is_ray_facing_left, g_next_one_v_y) == 1)
		{
			g_found_vertical = 1;
			g_wall_vertical_x = g_next_one_v_x;
			g_wall_vertical_y = g_next_one_v_y;
			break ;
		}
		else
		{
			g_next_one_v_x = g_next_one_v_x + g_x_step;
			g_next_one_v_y = g_next_one_v_y + g_y_step;
		}
	}
	ft_continue_ds();
}

int		ft_close(void)
{
	mlx_destroy_window(g_mlx_ptr, g_win_ptr);
	exit(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_toll_line(void)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (i != g_get_y)
	{
		if (ft_strlen(g_map[i]) > len)
			g_toll = ft_strlen(g_map[i]);
		len = ft_strlen(g_map[i]);
		i++;
	}
}
