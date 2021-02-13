/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 09:45:33 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/12 10:12:07 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_check_so(const char *str, char **no_space)
{
	int		error;
	size_t	i;

	if (g_g_duplicate_so == 0)
	{
		i = 0;
		while (no_space[i] != '\0')
			i++;
		error = ft_continue_so(str, no_space, i);
	}
	else
	{
		error = 0;
		if (g_get_y == 0)
			g_text_error = "Duplicate the identifier SO";
		else
			g_text_error = "Close the map";
	}
	return (error);
}

int		ft_check_no(const char *str, char **no_space)
{
	int		error;
	size_t	i;

	if (g_duplicate_no == 0)
	{
		i = 0;
		while (no_space[i] != '\0')
			i++;
		if ((i == 2) && (str[ft_strlen(str) - 1] != ' '))
			error = ft_get(no_space);
		else
			error = ft_check_i(i);
	}
	else
	{
		error = 0;
		if (g_get_y == 0)
			g_text_error = "Duplicate the identifier NO";
		else
			g_text_error = "Close the map";
	}
	return (error);
}

int		ft_check_identifiers(const char *str, char **no_space, char **no_vrg)
{
	int error;

	if ((ft_strlen(no_space[0]) == 1) || ((ft_strlen(no_space[0]) == 2)))
	{
		error = ft_r_s_f_c(str, no_space, no_vrg);
		if ((str[0] == 'E') && (str[1] == 'A'))
			error = ft_check_ea(str, no_space);
		if ((str[0] == 'W') && (str[1] == 'E'))
			error = ft_check_we(str, no_space);
		if ((str[0] == 'S') && (str[1] == 'O'))
			error = ft_check_so(str, no_space);
		if ((str[0] == 'N') && (str[1] == 'O'))
			error = ft_check_no(str, no_space);
	}
	else
	{
		error = 0;
		g_text_error = "Invalid Text";
	}
	return (error);
}

int		ft_continue_one(char **separ_lines)
{
	int error;

	if (g_get_y >= 3)
	{
		if (ft_check_one_on_line(separ_lines[0], separ_lines[g_get_y - 1]) == 0)
			error = ft_continue_line(separ_lines);
		else
		{
			error = 1;
			g_text_error = "Close the map";
		}
	}
	else
	{
		error = 1;
		if (g_get_y == 0)
			g_text_error = "Enter the map";
		if ((g_get_y != 0) && (g_get_y < 3))
			g_text_error = "Minimum lines of the map is 3";
	}
	return (error);
}

int		ft_errors_one(const char *str)
{
	int		error;
	char	**separ_lines;

	if (ft_check_errors(str) == 1)
	{
		separ_lines = ft_split_n(g_get, 'c');
		free(g_get);
		error = ft_continue_one(separ_lines);
	}
	else
		error = 1;
	return (error);
}
