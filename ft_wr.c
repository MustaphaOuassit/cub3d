/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:08:25 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/12 12:20:10 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_take_color_three_f(char **no_space)
{
	int y;

	y = 0;
	while (no_space[1][y] != '\0')
	{
		if (no_space[1][y] != '0')
			break ;
		y++;
	}
	if ((ft_strlen(no_space[1]) - y) >= 4)
		g_color_f = 1;
	else
		g_f_r = ft_atoi(no_space[1]);
}

int		ft_take_color_four_f(char **no_space)
{
	size_t	b;
	int		error;

	b = 0;
	while (b != ft_strlen(no_space[0]))
	{
		if (ft_isdigit(no_space[0][b]) == 0)
		{
			g_text_error = "Info invalid in F";
			error = 0;
			break ;
		}
		else
		{
			error = 1;
			g_info = 1;
		}
		if (error == 0)
			break ;
		b++;
	}
	return (error);
}

int		ft_take_color_five_f(char **no_space)
{
	int	error;
	int t;
	int chose_error;
	int r;

	error = 0;
	t = 0;
	r = 0;
	chose_error = 0;
	while (no_space[t] != '\0')
	{
		r = 0;
		while (no_space[t][r] != '\0')
		{
			if (ft_isdigit(no_space[t][r]) == 0)
			{
				chose_error = 1;
				break ;
			}
			r++;
		}
		t++;
	}
	ft_error_f(chose_error);
	return (error);
}

void	ft_add_colors_f(char **no_space, int j)
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
			g_color_f = 1;
		else
			g_f_g = ft_atoi(no_space[0]);
	}
	if (j == 2)
	{
		if ((ft_strlen(no_space[0]) - y) >= 4)
			g_color_f = 1;
		else
			g_f_b = ft_atoi(no_space[0]);
	}
}

int		ft_cnt_vrg_f(char **no_space, int j)
{
	int r;
	int error;

	r = 0;
	error = 0;
	while (no_space[r] != '\0')
		r++;
	if (r == 1)
		error = ft_take_color_four_f(no_space);
	else
		error = ft_take_color_five_f(no_space);
	if (error == 1)
		ft_add_colors_f(no_space, j);
	return (error);
}
