/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:08:50 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/12 16:35:26 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		protect_x(t_sprite *sprite, int i)
{
	int valid;

	valid = 1;
	if (sprite->x_offset + i < 0 ||
			(int)sprite->x_offset + i >= g_num_rays ||
			sprite->distance > g_rays[(int)sprite->x_offset + i].distance)
		valid = 0;
	return (valid);
}

void	ft_draw_sprite(t_sprite *sprite, int i, int j)
{
	int color;

	color = g_data_five[((int)g_sprite_width * (j * \
				(int)g_sprite_height /
				(int)sprite->size)) + (i * (int)g_sprite_width /
				(int)sprite->size)];
	if (color != 0)
		my_mlx_pixel_put(&g_img, sprite->x_offset + i,
sprite->y_offset + j, color);
}

void	ft_start_draw_sprite(t_sprite *sprite)
{
	g_i = 0;
	g_j = 0;
	while (g_i < sprite->size - 1)
	{
		if (!protect_x(sprite, g_i))
		{
			g_i++;
			continue;
		}
		g_j = 0;
		while (g_j < sprite->size - 1)
		{
			if (sprite->y_offset + g_j < 0 ||
					sprite->y_offset + g_j >= g_height_window)
			{
				g_j++;
				continue;
			}
			ft_draw_sprite(sprite, g_i, g_j);
			g_j++;
		}
		g_i++;
	}
}

void	ft_render_sprite(t_sprite *sprite)
{
	float s_angle;

	s_angle = atan2(sprite->y - g_y, sprite->x - g_x);
	while (s_angle - (g_rotation_angle) > M_PI)
		s_angle -= 2 * M_PI;
	while (s_angle - (g_rotation_angle) < -M_PI)
		s_angle += 2 * M_PI;
	s_angle -= g_rotation_angle;
	if (g_height_window > g_width_window)
		sprite->size = (g_height_window / sprite->distance) * g_tile_size;
	else
		sprite->size = (g_width_window / sprite->distance) * g_tile_size;
	sprite->y_offset = (g_height_window / 2) - (sprite->size / 2);
	sprite->x_offset = ((s_angle * g_width_window) / (60 * M_PI / 180)) +
		((g_width_window / 2) - (sprite->size / 2));
	ft_start_draw_sprite(sprite);
}

void	ft_render_sprites(void)
{
	t_list *new;

	new = g_sprite_h;
	while (new)
	{
		ft_render_sprite((t_sprite *)new->content);
		new = new->next;
	}
}
