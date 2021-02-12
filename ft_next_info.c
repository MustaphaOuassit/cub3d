/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 09:36:18 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/12 10:03:09 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_continue_ea(const char *str, char **no_space, int i)
{
	int error;

	if ((i == 2) && (str[ft_strlen(str) - 1] != ' '))
	{
		error = 1;
		g_check_ea = 1;
		g_textur_ea = ft_strdup(no_space[1]);
		g_duplicate_ea = 1;
		g_all_info = g_all_info + 1;
	}
	else
	{
		error = 0;
		if (i == 1)
			g_text_error = "Entre the file in EA";
		else
			g_text_error = "Info invalid in EA";
	}
	return (error);
}

int		ft_check_ea(const char *str, char **no_space)
{
	int		error;
	size_t	i;

	if (g_duplicate_ea == 0)
	{
		i = 0;
		while (no_space[i] != '\0')
			i++;
		error = ft_continue_ea(str, no_space, i);
	}
	else
	{
		error = 0;
		if (g_get_y == 0)
			g_text_error = "Duplicate the identifier EA";
		else
			g_text_error = "Close the map";
	}
	return (error);
}

int		ft_continue_we(const char *str, char **no_space, int i)
{
	int error;

	if ((i == 2) && (str[ft_strlen(str) - 1] != ' '))
	{
		error = 1;
		g_check_we = 1;
		g_textur_we = ft_strdup(no_space[1]);
		g_duplicate_we = 1;
		g_all_info = g_all_info + 1;
	}
	else
	{
		error = 0;
		if (i == 1)
			g_text_error = "Entre the file in WE";
		else
			g_text_error = "Info invalid in WE";
	}
	return (error);
}

int		ft_check_we(const char *str, char **no_space)
{
	int		error;
	size_t	i;

	if (g_duplicate_we == 0)
	{
		i = 0;
		while (no_space[i] != '\0')
			i++;
		error = ft_continue_we(str, no_space, i);
	}
	else
	{
		error = 0;
		if (g_get_y == 0)
			g_text_error = "Duplicate the identifier WE";
		else
			g_text_error = "Close the map";
	}
	return (error);
}

int		ft_continue_so(const char *str, char **no_space, int i)
{
	int error;

	if ((i == 2) && (str[ft_strlen(str) - 1] != ' '))
	{
		error = 1;
		g_check_so = 1;
		g_textur_so = ft_strdup(no_space[1]);
		g_g_duplicate_so = 1;
		g_all_info = g_all_info + 1;
	}
	else
	{
		error = 0;
		if (i == 1)
			g_text_error = "Entre the file in SO";
		else
			g_text_error = "Info invalid in SO";
	}
	return (error);
}
