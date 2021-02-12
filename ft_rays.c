/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:48:12 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/12 16:11:27 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_rays(void)
{
	int i;

	i = 0;
	while (i < g_num_rays)
	{
		g_ray_angle = ft_normalaize_angle(g_ray_angle);
		ft_check_ray_face();
		g_wall_x = 0;
		g_wall_y = 0;
		g_distance = 0;
		g_was_vertical = 0;
		ft_cast();
		ft_3d_walls(i);
		g_rays[i].distance = g_distance;
		g_ray_angle = g_ray_angle + (60 * (M_PI / 180) / g_num_rays);
		i++;
	}
}

float	ft_normalaize_angle(float angle)
{
	g_fo_v = 2 * M_PI;
	angle = fmod(angle, g_fo_v);
	if (angle < 0)
		angle = g_fo_v + angle;
	return (angle);
}

void	ft_cast(void)
{
	ft_horizontal();
	ft_vertical();
	ft_distance();
}

void	ft_check_ray_face(void)
{
	if ((g_ray_angle > 0) && (g_ray_angle < M_PI))
	{
		g_is_ray_facing_down = 1;
		g_is_ray_facing_up = 0;
	}
	else
	{
		g_is_ray_facing_down = 0;
		g_is_ray_facing_up = 1;
	}
	if ((g_ray_angle < (0.5 * M_PI)) || (g_ray_angle > (1.5 * M_PI)))
	{
		g_is_ray_facing_right = 1;
		g_is_ray_facing_left = 0;
	}
	else
	{
		g_is_ray_facing_right = 0;
		g_is_ray_facing_left = 1;
	}
}
