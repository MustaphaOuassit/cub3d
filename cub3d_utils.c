/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:05:40 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/09 18:20:21 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_continue_vrg_c(char **no_vrg, size_t i, const char *str)
{
	int		error;
	size_t	r;
	char	**no_space;

	error = 0;
	no_space = NULL;
	if (i == 2)
		error = ft_check_vrg(no_vrg, i);
	else
		error = ft_check_next_vrg(no_space, no_vrg);
	if (error == 1)
	{
		i = 0;
		r = 0;
		while (i != ft_strlen(str))
		{
			if (str[i] == ',')
				r++;
			i++;
		}
		error = ft_valid_check(r, error);
	}
	return (error);
}

int		ft_continue_vrg_f(char **no_vrg, size_t i, const char *str)
{
	int		error;
	size_t	r;
	char	**no_space;

	error = 0;
	no_space = NULL;
	if (i == 2)
		error = ft_check_vrg_f(no_vrg, i);
	else
		error = ft_check_next_vrg_f(no_space, no_vrg);
	if (error == 1)
	{
		i = 0;
		r = 0;
		while (i != ft_strlen(str))
		{
			if (str[i] == ',')
				r++;
			i++;
		}
		error = ft_valid_check_f(r, error);
	}
	return (error);
}

int		ft_continue_letter(char **no_space, int i)
{
	int	error;

	error = 0;
	while (i != 3)
	{
		error = ft_letter_r(no_space, i);
		if (error == 0)
			break ;
		i++;
	}
	if (error == 1)
	{
		i = 0;
		while (no_space[1][i] != '\0')
		{
			if (no_space[1][i] != '0')
				break ;
			i++;
		}
		ft_take_informations_r(no_space, i);
	}
	return (error);
}

int		ft_check_letter(char **no_space, int i)
{
	int error;
	int r;

	error = 0;
	g_chose_error = 0;
	r = 0;
	if (i == 2)
	{
		i = 1;
		error = ft_continue_letter(no_space, i);
	}
	else
	{
		r = 1;
		error = 0;
		while (no_space[r] != '\0')
		{
			ft_letter(no_space, r);
			if (g_chose_error == 1)
				break ;
			r++;
		}
		ft_for_r();
	}
	return (error);
}

int		ft_continue(const char *str, int error)
{
	int i;

	i = 0;
	if (g_entre == 1)
	{
		if (error == 0)
		{
			error = ft_check_all_errors(str);
		}
	}
	else
	{
		while (str[i] != '\0')
			i++;
		if (i == 0)
			g_text_error = "Empty File";
		else
			g_text_error = "Invalid File";
		error = 1;
	}
	return (error);
}
