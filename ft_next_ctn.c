/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_ctn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:23:30 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/12 10:47:56 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_chose_error(int chose_error)
{
	if (chose_error == 0)
		g_text_error = "Minimum numbers for one element in C is 1";
	else
		g_text_error = "Info invalid in C";
}

int		ft_take_color_two(char **no_space)
{
	int		error;
	size_t	t;
	int		r;
	int		chose_error;

	r = 1;
	error = 0;
	while (no_space[r] != '\0')
	{
		t = 0;
		while (t != ft_strlen(no_space[r]))
		{
			if (ft_isdigit(no_space[r][t]) == 0)
			{
				chose_error = 1;
				break ;
			}
			t++;
		}
		if (chose_error == 1)
			break ;
		r++;
	}
	ft_chose_error(chose_error);
	return (error);
}

void	ft_take_color_three(char **no_space)
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
		g_color_c = 1;
	else
		g_c_r = ft_atoi(no_space[1]);
}

int		ft_take_color_four(char **no_space)
{
	size_t	b;
	int		error;

	b = 0;
	while (b != ft_strlen(no_space[0]))
	{
		if (ft_isdigit(no_space[0][b]) == 0)
		{
			g_text_error = "Info invalid in C";
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

int		ft_take_color_five(char **no_space)
{
	int error;
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
	ft_print_error(chose_error);
	return (error);
}
