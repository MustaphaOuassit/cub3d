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
	size_t i;
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

int		ft_same(char *str)
{
	int j;

	j = 1;
	if(ft_strlen(str) == 1)
		if((str[0] == 'R') || (str[0] == 'S') || (str[0] == 'F') || str[0] == 'C')
			j = 0;
		if(ft_strlen(str) == 2)
			if(((str[0] == 'N') && (str[1] == 'O')) || ((str[0] == 'S') && (str[1] == 'O'))
			|| ((str[0] == 'W') && (str[1] == 'E')) || ((str[0] == 'E') && (str[1] == 'A')))
				j = 0;
	return (j);
}

int		ft_check_errors(const char *str)
{
	char	**no_space;
	char	**no_vrg;
	size_t	i;
	int		error;

	no_space = ft_split(str, ' ');
	no_vrg = ft_split(str, ',');
	i = 0;
	error = 0;
	info = 1;
		if (((str[0] == 'R') || (str[0] == 'F') || (str[0] == 'C') || (str[0] == 'S') || (str[0] == 'E') || (str[0] == 'W') || (str[0] == 'N'))
			&& (ft_same(no_space[0]) == 0))
		{
			if(str[0] == 'R')
			{
				if(duplicate_r == 0)
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
					duplicate_r = 1;
				}
				else
				{
					error = 0;
					text_error = "Duplicate the identifier R";
				}
			}	
			if(str[0] == 'F')
			{
				if(duplicate_f == 0)
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
					error =	ft_continue_vrg_f(no_vrg,i,str);
					if(error == 1)
					{
						check_f = 1;
						duplicate_f = 1;
					}
				}
				else
				{
					error = 0;
					text_error = "Duplicate the identifier F";
				}
			}
			if(str[0] == 'C')
			{
				if(duplicate_c == 0)
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
					error =	ft_continue_vrg_c(no_vrg,i,str);
					if(error == 1)
					{
						check_c = 1;
						duplicate_c = 1;
					}
				}
				else
				{
					error = 0;
					text_error = "Duplicate the identifier C";
				}
			}
			if((str[0] == 'S') && (str[1] != 'O'))
			{
				if(duplicate_s == 0)
				{
					i = 0;
					while(no_space[i] != '\0')
						i++;
					if((i == 2) && (str[ft_strlen(str) - 1] != ' '))
					{
						error = 1;
						check_s = 1;
						textur_sprite = ft_strdup(no_space[1]);
						duplicate_s = 1;
					}
					else
					{
						error = 0;
						if(i == 1)
							text_error = "Entre the file in S";
						else
							text_error = "Info invalid in S";
					}
				}
				else
				{
					error = 0;
					text_error = "Duplicate the identifier S";
				}
			}
			if((str[0] == 'E') && (str[1] == 'A'))
			{
				if(duplicate_ea == 0)
				{
					i = 0;
					while(no_space[i] != '\0')
					i++;
					if((i == 2) && (str[ft_strlen(str) - 1] != ' '))
					{
						error = 1;
						check_ea = 1;
						textur_ea = ft_strdup(no_space[1]);
						duplicate_ea = 1;
					}
					else
					{
						error = 0;
						if(i == 1)
							text_error = "Entre the file in EA";
						else
							text_error = "Info invalid in EA";
					}
				}
				else
				{
					error = 0;
					text_error = "Duplicate the identifier EA";
				}
			}
			if((str[0] == 'W') && (str[1] == 'E'))
			{
				if(duplicate_we == 0)
				{
					i = 0;
					while(no_space[i] != '\0')
						i++;
					if((i == 2) && (str[ft_strlen(str) - 1] != ' '))
					{
						error = 1;
						check_we = 1;
						textur_we = ft_strdup(no_space[1]);
						duplicate_we = 1;
					}
					else
					{
						error = 0;
						if(i == 1)
							text_error = "Entre the file in WE";
						else
							text_error = "Info invalid in WE";
					}
				}
				else
				{
					error = 0;
					text_error = "Duplicate the identifier WE";
				}
			}
			if((str[0] == 'S') && (str[1] == 'O'))
			{
				if(duplicate_so == 0)
				{
					i = 0;
					while(no_space[i] != '\0')
						i++;
					if((i == 2) && (str[ft_strlen(str) - 1] != ' '))
					{
						error = 1;
						check_so = 1;
						textur_so = ft_strdup(no_space[1]);
						duplicate_so = 1;
					}
					else
					{
						error = 0;
						if(i == 1)
							text_error = "Entre the file in SO";
						else
							text_error = "Info invalid in SO";
					}
				}
				else
				{
					error = 0;
					text_error = "Duplicate the identifier SO";
				}
			}
			if((str[0] == 'N') && (str[1] == 'O'))
			{
				if(duplicate_no == 0)
				{
					i = 0;
					while(no_space[i] != '\0')
						i++;
					if((i == 2) && (str[ft_strlen(str) - 1] != ' '))
					{
						error = 1;
						check_no = 1;
						textur_no = ft_strdup(no_space[1]);
						duplicate_no = 1;
					}
					else
					{
						error = 0;
						if(i == 1)
							text_error = "Entre the file in NO";
						else
							text_error = "Info invalid in NO";
					}
				}
				else
				{
					error = 0;
					text_error = "Duplicate the identifier NO";
				}
			}
		}
		else
		{
			text_error = "lack the identifier";
			error = ft_check_line_map(str, info);
		}
	return (error);
}

int		ft_check_one_on_line(char *firstr, char *endstr)
{
	int error;
	size_t i;

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
