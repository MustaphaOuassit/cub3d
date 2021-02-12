/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:00:26 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/12 16:24:14 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_map(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (g_map[j])
	{
		i = 0;
		while (g_map[j][i])
		{
			if (((g_map[j][i] == 'N') || (g_map[j][i] == 'S')
			|| (g_map[j][i] == 'E') || (g_map[j][i] == 'W'))
			&& (g_x == 0))
			{
				g_x = (g_tile_size * i) + g_tile_size / 2;
				g_y = (g_tile_size * j) + g_tile_size / 2;
			}
			i++;
		}
		j++;
	}
}

void	ft_drawing(void)
{
	g_rotation_angle = (g_check_direction) + (g_turn_direction +
	g_stock_direction) * 10 * (M_PI / 180);
	g_ray_angle = g_rotation_angle - ((60 * M_PI / 180) / 2);
	g_move_step = 20;
	g_stock_direction = g_turn_direction + g_stock_direction;
	g_stock_walk = g_walk_direction + g_stock_walk;
	ft_draw_map();
	ft_draw_player();
	ft_draw_rays();
	ft_sprite();
	g_move_step = 0;
	mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_img.img, 0, 0);
	mlx_hook(g_win_ptr, 2, 0, &deal_key, &g_img);
	mlx_hook(g_win_ptr, 3, 0, &deal_key_release, &g_img);
	mlx_hook(g_win_ptr, 17, 1L << 17, ft_close, (void *)0);
}

void	ft_window(void)
{
	int error;

	error = 0;
	if (g_side_p)
	{
		ft_organize();
		error = ft_texturs(error);
		error = ft_colors(error);
		if (error == 0)
			ft_put_data();
	}
	else
	{
		if (g_all_info == 8)
		{
			write(1, "Error\n", 7);
			write(1, "No Player in the map\n", 21);
		}
		else
		{
			write(1, "Error\n", 7);
			write(1, "lack the identifier\n", 20);
		}
	}
}

void	ft_sprite_distance(void)
{
	int		x_s;
	int		y_s;
	t_list	*tmp;

	tmp = g_sprite_h;
	while (tmp != NULL)
	{
		x_s = ((t_sprite *)tmp->content)->x;
		y_s = ((t_sprite *)tmp->content)->y;
		((t_sprite *)tmp->content)->distance =
		distance_two_points(g_x, g_y, x_s, y_s);
		tmp = tmp->next;
	}
}

void	ft_sort_sprites(void)
{
	t_list		*new;
	t_list		*temp;
	t_sprite	*inter;

	new = g_sprite_h;
	while (new != NULL)
	{
		temp = new;
		while (temp->next != NULL)
		{
			if (((t_sprite *)temp->content)->distance
			< ((t_sprite *)temp->next->content)->distance)
			{
				inter = (t_sprite *)temp->content;
				temp->content = temp->next->content;
				temp->next->content = (void *)inter;
			}
			temp = temp->next;
		}
		new = new->next;
	}
}
