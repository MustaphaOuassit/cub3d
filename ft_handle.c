/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:38:02 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/12 15:00:33 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_extention(char *str)
{
	int		i;
	int		j;
	int		error;
	char	**dot;

	i = 0;
	j = 0;
	error = 0;
	dot = ft_split(str, '.');
	while (dot[i] != '\0')
		i++;
	if ((i > 0) && (ft_strlen(dot[i - 1]) == 3))
	{
		while (dot[i - 1][j] != '\0')
		{
			error = ft_dot(dot, i, j, error);
			if (error == 1)
				break ;
			j++;
		}
	}
	else
		error = 1;
	ft_ptr_ln(dot);
	return (error);
}

int		ft_strcmp(char *s1, const char *s2)
{
	int x;

	x = 0;
	while (s1[x] == s2[x] && s1[x] != '\0' && s2[x] != '\0')
		x++;
	return (s1[x] - s2[x]);
}

int		ft_zero_two(char **separ_lines, int i, int j, int error)
{
	if ((separ_lines[j][i] == '0') || (separ_lines[j][i] == '2'))
	{
		if (separ_lines[j][i] == '2')
			ft_sprite_position(j, i);
		if (ft_break(separ_lines, i, j, error) == 1)
			error = 1;
	}
	return (error);
}

int		ft_check_player_map(char **separ_lines, int i, int j, int error)
{
	if ((separ_lines[j][i] == 'N') || (separ_lines[j][i] == 'S')
	|| (separ_lines[j][i] == 'E') || (separ_lines[j][i] == 'W'))
	{
		if (g_duplicate_p == 0)
		{
			if (ft_break(separ_lines, i, j, error) == 1)
				error = 1;
			else
			{
				g_duplicate_p = 1;
				g_side_p = separ_lines[j][i];
			}
		}
		else
		{
			error = 1;
			g_text_error = "Duplicate Player in th map";
		}
	}
	return (error);
}

int		ft_zero_map(char **separ_lines, int i, int j, int error)
{
	if (separ_lines[j][i] == ' ')
	{
		if (((int)(i - 1) >= 0)
		&& ((int)(i + 1) < (int)(ft_strlen(separ_lines[j])))
		&& ((int)(i + 1) < (int)(ft_strlen(separ_lines[j + 1])))
		&& ((int)(i + 1) < (int)(ft_strlen(separ_lines[j - 1]))))
		{
			if ((separ_lines[j][i - 1] == '0')
			|| (separ_lines[j][i + 1] == '0')
			|| (separ_lines[j - 1][i] == '0')
			|| (separ_lines[j + 1][i] == '0'))
				error = 1;
		}
	}
	return (error);
}
