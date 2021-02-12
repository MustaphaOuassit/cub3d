/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:04:03 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/12 10:34:56 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_check_id(const char *str, char **no_space, char **no_vrg)
{
	int error;

	error = 0;
	g_text_error = "lack the identifier";
	if (((str[0] == 'R') || (str[0] == 'F')
		|| (str[0] == 'C') || (str[0] == 'S')
		|| (str[0] == 'E') || (str[0] == 'W')
		|| (str[0] == 'N'))
		&& (ft_same(no_space[0]) == 0))
	{
		error = ft_check_identifiers(str, no_space, no_vrg);
		if (((g_check_f == 1) || (g_check_c == 1)
		|| (g_check_s == 1) || (g_check_ea == 1)
		|| (g_check_we == 1) || (g_check_so == 1)
		|| (g_check_no == 1)) && (g_get_y == 0))
			g_text_error = "Entre the map";
		else
			g_text_error = "lack the identifier";
	}
	return (error);
}

int		ft_check_one_on_line(char *firstr, char *endstr)
{
	int		error;
	size_t	i;

	error = 0;
	i = 0;
	while (i != ft_strlen(firstr))
	{
		if ((firstr[i] != '1') && (firstr[i] != ' '))
		{
			error = 1;
			break ;
		}
		i++;
	}
	if (error == 0)
		error = ft_endstr(endstr);
	return (error);
}

int		ft_check_all_errors(const char *str)
{
	char	**no_space;
	char	**no_vrg;
	int		error;

	if ((g_check_f == 1) && (g_check_c == 1)
			&& (g_check_s == 1) && (g_check_ea == 1)
			&& (g_check_we == 1) && (g_check_so == 1) && (g_check_no == 1))
		error = ft_errors_one(str);
	else
	{
		error = 1;
		no_space = ft_split(str, ' ');
		no_vrg = ft_split(str, ',');
		if (g_all_info == 7)
			error = ft_check_id(str, no_space, no_vrg);
		else
			g_text_error = "lack the identifier";
		ft_ptr_ln(no_space);
		ft_ptr_ln(no_vrg);
	}
	return (error);
}

int		ft_ctn_line(const char *str)
{
	int error;

	error = 0;
	if ((ft_strlen(str) == 0) && (g_check == 0))
		error = 1;
	return (error);
}

int		ft_take_color_one(char **no_space)
{
	int		error;
	size_t	b;

	b = 0;
	while (b != ft_strlen(no_space[1]))
	{
		if (ft_isdigit(no_space[1][b]) == 0)
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
