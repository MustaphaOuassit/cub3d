/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:40:07 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/12 17:34:02 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_player(void)
{
	g_new_playerx = g_x + cos(g_rotation_angle + g_b) *
	(float)g_move_step * ((float)g_walk_direction * 4);
	g_new_playery = g_y + sin(g_rotation_angle + g_b) *
	(float)g_move_step * ((float)g_walk_direction * 4);
	if (ft_has_wallat_p(g_new_playerx, g_new_playery) == 0)
	{
		g_x = g_x + cos(g_rotation_angle + g_b) *
			g_move_step * (g_walk_direction);
		g_y = g_y + sin(g_rotation_angle + g_b) *
			g_move_step * (g_walk_direction);
	}
	g_b = 0;
}
