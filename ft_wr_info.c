/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wr_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:49:46 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/12 11:07:31 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_take_digit(char **no_space, int r)
{
	size_t t;

	t = 0;
	while (t != ft_strlen(no_space[r]))
	{
		if (ft_isdigit(no_space[r][t]) == 0)
		{
			g_chose_error = 1;
			break ;
		}
		t++;
	}
}

void	ft_info_error(int j, size_t t, char **no_space)
{
	int r;

	if (j == 0)
	{
		if (t > 2)
			g_sec_error = 1;
		r = 1;
	}
	else
	{
		if (t > 1)
			g_sec_error = 1;
		r = 0;
	}
	while (no_space[r] != '\0')
	{
		t = 0;
		ft_take_digit(no_space, r);
		if (g_chose_error == 1)
			break ;
		r++;
	}
}

int		ft_else(void)
{
	int error;

	error = 0;
	g_text_error = "just two virgule in C";
	return (error);
}

int		ft_else_f(void)
{
	int error;

	error = 0;
	g_text_error = "just two virgule in F";
	return (error);
}

void	ft_condition_errors(void)
{
	if ((g_chose_error == 0) && (g_sec_error == 0))
		g_text_error = "Wrong number of infos in C";
	else
	{
		if ((g_sec_error == 1) && (g_chose_error == 0))
			g_text_error = "Minimum numbers for one element in C is 1";
		else
			g_text_error = "Info invalid in C";
	}
}
