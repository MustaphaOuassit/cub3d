/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:57:32 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/10 09:18:13 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_break(char **separ_lines, size_t i, int j, int error)
{
	if ((ft_strlen(separ_lines[j - 1]) <= i)
	|| (ft_strlen(separ_lines[j + 1]) <= i))
		error = 1;
	else
	{
		if (((int)(i - 1) >= 0)
		&& ((int)(i + 1) < (int)(ft_strlen(separ_lines[j]))))
		{
			if ((separ_lines[j][i - 1] == ' ') || (separ_lines[j][i + 1] == ' ')
			|| (separ_lines[j - 1][i] == ' ') || (separ_lines[j + 1][i] == ' '))
				error = 1;
		}
	}
	return (error);
}

int		ft_zero_space(char **separ_lines, size_t i, int j, int error)
{
	while (i != ft_strlen(separ_lines[j]))
	{
		error = ft_zero_two(separ_lines, i, j, error);
		if (error == 1)
			break ;
		error = ft_check_player_map(separ_lines, i, j, error);
		if (error == 1)
			break ;
		error = ft_zero_map(separ_lines, i, j, error);
		if (error == 1)
			break ;
		i++;
	}
	if (error == 0)
		g_map = separ_lines;
	return (error);
}

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int		ft_atoi(const char *str)
{
	unsigned long	nb;
	int				is_negatif;

	nb = 0;
	is_negatif = 1;
	while ((*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r') && (*str != '\0'))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		is_negatif = -1;
		str++;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - 48);
		if (nb > 9223372036854775807)
			return ((is_negatif == -1) ? (0) : (-1));
		str++;
	}
	return (nb * is_negatif);
}
