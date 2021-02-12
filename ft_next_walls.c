/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:33:20 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/12 15:59:29 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_line(float x_one, float y_one, float x_zero, float y_zero)
{
	float steps;
	float x_inc;
	float y_inc;
	float i;

	i = 0;
	g_dx = x_one - x_zero;
	g_dy = y_one - y_zero;
	if (fabsf(g_dx) > fabsf(g_dy))
		steps = fabsf(g_dx);
	else
		steps = fabsf(g_dy);
	x_inc = g_dx / steps;
	y_inc = g_dy / steps;
	while (i < steps)
	{
		my_mlx_pixel_put(&g_img, x_zero, y_zero, 0xFF0000);
		x_zero += x_inc;
		y_zero += y_inc;
		i++;
	}
}

int		ft_has_wallat_p(float i, float j)
{
	int		wallat;
	int		position_x;
	int		position_y;

	wallat = 0;
	position_x = (i / g_tile_size);
	position_y = (j / g_tile_size);
	if ((position_y >= g_get_y) ||
	(position_x >= (int)ft_strlen(g_map[position_y])))
		return (1);
	if ((g_map[position_y][position_x] == '1')
			|| (g_map[position_y][position_x] == ' ')
			|| (g_map[position_y][position_x] == '\0'))
		wallat = 1;
	else
		wallat = 0;
	return (wallat);
}

int		ft_has_wallat(float i, float j)
{
	int		wallat;
	int		position_x;
	int		position_y;

	wallat = 0;
	position_x = (i / g_tile_size);
	position_y = (j / g_tile_size);
	if ((position_y >= g_get_y) ||
	(position_x >= (int)ft_strlen(g_map[position_y])))
		return (1);
	if ((g_map[position_y][position_x] == '1') ||
	(g_map[position_y][position_x] == ' ')
	|| (g_map[position_y][position_x] == '\0'))
		wallat = 1;
	else
		wallat = 0;
	return (wallat);
}

void	ft_ray_push(double x2, double y2)
{
	double		xinc;
	double		yinc;
	int			steps;
	int			g_tilecolor;

	g_x1 = g_x;
	g_y1 = g_y;
	g_tilecolor = 16711680;
	steps = abs((int)x2 - (int)g_x1) > abs((int)y2 - (int)y1) ? abs((int)x2 -
			(int)g_x1) : abs((int)y2 - (int)y1);
	xinc = (x2 - g_x1) / (double)steps;
	yinc = (y2 - g_y1) / (double)steps;
	x2 = -1;
	while (++x2 <= steps)
	{
		g_x1 = g_x1 + xinc;
		g_y1 = g_y1 + yinc;
		my_mlx_pixel_put(&g_img, g_x1, g_y1, 0xFF0000);
	}
}

double	ft_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
