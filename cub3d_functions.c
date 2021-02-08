/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 19:13:43 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/08 17:46:09 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_check_player(int c, int error)
{
	if (((c == 'N') || (c == 'S') || (c == 'E')
				|| (c == 'W')) && (g_get_y == 0))
	{
		g_check = 0;
		error = 0;
	}
	else
	{
		g_check = 1;
		error = 1;
	}
	return (error);
}

int		ft_check_get(const char *str, int error)
{
	if (g_check == 1)
		error = ft_continue_check(str, error);
	return (error);
}

int		ft_line_map(const char *str)
{
	size_t	i;
	int		error;

	i = 0;
	error = ft_ctn_line(str);
	while (i != ft_strlen(str))
	{
		if ((str[i] != ' ') && (str[i] != '0')
		&& (str[i] != '1') && (str[i] != '2') && (str[i] != 'N')
		&& (str[i] != 'S') && (str[i] != 'E') && (str[i] != 'W'))
		{
			g_check = 0;
			error = 0;
			break ;
		}
		else
		{
			error = ft_check_player(str[i], error);
			if (error == 0)
				break ;
		}
		i++;
	}
	error = ft_check_get(str, error);
	return (error);
}

int		ft_same(char *str)
{
	int j;

	j = 1;
	if ((str[0] == 'R') || (str[0] == 'S')
		|| (str[0] == 'F') || str[0] == 'C')
		j = 0;
	if (((str[0] == 'N') && (str[1] == 'O'))
	|| ((str[0] == 'S') && (str[1] == 'O'))
	|| ((str[0] == 'W') && (str[1] == 'E'))
	|| ((str[0] == 'E') && (str[1] == 'A')))
		j = 0;
	return (j);
}

int		ft_check_errors(const char *str)
{
	char	**no_space;
	char	**no_vrg;
	int		error;

	no_space = ft_split(str, ' ');
	no_vrg = ft_split(str, ',');
	g_info = 1;
	if (((str[0] == 'R') || (str[0] == 'F')
	|| (str[0] == 'C') || (str[0] == 'S')
	|| (str[0] == 'E') || (str[0] == 'W') || (str[0] == 'N'))
	&& (ft_same(no_space[0]) == 0) && (g_get_y == 0))
		error = ft_check_identifiers(str, no_space, no_vrg);
	else
	{
		g_text_error = "lack the identifier";
		error = ft_check_line_map(str, g_info);
	}
	ft_ptr_ln(no_space);
	ft_ptr_ln(no_vrg);
	return (error);
}
