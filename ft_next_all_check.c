/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_all_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:30:21 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/12 14:41:33 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_valid_check(int r, int error)
{
	if (r == 2)
		error = 1;
	else
		error = ft_else();
	return (error);
}

int		ft_valid_check_f(int r, int error)
{
	if (r == 2)
		error = 1;
	else
		error = ft_else_f();
	return (error);
}

int		ft_check_line_map(const char *str, int info)
{
	int error;

	if ((g_get_y >= 1) && (g_all_info == 8))
		g_text_error = "Close the map";
	else
		g_text_error = "Invalid Text";
	error = 0;
	if ((ft_line_map(str) == 1) && (info == 1))
		error = 1;
	else
	{
		error = 0;
	}
	return (error);
}

int		ft_pirmission(const char *str)
{
	int		j;
	size_t	i;

	i = 0;
	j = 1;
	while (i != ft_strlen(str))
	{
		if ((str[i] == '0') || (str[i] == '1') || (str[i] == '2'))
		{
			g_pirmission = 1;
			j = 0;
			break ;
		}
		i++;
	}
	return (j);
}

int		ft_check_info_draw(char **separ_lines, int j, int error)
{
	int i;

	while (j != g_get_y - 1)
	{
		if (((separ_lines[j][ft_strlen(separ_lines[j]) - 1] == '1')
				|| (separ_lines[j][ft_strlen(separ_lines[j]) - 1] == ' '))
				&& ((separ_lines[j][0] == '1') || (separ_lines[j][0] == ' ')))
		{
			i = 0;
			error = ft_zero_space(separ_lines, i, j, error);
		}
		else
			error = 1;
		if (error == 1)
		{
			if (g_duplicate_p == 0)
				g_text_error = "Close the map";
			break ;
		}
		j++;
	}
	return (error);
}
