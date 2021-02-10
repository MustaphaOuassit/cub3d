/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:39:38 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/10 08:39:04 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_add_string(const char *str, int error)
{
	char	*separator;
	char	*pfree;

	separator = ft_strjoin(str, "c");
	pfree = g_get;
	g_get = ft_strjoin(g_get, separator);
	g_get_y++;
	free(pfree);
	free(separator);
	error = 1;
	return (error);
}

int		ft_continue_string(const char *str, int error)
{
	size_t	i;
	int		r;

	i = 0;
	r = 0;
	while (i != ft_strlen(str))
	{
		if (str[i] == ' ')
		{
			r = 1;
			break ;
		}
		i++;
	}
	if ((g_pirmission == 1) || (r == 1))
		error = 0;
	return (error);
}

int		ft_continue_check(const char *str, int error)
{
	if (ft_pirmission(str) == 0)
		error = ft_add_string(str, error);
	else
		error = ft_continue_string(str, error);
	return (error);
}

int		ft_endstr(char *endstr)
{
	size_t	i;
	int		error;

	i = 0;
	error = 0;
	while (i != ft_strlen(endstr))
	{
		if ((endstr[i] != '1') && (endstr[i] != ' '))
		{
			error = 1;
			break ;
		}
		i++;
	}
	return (error);
}

int		ft_continue_line(char **separ_lines)
{
	int	j;
	int	error;

	j = 1;
	error = 0;
	if ((g_check_f == 1) && (g_check_c == 1) && (g_check_s == 1)
	&& (g_check_ea == 1) && (g_check_we == 1)
	&& (g_check_so == 1) && (g_check_no == 1))
		error = ft_check_info_draw(separ_lines, j, error);
	else
	{
		error = 1;
		g_text_error = "lack the identifier";
	}
	return (error);
}
