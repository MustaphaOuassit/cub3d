/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 19:26:54 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/16 18:57:02 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_continue_r(const char *str, char **no_space, size_t i)
{
	int		error;

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
	if (error == 1)
	{
		if ((str[ft_strlen(str) - 1] == ' ') ||
		(str[ft_strlen(str) - 1] == '\t'))
		{
			error = 0;
			g_text_error = "Info invalid in R";
		}
		else
			ft_change_dup();
	}
	return (error);
}

int		ft_check_r(const char *str, char **no_space)
{
	int error;

	if (g_duplicate_r == 0)
		error = ft_continue_r(str, no_space, 0);
	else
	{
		error = 0;
		if (g_get_y == 0)
			g_text_error = "Duplicate the identifier R";
		else
			g_text_error = "Close the map";
	}
	return (error);
}

int		ft_continue_f(char **no_vrg, const char *str, int i)
{
	int error;

	error = ft_continue_vrg_f(no_vrg, i, str);
	if (error == 1)
	{
		if ((str[ft_strlen(str) - 1] == ' ') ||
		(str[ft_strlen(str) - 1] == '\t'))
		{
			error = 0;
			g_text_error = "Info invalid in F";
		}
		else
		{
			g_check_f = 1;
			g_duplicate_f = 1;
			g_all_info = g_all_info + 1;
		}
	}
	return (error);
}

void	ft_write_f(void)
{
	if (g_get_y == 0)
		g_text_error = "Duplicate the identifier F";
	else
		g_text_error = "Close the map";
}

int		ft_check_f(const char *str, char **no_vrg)
{
	int		error;
	size_t	i;

	if (g_duplicate_f == 0)
	{
		i = 0;
		while (i != ft_strlen(str))
		{
			if (!(no_vrg[i]))
			{
				i = i - 1;
				break ;
			}
			i++;
		}
		error = ft_continue_f(no_vrg, str, i);
	}
	else
	{
		error = 0;
		ft_write_f();
	}
	return (error);
}
