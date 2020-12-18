/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:39:38 by mouassit          #+#    #+#             */
/*   Updated: 2020/12/08 19:40:58 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_add_string(const char *str, int error)
{
	char	*separator;

	separator = ft_strjoin(str, "c");
	get = ft_strjoin(get, separator);
	get_y++;
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
	if ((pirmission == 1) || (r == 1))
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
	size_t i;
	int error;

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
	int	i;
	int	j;
	int	error;

	j = 1;
	error = 0;
	while (j != get_y - 1)
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
			break ;
		j++;
	}
	return (error);
}
