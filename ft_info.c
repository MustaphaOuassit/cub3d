/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 09:23:55 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/12 09:43:38 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_continue_c(char **no_vrg, const char *str, int i)
{
	int	error;

	error = ft_continue_vrg_c(no_vrg, i, str);
	if (error == 1)
	{
		if ((str[ft_strlen(str) - 1] == ' ') || (str[ft_strlen(str) - 1] == '\t'))
		{
			error = 0;
			g_text_error = "Info invalid in C";
		}
		else
		{
			g_check_c = 1;
			g_duplicate_c = 1;
			g_all_info = g_all_info + 1;
		}
	}
	return (error);
}

void	ft_write_c(void)
{
	if (g_get_y == 0)
		g_text_error = "Duplicate the identifier C";
	else
		g_text_error = "Close the map";
}

int		ft_check_c(const char *str, char **no_vrg)
{
	int		error;
	size_t	i;

	if (g_duplicate_c == 0)
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
		error = ft_continue_c(no_vrg, str, i);
	}
	else
	{
		error = 0;
		ft_write_c();
	}
	return (error);
}

int		ft_continue_s(const char *str, char **no_space, int i)
{
	int error;

	if ((i == 2) && (str[ft_strlen(str) - 1] != ' ') && (str[ft_strlen(str) - 1] != '\t'))
	{
		error = 1;
		g_check_s = 1;
		g_textur_sprite = ft_strdup(no_space[1]);
		g_duplicate_s = 1;
		g_all_info = g_all_info + 1;
	}
	else
	{
		error = 0;
		if (i == 1)
			g_text_error = "Entre the file in S";
		else
			g_text_error = "Info invalid in S";
	}
	return (error);
}

int		ft_check_s(const char *str, char **no_space)
{
	int		error;
	size_t	i;

	if (g_duplicate_s == 0)
	{
		i = 0;
		while (no_space[i] != '\0')
			i++;
		error = ft_continue_s(str, no_space, i);
	}
	else
	{
		error = 0;
		if (g_get_y == 0)
			g_text_error = "Duplicate the identifier S";
		else
			g_text_error = "Close the map";
	}
	return (error);
}
