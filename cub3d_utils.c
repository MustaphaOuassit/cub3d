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
int		ft_continue_vrg(char **no_vrg, size_t i)
{
	int	error;
	size_t j;
	size_t b;
	int r;
	size_t t;
	char	**no_space;
	int chose_error;

	error = 0;
	chose_error = 0;
	j = 0;
	b = 0;
	t = 0;
	if(i == 2)
	{
		while (j <= i)
		{
			b = 0;
			no_space = ft_split(no_vrg[j], ' ');
			if (j == 0)
			{
				r = 0;
				while (no_space[r] != '\0')
					r++;
				if(r == 2)
				{
					while (b != ft_strlen(no_space[1]))
					{
						if(ft_isdigit(no_space[1][b]) == 0)
						{
							text_error = "Info invalid in F";
							error = 0;
							break;
						}
						else
						{
							error = 1;
							info = 1;
						}
						if(error == 0)
							break;
						b++;
					}
				}
				else
				{
					error = 0;
					t = 0;
					while (t != ft_strlen(no_space[r - 1]))
					{
						if(ft_isdigit(no_space[r - 1][t]) == 0)
						{
							chose_error = 1;
							break;
						}
						t++;
					}
					if(chose_error == 0)
						text_error = "Maximum numbers for one element in F is 1";
					else
						text_error = "Info invalid in F";
					break;
				}
				if(error == 1)
					flr[j] = no_space[1];
			}
			else
			{
				while (b != ft_strlen(no_space[0]))
				{
					if(ft_isdigit(no_space[0][b]) == 0)
					{
						text_error = "Info invalid in F";
						error = 0;
						break;
					}
					else
					{
						error = 1;
						info = 1;
					}
					if(error == 0)
						break;
					b++;
				}
				if(error == 1)
					flr[j] = no_space[0];
			}
			if(error == 0)
				break;
			j++;
		}
	}
	else
	{
		error = 0;
		j = 0;
		while (j != ft_strlen(no_vrg[i]))
		{
			if(ft_isdigit(no_vrg[i][j]) == 0)
			{
				chose_error = 1;
				break;
			}
			j++;
		}
		if(chose_error == 0)
			text_error = "Maximum info 3 numbers in F";
		else
			text_error = "Info invalid in F";
	}
	return(error);
	/*
	while (i != 3)
	{
		j = 0;
		while (j != ft_strlen(no_vrg[i]))
		{
			if (ft_isdigit(no_vrg[i][j]) == 0)
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
		printf("%s\n",no_vrg[0]);
		printf("%s\n",no_vrg[1]);
		printf("%s\n",no_vrg[2]);
		resolution[0] = no_space[1];
		resolution[1] = no_space[2];
	}*/
}

int		ft_continue_letter(char **no_space, int i, size_t j)
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
				text_error = "Info invalid in R";
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

int		ft_check_vrg(char **no_vrg, int i)
{
	int error;
	int j;

	error = 0;
	j = 0;
	if (i == 2)
	{
		i = 1;
			error = ft_continue_vrg(no_vrg, i);
	}
	else
		error = 0;
	return (error);
}

int		ft_check_letter(char **no_space, int i)
{
	int error;
	size_t j;
	int chose_error;

	error = 0;
	chose_error = 0;
	j = 0;
	if (i == 2)
	{
		i = 1;
		error = ft_continue_letter(no_space, i, j);
	}
	else
	{
		error = 0;
		j = 0;
		while (j != ft_strlen(no_space[i]))
		{
			if(ft_isdigit(no_space[i][j]) == 0)
			{
				chose_error = 1;
				break;
			}
			j++;
		}
		if(chose_error == 0)
			text_error = "Maximum info 2 numbers in R";
		else
			text_error = "Info invalid in R";
	}
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
	}
	else
	{
		text_error = "Empty File.";
		error = 1;
	}
	return(error);
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
	size_t i;

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
