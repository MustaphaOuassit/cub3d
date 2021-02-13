/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:40:07 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/13 17:09:16 by mouassit         ###   ########.fr       */
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

int		ft_c_s(const char *str, char **no_space, char **no_vrg, int error)
{
	if (str[0] == 'C')
	{
		if (ft_strlen(no_space[0]) == 1)
			error = ft_check_c(str, no_vrg);
		else
		{
			error = 0;
			g_text_error = "Invalid Text";
		}
	}
	if ((str[0] == 'S') && (str[1] != 'O'))
	{
		if (ft_strlen(no_space[0]) == 1)
			error = ft_check_s(str, no_space);
		else
		{
			error = 0;
			g_text_error = "Invalid Text";
		}
	}
	return (error);
}

int		ft_r_s_f_c(const char *str, char **no_space, char **no_vrg)
{
	int error;

	error = 0;
	if (str[0] == 'R')
	{
		if (ft_strlen(no_space[0]) == 1)
			error = ft_check_r(str, no_space);
		else
		{
			error = 0;
			g_text_error = "Invalid Text";
		}
	}
	if (str[0] == 'F')
	{
		if (ft_strlen(no_space[0]) == 1)
			error = ft_check_f(str, no_vrg);
		else
		{
			error = 0;
			g_text_error = "Invalid Text";
		}
	}
	error = ft_c_s(str, no_space, no_vrg, error);
	return (error);
}
