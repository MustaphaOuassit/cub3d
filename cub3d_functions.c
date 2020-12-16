/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 19:13:43 by mouassit          #+#    #+#             */
/*   Updated: 2020/12/16 10:24:35 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_line_map(const char *str)
{
	int i;
	int error;

	i = 0;
	if ((ft_strlen(str) == 0) && (check == 0))
		error = 1;
	while (i != ft_strlen(str))
	{
		if ((str[i] != ' ') && (str[i] != '0')
				&& (str[i] != '1') && (str[i] != '2'))
		{
			check = 0;
			error = 0;
			break ;
		}
		else
		{
			check = 1;
			error = 1;
		}
		i++;
	}
	if (check == 1)
		error = ft_continue_check(str, error);
	return (error);
}

int		ft_same(char *str, char *stc)
{
	int i;
	int j;

	i = 0;
	j = 1;
	if ((ft_strlen(str) == 1) && (str[0] == 'R'))
		j = 0;
	return (j);
}

int		ft_check_errors(const char *str)
{
	char	**no_space;
	int		i;
	int		j;
	int		error;

	no_space = ft_split(str, ' ');
	i = 0;
	j = 0;
	error = 0;
	if ((str[0] == 'R') && (ft_same(no_space[0], "R") == 0))
	{
		while (i != ft_strlen(str))
		{
			if (!(no_space[i]))
			{
				i = i - 1;
				break ;
			}
			i++;
		}
		error = ft_check_letter(no_space, i);
	}
	else
	{
		error = ft_check_line_map(str, info);
	}
	return (error);
}

int		ft_check_one_on_line(char *firstr, char *endstr)
{
	int error;
	int i;

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

int	ft_check_all_errors(const char *str)
{
	char	**separ_lines;
	int		error;

	error = 0;
	if (ft_check_errors(str) == 1)
	{
		separ_lines = ft_split_n(get, 'c');
		if (get_y > 1)
		{
			if (ft_check_one_on_line(separ_lines[0],
						separ_lines[get_y - 1]) == 0)
				error = ft_continue_line(separ_lines);
			else
				error = 1;
			if (error == 1)
				write(1, "Error\n", 7);
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
