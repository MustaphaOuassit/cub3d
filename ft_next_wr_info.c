/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_wr_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:59:29 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/12 12:04:16 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_check_next_vrg(char **no_space, char **no_vrg)
{
	int		error;
	int		j;
	int		r;
	size_t	t;

	error = 0;
	g_sec_error = 0;
	g_chose_error = 0;
	j = 0;
	r = 0;
	t = 0;
	while (no_vrg[j] != '\0')
	{
		no_space = ft_split(no_vrg[j], ' ');
		t = 0;
		while (no_space[t] != '\0')
			t++;
		ft_info_error(j, t, no_space);
		if (g_chose_error == 1)
			break ;
		j++;
		ft_ptr_ln(no_space);
	}
	ft_condition_errors();
	return (error);
}

void	ft_chose_error_f(int chose_error)
{
	if (chose_error == 0)
		g_text_error = "Minimum numbers for one element in F is 1";
	else
		g_text_error = "Info invalid in F";
}

int		ft_take_color_two_f(char **no_space)
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
	ft_chose_error_f(chose_error);
	return (error);
}

int		ft_take_color_one_f(char **no_space)
{
	int		error;
	size_t	b;

	b = 0;
	while (b != ft_strlen(no_space[1]))
	{
		if (ft_isdigit(no_space[1][b]) == 0)
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

int		ft_cnt_r_f(char **no_space)
{
	int r;

	r = 0;
	while (no_space[r] != '\0')
		r++;
	return (r);
}
