/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:36:43 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/12 16:43:22 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_get(char **no_space)
{
	int error;

	error = 1;
	g_check_no = 1;
	g_textur_no = ft_strdup(no_space[1]);
	g_duplicate_no = 1;
	g_all_info = g_all_info + 1;
	return (error);
}

void	ft_print_error(int chose_error)
{
	if (chose_error == 1)
		g_text_error = "Info invalid in C";
	else
		g_text_error = "Minimum numbers for one element in C is 1";
}

void	ft_error_f(int chose_error)
{
	if (chose_error == 1)
		g_text_error = "Info invalid in F";
	else
		g_text_error = "Minimum numbers for one element in F is 1";
}

int		ft_dot(char **dot, int i, int j, int error)
{
	if ((dot[i - 1][j] != 'c')
			&& (dot[i - 1][j] != 'u') && (dot[i - 1][j] != 'b'))
	{
		error = 1;
	}
	return (error);
}

void	ft_ctn_ds(void)
{
	if (g_vertical_distance < g_horizontal_distance)
		g_was_vertical = 1;
	else
		g_was_vertical = 0;
}
