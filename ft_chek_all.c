/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chek_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:18:21 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/12 14:36:37 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_check_next_vrg_f(char **no_space, char **no_vrg)
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
		ft_info_error_f(j, t, no_space);
		if (g_chose_error == 1)
			break ;
		j++;
		ft_ptr_ln(no_space);
	}
	ft_condition_errors_f();
	return (error);
}

void	ft_letter(char **no_space, int r)
{
	size_t j;

	j = 0;
	while (j != ft_strlen(no_space[r]))
	{
		if (ft_isdigit(no_space[r][j]) == 0)
		{
			g_chose_error = 1;
			break ;
		}
		j++;
	}
}

void	ft_for_r(void)
{
	if (g_chose_error == 0)
		g_text_error = "Wrong number of infos in R";
	else
		g_text_error = "Info invalid in R";
}

int		ft_letter_r(char **no_space, int i)
{
	size_t	j;
	int		error;

	j = 0;
	error = 0;
	while (j != ft_strlen(no_space[i]))
	{
		if (ft_isdigit(no_space[i][j]) == 0)
		{
			error = 0;
			g_text_error = "Info invalid in R";
			break ;
		}
		else
		{
			error = 1;
			g_info = 1;
		}
		j++;
	}
	return (error);
}

void	ft_take_informations_r(char **no_space, int i)
{
	if ((ft_strlen(no_space[1]) - i) >= 5)
		g_width_window = 2560;
	else
		g_width_window = ft_atoi(no_space[1]);
	if ((ft_strlen(no_space[2]) - i) >= 5)
		g_height_window = 1440;
	else
		g_height_window = ft_atoi(no_space[2]);
}
