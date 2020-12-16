/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:05:40 by mouassit          #+#    #+#             */
/*   Updated: 2020/12/08 17:37:53 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_continue_letter(char **no_space, int i, int j)
{
	int	error;

	error = 0;
	while (i != 3)
	{
		j = 0;
		while (j != ft_strlen(no_space[i]))
		{
			if (ft_isdigit(no_space[i][j]) == 0)
			{
				error = 0;
				break ;
			}
			else
			{
				error = 1;
				info = 1;
			}
			j++;
		}
		if (error == 0)
			break ;
		i++;
	}
	if (error == 1)
	{
		resolution[0] = no_space[1];
		resolution[1] = no_space[2];
	}
	return (error);
}

int		ft_check_letter(char **no_space, int i)
{
	int error;
	int j;

	error = 0;
	j = 0;
	if (i == 2)
	{
		i = 1;
		error = ft_continue_letter(no_space, i, j);
	}
	else
		error = 0;
	return (error);
}

int	ft_continue(const char *str, int error)
{
	if (entre == 1)
	{
		if (error == 0)
		{
			error = ft_check_all_errors(str);
		}
		else
			write(1, "Error\n", 6);
	}
	else
	{
		write(1, "Error\n", 6);
		error = 1;
	}
	return(error) ;
}

int		ft_check_line_map(const char *str, int info)
{
	int error;

	error = 0;
	if ((ft_line_map(str) == 1) && (info == 1))
		error = 1;
	else
		error = 0;
	return (error);
}

int		ft_pirmission(const char *str)
{
	int j;
	int i;

	i = 0;
	j = 1;
	while (i != ft_strlen(str))
	{
		if ((str[i] == '0') || (str[i] == '1') || (str[i] == '2'))
		{
			pirmission = 1;
			j = 0;
			break ;
		}
		i++;
	}
	return (j);
}
