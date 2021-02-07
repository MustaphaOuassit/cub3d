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
	if ((ft_strlen(str) == 0) && (g_check == 0))
		error = 1;
	while (i != ft_strlen(str))
	{
		if ((str[i] != ' ') && (str[i] != '0')
				&& (str[i] != '1') && (str[i] != '2') && (str[i] != 'N') && (str[i] != 'S') && (str[i] != 'E') && (str[i] != 'W'))
		{
			g_check = 0;
			error = 0;
			break ;
		}
		else
		{
			if(((str[i] == 'N') || (str[i] == 'S') || (str[i] == 'E') || (str[i] == 'W')) && (g_get_y == 0))
			{
				g_check = 0;
				error = 0;
				break;
			}
			else
			{
				g_check = 1;
				error = 1;	
			}
		}
		i++;
	}
	if (g_check == 1)
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
	g_info = 1;
		if (((str[0] == 'R') || (str[0] == 'F') || (str[0] == 'C') || (str[0] == 'S') || (str[0] == 'E') || (str[0] == 'W') || (str[0] == 'N'))
			&& (ft_same(no_space[0]) == 0) && (g_get_y == 0))
		{
			if(str[0] == 'R')
			{
				if(g_duplicate_r == 0)
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
					if(error == 1)
					{
						if(str[ft_strlen(str) - 1] == ' ')
						{
							error = 0;
							g_text_error = "Info invalid in R";
						}
						else
						{
							g_duplicate_r = 1;
							g_all_info = g_all_info + 1;
						}
					}
				}
				else
				{
					error = 0;
					if(g_get_y == 0)
						g_text_error = "Duplicate the identifier R";
					else
						g_text_error = "Close the map";
				}
			}	
			if(str[0] == 'F')
			{
				if(g_duplicate_f == 0)
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
						if(str[ft_strlen(str) - 1] == ' ')
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
				}
				else
				{
					error = 0;
					if(g_get_y == 0)
						g_text_error = "Duplicate the identifier F";
					else
						g_text_error = "Close the map";
				}
			}
			if(str[0] == 'C')
			{
				if(g_duplicate_c == 0)
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
						if(str[ft_strlen(str) - 1] == ' ')
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
				}
				else
				{
					error = 0;
					if(g_get_y == 0)
						g_text_error = "Duplicate the identifier C";
					else
						g_text_error = "Close the map";	
				}
			}
			if((str[0] == 'S') && (str[1] != 'O'))
			{
				if(g_duplicate_s == 0)
				{
					i = 0;
					while(no_space[i] != '\0')
						i++;
					if((i == 2) && (str[ft_strlen(str) - 1] != ' '))
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
						if(i == 1)
							g_text_error = "Entre the file in S";
						else
							g_text_error = "Info invalid in S";
					}
				}
				else
				{
					error = 0;
					if(g_get_y == 0)
						g_text_error = "Duplicate the identifier S";
					else
						g_text_error = "Close the map";
				}
			}
			if((str[0] == 'E') && (str[1] == 'A'))
			{
				if(g_duplicate_ea == 0)
				{
					i = 0;
					while(no_space[i] != '\0')
					i++;
					if((i == 2) && (str[ft_strlen(str) - 1] != ' '))
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
						if(i == 1)
							g_text_error = "Entre the file in EA";
						else
							g_text_error = "Info invalid in EA";
					}
				}
				else
				{
					error = 0;
					if(g_get_y == 0)
						g_text_error = "Duplicate the identifier EA";
					else
						g_text_error = "Close the map";	
				}
			}
			if((str[0] == 'W') && (str[1] == 'E'))
			{
				if(g_duplicate_we == 0)
				{
					i = 0;
					while(no_space[i] != '\0')
						i++;
					if((i == 2) && (str[ft_strlen(str) - 1] != ' '))
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
						if(i == 1)
							g_text_error = "Entre the file in WE";
						else
							g_text_error = "Info invalid in WE";
					}
				}
				else
				{
					error = 0;
					if(g_get_y == 0)
						g_text_error = "Duplicate the identifier WE";
					else
						g_text_error = "Close the map";	
				}
			}
			if((str[0] == 'S') && (str[1] == 'O'))
			{
				if(g_g_duplicate_so == 0)
				{
					i = 0;
					while(no_space[i] != '\0')
						i++;
					if((i == 2) && (str[ft_strlen(str) - 1] != ' '))
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
						if(i == 1)
							g_text_error = "Entre the file in SO";
						else
							g_text_error = "Info invalid in SO";
					}
				}
				else
				{
					error = 0;
					if(g_get_y == 0)
						g_text_error = "Duplicate the identifier SO";
					else
						g_text_error = "Close the map";
				}
			}
			if((str[0] == 'N') && (str[1] == 'O'))
			{
				if(g_duplicate_no == 0)
				{
					i = 0;
					while(no_space[i] != '\0')
						i++;
					if((i == 2) && (str[ft_strlen(str) - 1] != ' '))
					{
						error = 1;
						g_check_no = 1;
						g_textur_no = ft_strdup(no_space[1]);
						g_duplicate_no = 1;
						g_all_info = g_all_info + 1;
					}
					else
					{
						error = 0;
						if(i == 1)
							g_text_error = "Entre the file in NO";
						else
							g_text_error = "Info invalid in NO";
					}
				}
				else
				{
					error = 0;
					if(g_get_y == 0)
						g_text_error = "Duplicate the identifier NO";
					else
						g_text_error = "Close the map";
				}
			}
		}
		else
		{
			g_text_error = "lack the identifier";
			error = ft_check_line_map(str, g_info);
		}
		ft_ptr_ln(no_space);
		ft_ptr_ln(no_vrg);
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
			break;
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
	char **no_space;
	char **no_vrg;
	int		error;
	size_t i;
	error = 0;
	i = 0;
	if((g_check_f == 1) && (g_check_c == 1) && (g_check_s == 1) && (g_check_ea == 1) && (g_check_we == 1) && (g_check_so == 1) && (g_check_no == 1))
	{
		if (ft_check_errors(str) == 1)
		{
			separ_lines = ft_split_n(g_get, 'c');
			free(g_get);
			if (g_get_y >= 3)
			{
				if (ft_check_one_on_line(separ_lines[0],separ_lines[g_get_y - 1]) == 0)
				{
					error = ft_continue_line(separ_lines);
				}
				else
				{
					error = 1;
					g_text_error = "Close the map";
				}
			}
			else
			{
				error = 1;
				if(g_get_y == 0)
					g_text_error = "Enter the map";
				if((g_get_y != 0) && (g_get_y < 3))
					g_text_error = "Minimum lines of the map is 3";
			}
		}
		else
			error = 1;
	}
	else
	{
		error = 1;
		no_space = ft_split(str, ' ');
		no_vrg = ft_split(str, ',');
		///////////////////////////////////////////////////////////////////////
		if(g_all_info == 7)
		{
				g_text_error = "lack the identifier";
				if (((str[0] == 'R') || (str[0] == 'F') || (str[0] == 'C') || (str[0] == 'S') || (str[0] == 'E') || (str[0] == 'W') || (str[0] == 'N'))
			&& (ft_same(no_space[0]) == 0))
		{
			if(str[0] == 'R')
			{
				if(g_duplicate_r == 0)
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
					if(error == 1)
					{
						g_duplicate_r = 1;
						g_all_info = g_all_info + 1;
					}
				}
				else
				{
					error = 0;
					if(g_get_y == 0)
						g_text_error = "Duplicate the identifier R";
					else
						g_text_error = "Close the map";
				}
			}	
			if(str[0] == 'F')
			{
				if(g_duplicate_f == 0)
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
						g_check_f = 1;
						g_duplicate_f = 1;
						g_all_info = g_all_info + 1;
					}
				}
				else
				{
					error = 0;
					if(g_get_y == 0)
						g_text_error = "Duplicate the identifier F";
					else
						g_text_error = "Close the map";
				}
			}
			if(str[0] == 'C')
			{
				if(g_duplicate_c == 0)
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
						g_check_c = 1;
						g_duplicate_c = 1;
						g_all_info = g_all_info + 1;
					}
				}
				else
				{
					error = 0;
					if(g_get_y == 0)
						g_text_error = "Duplicate the identifier C";
					else
						g_text_error = "Close the map";	
				}
			}
			if((str[0] == 'S') && (str[1] != 'O'))
			{
				if(g_duplicate_s == 0)
				{
					i = 0;
					while(no_space[i] != '\0')
						i++;
					if((i == 2) && (str[ft_strlen(str) - 1] != ' '))
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
						if(i == 1)
							g_text_error = "Entre the file in S";
						else
							g_text_error = "Info invalid in S";
					}
				}
				else
				{
					error = 0;
					if(g_get_y == 0)
						g_text_error = "Duplicate the identifier S";
					else
						g_text_error = "Close the map";
				}
			}
			if((str[0] == 'E') && (str[1] == 'A'))
			{
				if(g_duplicate_ea == 0)
				{
					i = 0;
					while(no_space[i] != '\0')
					i++;
					if((i == 2) && (str[ft_strlen(str) - 1] != ' '))
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
						if(i == 1)
							g_text_error = "Entre the file in EA";
						else
							g_text_error = "Info invalid in EA";
					}
				}
				else
				{
					error = 0;
					if(g_get_y == 0)
						g_text_error = "Duplicate the identifier EA";
					else
						g_text_error = "Close the map";	
				}
			}
			if((str[0] == 'W') && (str[1] == 'E'))
			{
				if(g_duplicate_we == 0)
				{
					i = 0;
					while(no_space[i] != '\0')
						i++;
					if((i == 2) && (str[ft_strlen(str) - 1] != ' '))
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
						if(i == 1)
							g_text_error = "Entre the file in WE";
						else
							g_text_error = "Info invalid in WE";
					}
				}
				else
				{
					error = 0;
					if(g_get_y == 0)
						g_text_error = "Duplicate the identifier WE";
					else
						g_text_error = "Close the map";	
				}
			}
			if((str[0] == 'S') && (str[1] == 'O'))
			{
				if(g_g_duplicate_so == 0)
				{
					i = 0;
					while(no_space[i] != '\0')
						i++;
					if((i == 2) && (str[ft_strlen(str) - 1] != ' '))
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
						if(i == 1)
							g_text_error = "Entre the file in SO";
						else
							g_text_error = "Info invalid in SO";
					}
				}
				else
				{
					error = 0;
					if(g_get_y == 0)
						g_text_error = "Duplicate the identifier SO";
					else
						g_text_error = "Close the map";
				}
			}
			if((str[0] == 'N') && (str[1] == 'O'))
			{
				if(g_duplicate_no == 0)
				{
					i = 0;
					while(no_space[i] != '\0')
						i++;
					if((i == 2) && (str[ft_strlen(str) - 1] != ' '))
					{
						error = 1;
						g_check_no = 1;
						g_textur_no = ft_strdup(no_space[1]);
						g_duplicate_no = 1;
						g_all_info = g_all_info + 1;
					}
					else
					{
						error = 0;
						if(i == 1)
							g_text_error = "Entre the file in NO";
						else
							g_text_error = "Info invalid in NO";
					}
				}
				else
				{
					error = 0;
					if(g_get_y == 0)
						g_text_error = "Duplicate the identifier NO";
					else
						g_text_error = "Close the map";
				}
			}
			if(((g_check_f == 1) || (g_check_c == 1) || (g_check_s == 1) || (g_check_ea == 1) || (g_check_we == 1) || (g_check_so == 1) || (g_check_no == 1)) && (g_get_y == 0))
				g_text_error = "Entre the map";
			else
				g_text_error = "lack the identifier";
		}

	}
	else
		g_text_error = "lack the identifier";
	ft_ptr_ln(no_space);
	ft_ptr_ln(no_vrg);
}
	return(error) ;
}
