/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:35:42 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/12 10:57:59 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_add_colors(char **no_space, int j)
{
	int y;

	y = 0;
	while (no_space[0][y] != '\0')
	{
		if (no_space[0][y] != '0')
			break ;
		y++;
	}
	if (j == 1)
	{
		if ((ft_strlen(no_space[0]) - y) >= 4)
			g_color_c = 1;
		else
			g_c_g = ft_atoi(no_space[0]);
	}
	if (j == 2)
	{
		if ((ft_strlen(no_space[0]) - y) >= 4)
			g_color_c = 1;
		else
			g_c_b = ft_atoi(no_space[0]);
	}
}

int		ft_cnt_vrg(char **no_space, int j)
{
	int r;
	int error;

	r = 0;
	error = 0;
	while (no_space[r] != '\0')
		r++;
	if (r == 1)
		error = ft_take_color_four(no_space);
	else
		error = ft_take_color_five(no_space);
	if (error == 1)
		ft_add_colors(no_space, j);
	return (error);
}

int		ft_cnt_r(char **no_space)
{
	int r;

	r = 0;
	while (no_space[r] != '\0')
		r++;
	return (r);
}

int		ft_vrg(char **no_vrg, char **no_space, int i, int j)
{
	while (j <= i)
	{
		no_space = ft_split(no_vrg[j], ' ');
		if (j == 0)
		{
			g_r = ft_cnt_r(no_space);
			if (g_r == 2)
				g_error = ft_take_color_one(no_space);
			else
			{
				g_error = ft_take_color_two(no_space);
				break ;
			}
			if (g_error == 1)
				ft_take_color_three(no_space);
		}
		else
			g_error = ft_cnt_vrg(no_space, j);
		if (g_error == 0)
			break ;
		j++;
		ft_ptr_ln(no_space);
	}
	return (g_error);
}

int		ft_check_vrg(char **no_vrg, size_t i)
{
	int		error;
	size_t	j;
	char	**no_space;

	no_space = NULL;
	j = 0;
	g_r = 0;
	g_error = 0;
	error = ft_vrg(no_vrg, no_space, i, j);
	return (error);
}
