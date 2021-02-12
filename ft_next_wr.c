/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_wr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:02:36 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/12 12:20:30 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_vrg_f(char **no_vrg,char **no_space, int i, int j)
{
	while (j <= i)
	{
		no_space = ft_split(no_vrg[j], ' ');
		if (j == 0)
		{
			g_r = ft_cnt_r_f(no_space);
			if(g_r == 2)
				g_error = ft_take_color_one_f(no_space);
			else
			{
				g_error = ft_take_color_two_f(no_space);
				break;
			}
			if(g_error == 1)
				ft_take_color_three_f(no_space);
		}
		else
			g_error = ft_cnt_vrg_f(no_space,j);
		if(g_error == 0)
			break;
		j++;
		ft_ptr_ln(no_space);
	}
	return(g_error);
}


int	ft_check_vrg_f(char **no_vrg,size_t i)
{
	int error;
	size_t j;
	char **no_space;

	no_space = NULL;
	j = 0;
	g_r = 0;
	g_error = 0;
	error = ft_vrg_f(no_vrg,no_space,i,j);
		return (error);
}

void	ft_condition_errors_f()
{
	if((g_chose_error == 0) && (g_sec_error == 0))
		g_text_error = "Wrong number of infos in F";
	elsesize_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
	{
		if((g_sec_error == 1) && (g_chose_error == 0))
			g_text_error = "Minimum numbers for one element in F is 1";
		else
			g_text_error = "Info invalid in F";
	}
}

void ft_take_digit_f(char **no_space, int r)
{
	size_t t;

	t = 0;
	while (t != ft_strlen(no_space[r]))
	{
		if(ft_isdigit(no_space[r][t]) == 0)
		{
			g_chose_error = 1;
			break;
		}
		t++;
	}
}

void ft_info_error_f(int j, size_t t, char **no_space)
{
	int r;

	if(j == 0)
	{
		if(t > 2)
			g_sec_error = 1;
		r = 1;
	}
	else
	{
		if(t > 1)
			g_sec_error = 1;
		r = 0;
	}
	while (no_space[r] != '\0')
	{
		t = 0;
		ft_take_digit_f(no_space,r);
		if(g_chose_error == 1)
			break;
		r++;
	}
}
