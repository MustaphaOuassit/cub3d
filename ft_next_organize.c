/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_organize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:09:57 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/12 15:31:51 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mov(void)
{
	ft_color_window();
	ft_drawing();
}

void	ft_continue_hz(void)
{
	g_found_horizontal = 0;
	g_wall_horizontal_x = 0;
	g_wall_horizontal_y = 0;
	g_closet_one_y = (int)(g_y / g_tile_size) * g_tile_size;
	if (g_is_ray_facing_down == 1)
		g_closet_one_y = g_closet_one_y + g_tile_size;
	else
		g_closet_one_y = g_closet_one_y + 0;
	g_closet_one_x = g_x + ((g_closet_one_y - g_y) / tan(g_ray_angle));
	g_y_step = g_tile_size;
	if (g_is_ray_facing_up == 1)
		g_y_step = g_y_step * -1;
	else
	{
		if (g_is_ray_facing_down == 1)
			g_y_step = g_y_step * 1;
	}
	g_x_step = g_tile_size / tan(g_ray_angle);
	if ((g_is_ray_facing_left == 1) && (g_x_step > 0))
		g_x_step = g_x_step * -1;
	else
		g_x_step = g_x_step * 1;
}

void	ft_horizontal(void)
{
	ft_continue_hz();
	if ((g_is_ray_facing_right == 1) && (g_x_step < 0))
		g_x_step = g_x_step * -1;
	else
		g_x_step = g_x_step * 1;
	g_next_one_x = g_closet_one_x;
	g_next_one_y = g_closet_one_y;
	while ((g_next_one_x >= 0) && (g_next_one_x <= ((g_toll - 1) * g_tile_size))
	&& (g_next_one_y >= 0) && (g_next_one_y <= ((g_get_y - 1) * g_tile_size)))
	{
		if (ft_has_wallat(g_next_one_x, g_next_one_y - g_is_ray_facing_up) == 1)
		{
			g_found_horizontal = 1;
			g_wall_horizontal_x = g_next_one_x;
			g_wall_horizontal_y = g_next_one_y;
			break ;
		}
		else
		{
			g_next_one_x = g_next_one_x + g_x_step;
			g_next_one_y = g_next_one_y + g_y_step;
		}
	}
}

void	ft_continue_vr(void)
{
	if ((g_is_ray_facing_down == 1) && (g_y_step < 0))
		g_y_step = g_y_step * -1;
	else
		g_y_step = g_y_step * 1;
}

void	ft_vertical(void)
{
	g_found_vertical = 0;
	g_wall_vertical_x = 0;
	g_wall_vertical_y = 0;
	g_closet_one_x = (int)(g_x / g_tile_size) * g_tile_size;
	if (g_is_ray_facing_right == 1)
		g_closet_one_x = g_closet_one_x + g_tile_size;
	else
		g_closet_one_x = g_closet_one_x + 0;
	g_closet_one_y = g_y + ((g_closet_one_x - g_x) * tan(g_ray_angle));
	g_x_step = g_tile_size;
	if (g_is_ray_facing_left == 1)
		g_x_step = g_x_step * -1;
	else
	{
		if (g_is_ray_facing_right == 1)
			g_x_step = g_x_step * 1;
	}
	g_y_step = g_tile_size * tan(g_ray_angle);
	if ((g_is_ray_facing_up == 1) && (g_y_step > 0))
		g_y_step = g_y_step * -1;
	else
		g_y_step = g_y_step * 1;
	ft_continue_vr();
}
