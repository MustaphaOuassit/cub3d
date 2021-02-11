/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 19:26:54 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/11 19:26:58 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int	ft_continue_r(const char *str,char **no_space)
{
	int error;
	size_t i;

	i = 0;
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
			ft_change_dup();
	}
	return(error);
}
int	ft_check_r(const char *str,char **no_space)
{
	int error;

	if(g_duplicate_r == 0)
		error = ft_continue_r(str,no_space);
	else
	{
		error = 0;
		if(g_get_y == 0)
		g_text_error = "Duplicate the identifier R";
		else
		g_text_error = "Close the map";
	}
	return(error);
}
int		ft_continue_f(char **no_vrg, const char *str, int i)
{
	int error;

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
	return(error);
}
void	ft_write_f()
{
	if(g_get_y == 0)
		g_text_error = "Duplicate the identifier F";
	else
		g_text_error = "Close the map";
}

int	ft_check_f(const char *str, char **no_vrg)
{
	int error;
	size_t i;
	
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
		error = ft_continue_f(no_vrg,str,i);
	}
	else
	{
		error = 0;
		ft_write_f();
	}
	return(error);
}

int ft_continue_c(char **no_vrg,const char *str,int i)
{
	int error;

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
	return(error);
}
void	ft_write_c()
{
	if(g_get_y == 0)
		g_text_error = "Duplicate the identifier C";
	else
		g_text_error = "Close the map";	
}
int		ft_check_c(const char *str, char **no_vrg)
{
	int error;
	size_t i;

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
		error = ft_continue_c(no_vrg,str,i);
	}
	else
	{
		error = 0;
		ft_write_c();
	}
	return(error);
}

int		ft_continue_s(const char *str, char **no_space, int i)
{
	int error;

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
	return(error);
}

int		ft_check_s(const char *str,char **no_space)
{
	int error;
	size_t i;

	if(g_duplicate_s == 0)
	{
		i = 0;
		while(no_space[i] != '\0')
			i++;
		error = ft_continue_s(str,no_space,i);
	}
	else
	{
		error = 0;
		if(g_get_y == 0)
			g_text_error = "Duplicate the identifier S";
		else
			g_text_error = "Close the map";
	}
	return(error);
}
int ft_continue_ea(const char *str, char **no_space, int i)
{
	int error;

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
	return(error);
}
int 	ft_check_ea(const char *str, char **no_space)
{
	int error;
	size_t i;
	
	if(g_duplicate_ea == 0)
	{
		i = 0;
		while(no_space[i] != '\0')
			i++;
		error = ft_continue_ea(str, no_space,i);
	}
	else
	{
		error = 0;
		if(g_get_y == 0)
			g_text_error = "Duplicate the identifier EA";
		else
			g_text_error = "Close the map";	
	}
	return(error);
}

int		ft_continue_we(const char *str, char **no_space, int i)
{
	int error;

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
	return(error);
}

int		ft_check_we(const char *str, char **no_space)
{
	int error;
	size_t i;
	
	if(g_duplicate_we == 0)
	{
		i = 0;
		while(no_space[i] != '\0')
			i++;
		error = ft_continue_we(str,no_space,i);
	}
	else
	{
		error = 0;
		if(g_get_y == 0)
			g_text_error = "Duplicate the identifier WE";
		else
			g_text_error = "Close the map";	
	}
	return(error);
}

int		ft_continue_so(const char *str, char **no_space, int i)
{
	int error;

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
	return(error);
}

int		ft_check_so(const char *str, char **no_space)
{
	int error;
	size_t i;

	if(g_g_duplicate_so == 0)
	{
		i = 0;
		while(no_space[i] != '\0')
			i++;
		error = ft_continue_so(str,no_space,i);
	}
	else
	{
		error = 0;
		if(g_get_y == 0)
			g_text_error = "Duplicate the identifier SO";
		else
			g_text_error = "Close the map";
	}
	return(error);
}

int		ft_check_no(const char *str, char **no_space)
{
	int error;
	size_t i;
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
	return(error);
}

int		ft_check_identifiers(const char *str, char **no_space, char **no_vrg)
{
	int error;

	if(str[0] == 'R')
		error = ft_check_r(str,no_space);
	if(str[0] == 'F')
		error = ft_check_f(str,no_vrg);
	if(str[0] == 'C')
		error = ft_check_c(str,no_vrg);
	if((str[0] == 'S') && (str[1] != 'O'))
		error = ft_check_s(str,no_space);
	if((str[0] == 'E') && (str[1] == 'A'))
		error = ft_check_ea(str,no_space);
	if((str[0] == 'W') && (str[1] == 'E'))
		error = ft_check_we(str,no_space);
	if((str[0] == 'S') && (str[1] == 'O'))
		error = ft_check_so(str,no_space);
	if((str[0] == 'N') && (str[1] == 'O'))
		error = ft_check_no(str,no_space);
	return(error);
}

int	ft_continue_one(char **separ_lines)
{
	int error;

	if (g_get_y >= 3)
	{
		if (ft_check_one_on_line(separ_lines[0],separ_lines[g_get_y - 1]) == 0)
			error = ft_continue_line(separ_lines);
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
	return(error);
}

int	ft_errors_one(const char *str)
{
	int error;

	char **separ_lines;
	
	if (ft_check_errors(str) == 1)
	{
		separ_lines = ft_split_n(g_get, 'c');
		free(g_get);
		error = ft_continue_one(separ_lines);
	}
	else
		error = 1;
	return(error);
}

int ft_check_id(const char *str, char **no_space, char **no_vrg)
{
	int error;

	error = 0;
	g_text_error = "lack the identifier";
	if (((str[0] == 'R') || (str[0] == 'F') || (str[0] == 'C') || (str[0] == 'S') || (str[0] == 'E') || (str[0] == 'W') || (str[0] == 'N'))
		&& (ft_same(no_space[0]) == 0))
	{
		error = ft_check_identifiers(str,no_space,no_vrg);
			if(((g_check_f == 1) || (g_check_c == 1) || (g_check_s == 1) || (g_check_ea == 1) || (g_check_we == 1) || (g_check_so == 1) || (g_check_no == 1)) && (g_get_y == 0))
				g_text_error = "Entre the map";
			else
				g_text_error = "lack the identifier";
	}
	return(error);
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
	char **no_space;
	char **no_vrg;
	int		error;

	if((g_check_f == 1) && (g_check_c == 1) && (g_check_s == 1) && (g_check_ea == 1) && (g_check_we == 1) && (g_check_so == 1) && (g_check_no == 1))
		error = ft_errors_one(str);
	else
	{
		error = 1;
		no_space = ft_split(str, ' ');
		no_vrg = ft_split(str, ',');
		if(g_all_info == 7)
			error = ft_check_id(str,no_space,no_vrg);
		else
			g_text_error = "lack the identifier";
		ft_ptr_ln(no_space);
		ft_ptr_ln(no_vrg);
	}
	return(error) ;
}

int		ft_ctn_line(const char *str)
{
	int error;

	error = 0;
	if ((ft_strlen(str) == 0) && (g_check == 0))
		error = 1;
	return (error);
}

int	ft_take_color_one(char **no_space)
{
	int error;
	size_t b;

	b = 0;
	while (b != ft_strlen(no_space[1]))
	{
		if(ft_isdigit(no_space[1][b]) == 0)
		{
			g_text_error = "Info invalid in C";
			error = 0;
			break;
		}
		else
		{
			error = 1;
			g_info = 1;
			}
			if(error == 0)
				break;
		b++;
	}
	return(error);
}

void	ft_chose_error(int chose_error)
{
	if(chose_error == 0)
		g_text_error = "Minimum numbers for one element in C is 1";
	else
		g_text_error = "Info invalid in C";
}

int	ft_take_color_two(char **no_space)
{
	int error;
	size_t	t;
	int r;
	int chose_error;
	
	r = 1;
	error = 0;
	while (no_space[r] != '\0')
	{
		t = 0;
		while (t != ft_strlen(no_space[r]))
		{
			if(ft_isdigit(no_space[r][t]) == 0)
			{
				chose_error = 1;
				break;
			}
			t++;
		}
		if(chose_error == 1)
			break;
		r++;
	}

	ft_chose_error(chose_error);
	return(error);
}

void ft_take_color_three(char **no_space)
{
	int y;

	y = 0;
	while (no_space[1][y] != '\0')
	{
		if(no_space[1][y] != '0')
			break;
		y++;
	}
	if((ft_strlen(no_space[1]) - y) >= 4)
		g_color_c = 1;
	else
		g_c_r = ft_atoi(no_space[1]);
}

int	ft_take_color_four(char **no_space)
{
	size_t b;
	int error;

	b = 0;
	while (b != ft_strlen(no_space[0]))
	{
		if(ft_isdigit(no_space[0][b]) == 0)
		{
			g_text_error = "Info invalid in C";
			error = 0;
			break;
		}
		else
		{
			error = 1;
			g_info = 1;
		}
		if(error == 0)
			break;
		b++;
	}
	return(error);
}

int	ft_take_color_five(char **no_space)
{
	int error;
	int t;
	int chose_error;
	int r;

	error = 0;
	t = 0;
	r = 0;
	chose_error = 0;
	while (no_space[t] != '\0')
	{
		r = 0;
		while (no_space[t][r] != '\0')
		{
			if(ft_isdigit(no_space[t][r]) == 0)
			{
				chose_error = 1;
				break;
			}
			r++;
		}
		t++;
	}
	if(chose_error == 1)
		g_text_error = "Info invalid in C";
	else
		g_text_error = "Minimum numbers for one element in C is 1";
	return(error);
}

void	ft_add_colors(char **no_space, int j)
{
	int y;

	y = 0;
	while (no_space[0][y] != '\0')
	{
		if(no_space[0][y] != '0')
			break;
		y++;
	}
	if(j == 1)
	{
		if((ft_strlen(no_space[0]) - y) >= 4)
			g_color_c = 1;
		else
			g_c_g = ft_atoi(no_space[0]);
	}
	if(j == 2)
	{
		if((ft_strlen(no_space[0]) - y) >= 4)
			g_color_c = 1;
		else
			g_c_b = ft_atoi(no_space[0]);
	}
}

int	ft_cnt_vrg(char **no_space, int j)
{
	int r;
	int error;

	r = 0;
	error = 0;
	while (no_space[r] != '\0')
		r++;
	if(r == 1)
		error = ft_take_color_four(no_space);
	else
		error = ft_take_color_five(no_space);
	if(error == 1)
		ft_add_colors(no_space,j);
	return(error);
}
int	ft_cnt_r(char **no_space)
{
	int r;
	
	r = 0;
	while (no_space[r] != '\0')
	r++;
	return(r);
}

int ft_vrg(char **no_vrg,char **no_space, int i, int j)
{
	while (j <= i)
	{
		no_space = ft_split(no_vrg[j], ' ');
		if (j == 0)
		{
			g_r = ft_cnt_r(no_space);
			if(g_r == 2)
				g_error = ft_take_color_one(no_space);
			else
			{
				g_error = ft_take_color_two(no_space);
				break;
			}
			if(g_error == 1)
				ft_take_color_three(no_space);
		}
		else
			g_error = ft_cnt_vrg(no_space,j);
		if(g_error == 0)
			break;
		j++;
		ft_ptr_ln(no_space);
	}
	return(g_error);
}

int	ft_check_vrg(char **no_vrg,size_t i)
{
	int error;
	size_t j;
	char **no_space;

	no_space = NULL;
	j = 0;
	g_r = 0;
	g_error = 0;
	error = ft_vrg(no_vrg,no_space,i,j);
		return (error);
}

void ft_take_digit(char **no_space, int r)
{
	size_t t;

	t = 0;
	while (t != ft_strlen(no_space[r]))
	{
		if(ft_isdigit(no_space[r][t]) == 0)
		{
			g_chose_error = 1;
			break;
		}
		t++;
	}
}

void ft_info_error(int j, size_t t, char **no_space)
{
	int r;

	if(j == 0)
	{
		if(t > 2)
			g_sec_error = 1;
		r = 1;
	}
	else
	{
		if(t > 1)
			g_sec_error = 1;
		r = 0;
	}
	while (no_space[r] != '\0')
	{
		t = 0;
		ft_take_digit(no_space,r);
		if(g_chose_error == 1)
			break;
		r++;
	}
}

int ft_else()
{
	int error;
	
	error = 0;
	g_text_error = "just two virgule in C";
	return(error);
}

int ft_else_f()
{
	int error;
	
	error = 0;
	g_text_error = "just two virgule in F";
	return(error);
}

void	ft_condition_errors()
{
	if((g_chose_error == 0) && (g_sec_error == 0))
		g_text_error = "Wrong number of infos in C";
	else
	{
		if((g_sec_error == 1) && (g_chose_error == 0))
			g_text_error = "Minimum numbers for one element in C is 1";
		else
			g_text_error = "Info invalid in C";
	}
}

int	ft_check_next_vrg(char **no_space, char **no_vrg)
{
	int error;
	int j;
	int r;
	size_t t;

	error = 0;
	g_sec_error = 0;
	g_chose_error = 0;
	j = 0;
	r = 0;
	t = 0;
		while (no_vrg[j] != '\0')
		{
			no_space = ft_split(no_vrg[j],' ');
			t = 0;
			while (no_space[t] != '\0')
				t++;
			ft_info_error(j,t,no_space);
			if(g_chose_error == 1)
				break;
			j++;
			ft_ptr_ln(no_space);
		}
		ft_condition_errors();
		return(error);
}

void	ft_chose_error_f(int chose_error)
{
	if(chose_error == 0)
		g_text_error = "Minimum numbers for one element in F is 1";
	else
		g_text_error = "Info invalid in F";
}

int	ft_take_color_two_f(char **no_space)
{
	int error;
	size_t	t;
	int r;
	int chose_error;
	
	r = 1;
	error = 0;
	while (no_space[r] != '\0')
	{
		t = 0;
		while (t != ft_strlen(no_space[r]))
		{
			if(ft_isdigit(no_space[r][t]) == 0)
			{
				chose_error = 1;
				break;
			}
			t++;
		}
		if(chose_error == 1)
			break;
		r++;
	}

	ft_chose_error_f(chose_error);
	return(error);
}

int	ft_take_color_one_f(char **no_space)
{
	int error;
	size_t b;

	b = 0;
	while (b != ft_strlen(no_space[1]))
	{
		if(ft_isdigit(no_space[1][b]) == 0)
		{
			g_text_error = "Info invalid in F";
			error = 0;
			break;
		}
		else
		{
			error = 1;
			g_info = 1;
			}
			if(error == 0)
				break;
		b++;
	}
	return(error);
}

int	ft_cnt_r_f(char **no_space)
{
	int r;
	
	r = 0;
	while (no_space[r] != '\0')
	r++;
	return(r);
}

void ft_take_color_three_f(char **no_space)
{
	int y;

	y = 0;
	while (no_space[1][y] != '\0')
	{
		if(no_space[1][y] != '0')
			break;
		y++;
	}
	if((ft_strlen(no_space[1]) - y) >= 4)
		g_color_f = 1;
	else
		g_f_r = ft_atoi(no_space[1]);
}

int	ft_take_color_four_f(char **no_space)
{
	size_t b;
	int error;

	b = 0;
	while (b != ft_strlen(no_space[0]))
	{
		if(ft_isdigit(no_space[0][b]) == 0)
		{
			g_text_error = "Info invalid in F";
			error = 0;
			break;
		}
		else
		{
			error = 1;
			g_info = 1;
		}
		if(error == 0)
			break;
		b++;
	}
	return(error);
}

int	ft_take_color_five_f(char **no_space)
{
	int error;
	int t;
	int chose_error;
	int r;

	error = 0;
	t = 0;
	r = 0;
	chose_error = 0;
	while (no_space[t] != '\0')
	{
		r = 0;
		while (no_space[t][r] != '\0')
		{
			if(ft_isdigit(no_space[t][r]) == 0)
			{
				chose_error = 1;
				break;
			}
			r++;
		}
		t++;
	}
	if(chose_error == 1)
		g_text_error = "Info invalid in F";
	else
		g_text_error = "Minimum numbers for one element in F is 1";
	return(error);
}

void	ft_add_colors_f(char **no_space, int j)
{
	int y;

	y = 0;
	while (no_space[0][y] != '\0')
	{
		if(no_space[0][y] != '0')
			break;
		y++;
	}
	if(j == 1)
	{
		if((ft_strlen(no_space[0]) - y) >= 4)
			g_color_f = 1;
		else
			g_f_g = ft_atoi(no_space[0]);
	}
	if(j == 2)
	{
		if((ft_strlen(no_space[0]) - y) >= 4)
			g_color_f = 1;
		else
			g_f_b = ft_atoi(no_space[0]);
	}
}

int	ft_cnt_vrg_f(char **no_space, int j)
{
	int r;
	int error;

	r = 0;
	error = 0;
	while (no_space[r] != '\0')
		r++;
	if(r == 1)
		error = ft_take_color_four_f(no_space);
	else
		error = ft_take_color_five_f(no_space);
	if(error == 1)
		ft_add_colors_f(no_space,j);
	return(error);
}

int ft_vrg_f(char **no_vrg,char **no_space, int i, int j)
{
	while (j <= i)
	{
		no_space = ft_split(no_vrg[j], ' ');
		if (j == 0)
		{
			g_r = ft_cnt_r_f(no_space);
			if(g_r == 2)
				g_error = ft_take_color_one_f(no_space);
			else
			{
				g_error = ft_take_color_two_f(no_space);
				break;
			}
			if(g_error == 1)
				ft_take_color_three_f(no_space);
		}
		else
			g_error = ft_cnt_vrg_f(no_space,j);
		if(g_error == 0)
			break;
		j++;
		ft_ptr_ln(no_space);
	}
	return(g_error);
}


int	ft_check_vrg_f(char **no_vrg,size_t i)
{
	int error;
	size_t j;
	char **no_space;

	no_space = NULL;
	j = 0;
	g_r = 0;
	g_error = 0;
	error = ft_vrg_f(no_vrg,no_space,i,j);
		return (error);
}

void	ft_condition_errors_f()
{
	if((g_chose_error == 0) && (g_sec_error == 0))
		g_text_error = "Wrong number of infos in F";
	else
	{
		if((g_sec_error == 1) && (g_chose_error == 0))
			g_text_error = "Minimum numbers for one element in F is 1";
		else
			g_text_error = "Info invalid in F";
	}
}

void ft_take_digit_f(char **no_space, int r)
{
	size_t t;

	t = 0;
	while (t != ft_strlen(no_space[r]))
	{
		if(ft_isdigit(no_space[r][t]) == 0)
		{
			g_chose_error = 1;
			break;
		}
		t++;
	}
}

void ft_info_error_f(int j, size_t t, char **no_space)
{
	int r;

	if(j == 0)
	{
		if(t > 2)
			g_sec_error = 1;
		r = 1;
	}
	else
	{
		if(t > 1)
			g_sec_error = 1;
		r = 0;
	}
	while (no_space[r] != '\0')
	{
		t = 0;
		ft_take_digit_f(no_space,r);
		if(g_chose_error == 1)
			break;
		r++;
	}
}

int	ft_check_next_vrg_f(char **no_space, char **no_vrg)
{
	int error;
	int j;
	int r;
	size_t t;

	error = 0;
	g_sec_error = 0;
	g_chose_error = 0;
	j = 0;
	r = 0;
	t = 0;
		while (no_vrg[j] != '\0')
		{
			no_space = ft_split(no_vrg[j],' ');
			t = 0;
			while (no_space[t] != '\0')
				t++;
			ft_info_error_f(j,t,no_space);
			if(g_chose_error == 1)
				break;
			j++;
			ft_ptr_ln(no_space);
		}
		ft_condition_errors_f();
		return(error);
}

void	ft_letter(char **no_space, int r)
{
	size_t j;

	j = 0;
	while (j != ft_strlen(no_space[r]))
	{
		if(ft_isdigit(no_space[r][j]) == 0)
		{
			g_chose_error = 1;
			break;
		}
		j++;
	}
}

void ft_for_r()
{
	if(g_chose_error == 0)
			g_text_error = "Wrong number of infos in R";
	else
		g_text_error = "Info invalid in R";
}

int	ft_letter_r(char **no_space, int i)
{
	size_t j;
	int error;

	j = 0;
	error = 0;
	while (j != ft_strlen(no_space[i]))
	{
		if (ft_isdigit(no_space[i][j]) == 0)
		{
			error = 0;
			g_text_error = "Info invalid in R";
			break ;
		}
		else
		{
			error = 1;
			g_info = 1;
		}
		j++;
	}
	return(error);
}

void	ft_take_informations_r(char **no_space, int i)
{
	if((ft_strlen(no_space[1]) - i) >= 5)
		g_width_window = 2560;
	else
		g_width_window = ft_atoi(no_space[1]);
	if((ft_strlen(no_space[2]) - i) >= 5)
		g_height_window = 1440;
	else
		g_height_window = ft_atoi(no_space[2]);
}

int		ft_valid_check(int r, int error)
{
	if(r == 2)
		error = 1;
	else
		error = ft_else();
	return(error);
}
int		ft_valid_check_f(int r, int error)
{
	if(r == 2)
		error = 1;
	else
		error = ft_else_f();
	return(error);
}

int		ft_check_line_map(const char *str, int info)
{
	int error;
	if((g_get_y >= 1) && (g_all_info == 8))
		g_text_error = "Close the map";
	else
		g_text_error = "Invalid Text";
	error = 0;
	if ((ft_line_map(str) == 1) && (info == 1))
		error = 1;
	else
	{
		error = 0;
	}
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
			g_pirmission = 1;
			j = 0;
			break ;
		}
		i++;
	}
	return (j);
}

int		ft_check_info_draw(char **separ_lines, int j, int error)
{
	int i;

	while (j != g_get_y - 1)
	{
		if (((separ_lines[j][ft_strlen(separ_lines[j]) - 1] == '1')
				|| (separ_lines[j][ft_strlen(separ_lines[j]) - 1] == ' '))
				&& ((separ_lines[j][0] == '1') || (separ_lines[j][0] == ' ')))
		{
			i = 0;
			error = ft_zero_space(separ_lines, i, j, error);
		}
		else
			error = 1;
		if (error == 1)
		{
			if(g_duplicate_p == 0)
				g_text_error = "Close the map";
			break;
		}
		j++;
	}
	return (error);
}

int		ft_extention(char *str)
{
	int i;
	int j;
	int error;
	char **dot;

	i = 0;
	j = 0;
	error = 0;
	dot = ft_split(str,'.');
	while(dot[i] != '\0')
		i++;
	if((i > 0) && (ft_strlen(dot[i - 1]) == 3))
	{
		while (dot[i - 1][j] != '\0')
		{
			if((dot[i - 1][j] != 'c') && (dot[i - 1][j] != 'u') && (dot[i - 1][j] != 'b'))
			{
				error = 1;
				break;
			}
			j++;
		}
	}
	else
		error = 1;
	ft_ptr_ln(dot);
	return(error);
}

int	ft_strcmp(char *s1, const char *s2)
{
	int x;

	x = 0;
	while (s1[x] == s2[x] && s1[x] != '\0' && s2[x] != '\0')
		x++;
	return (s1[x] - s2[x]);
}

int	ft_zero_two(char **separ_lines, int i, int j, int error)
{
	if ((separ_lines[j][i] == '0') || (separ_lines[j][i] == '2'))
	{
		if(separ_lines[j][i] == '2')
			ft_sprite_position(j,i);
		if (ft_break(separ_lines, i, j, error) == 1)
			error = 1;
	}
	return (error);
}

int ft_check_player_map(char **separ_lines, int i, int j, int error)
{
	if ((separ_lines[j][i] == 'N') || (separ_lines[j][i] == 'S') || (separ_lines[j][i] == 'E') || (separ_lines[j][i] == 'W'))
	{
		if(g_duplicate_p == 0)
		{
			if (ft_break(separ_lines, i, j, error) == 1)
				error = 1;
			else
			{
				g_duplicate_p = 1;
				g_side_p = separ_lines[j][i];
			}
		}
		else
		{
			error = 1;
			g_text_error = "Duplicate Player in th map";
		}
	}
	return(error);
}

int ft_zero_map(char **separ_lines, int i, int j, int error)
{
	if (separ_lines[j][i] == ' ')
	{
		if(((int)(i - 1) >= 0) && ((int)(i + 1) < (int)(ft_strlen(separ_lines[j]))) 
		&& ((int)(i + 1) < (int)(ft_strlen(separ_lines[j + 1]))) 
		&& ((int)(i + 1) < (int)(ft_strlen(separ_lines[j - 1]))))
		{
			if ((separ_lines[j][i - 1] == '0')
			|| (separ_lines[j][i + 1] == '0')
			|| (separ_lines[j - 1][i] == '0')
			|| (separ_lines[j + 1][i] == '0'))
				error = 1;
		}
	}
	return (error);
}

void	ft_organize()
{
	if(g_width_window > 2560)
		g_width_window = 2560;
	if(g_height_window > 1440)
		g_height_window = 1440;
	if(g_side_p == 'N')
		g_check_direction = (M_PI / 2) + (M_PI / 2) + (M_PI / 2);
	if(g_side_p == 'S')
		g_check_direction = M_PI / 2;
	if(g_side_p == 'E')
		g_check_direction = M_PI + M_PI;
	if(g_side_p == 'W')
		g_check_direction = M_PI;
}

int		ft_no_ea(int error)
{
	if (!(g_textur_three = mlx_xpm_file_to_image(g_mlx_ptr, g_textur_no,&g_t,&g_t))) 
	{
		if(error == 0)
		{
			write(1,"Error\n",7);
			write(1,g_textur_no,(int)ft_strlen(g_textur_no));
			write(1," Invalid file\n",14);
			error = 1;
		}
	}
	if (!(g_textur_four = mlx_xpm_file_to_image(g_mlx_ptr, g_textur_ea,&g_t,&g_t)))
	{
		if(error == 0)
		{
			write(1,"Error\n",7);
			write(1,g_textur_ea,(int)ft_strlen(g_textur_ea));
			write(1," Invalid file\n",14);
			error = 1;
		}
	}
	return(error);
}

int		ft_s(int error)
{
	if (!(g_textur_five = mlx_xpm_file_to_image(g_mlx_ptr, g_textur_sprite,&g_sprite_width,&g_sprite_height)))
	{
		if(error == 0)
		{
			write(1,"Error\n",7);
			write(1,g_textur_sprite,(int)ft_strlen(g_textur_sprite));
			write(1," Invalid file\n",14);
			error = 1;
		}
	}
	return (error);
}

int		ft_texturs(int error)
{
	if (!(g_textur_one = mlx_xpm_file_to_image(g_mlx_ptr,g_textur_so,&g_t,&g_t)))
	{
		write(1,"Error\n",7);
		write(1,g_textur_so,(int)ft_strlen(g_textur_so));
		write(1," Invalid file\n",14);
		error = 1;
	}
	if (!(g_textur_two = mlx_xpm_file_to_image(g_mlx_ptr, g_textur_we,&g_t,&g_t))) 
	{
		if(error == 0)
		{
			write(1,"Error\n",7);
			write(1,g_textur_we,(int)ft_strlen(g_textur_we));
			write(1," Invalid file\n",14);
			error = 1;
		}
	}
	error = ft_no_ea(error);
	error = ft_s(error);
	return (error);
}

int		ft_error_cl(int error)
{
	if(error == 0)
	{
		write(1,"Error\n",7);
		write(1,"Color no valid in C\n",20);
		error = 1;
	}
	return (error);
}

int		ft_colors(int error)
{
	if((g_color_f == 0) && ((g_f_r <= 255) && ((g_f_r >= 0))) 
	&& ((g_f_g <= 255) && ((g_f_g >= 0))) && ((g_f_b <= 255) 
	&& ((g_f_b >= 0))))
		g_color_floor = g_f_r * 65536 + g_f_g * 256 + g_f_b;
	else
	{
		if(error == 0)
		{
			write(1,"Error\n",7);
			write(1,"Color no valid in F\n",20);
			error = 1;
		}
	}
	if((g_color_c == 0) && ((g_c_r <= 255) && ((g_c_r >= 0))) 
	&& ((g_c_g <= 255) && ((g_c_g >= 0))) 
	&& ((g_c_b <= 255) && ((g_c_b >= 0))))
		g_color_sky = g_c_r * 65536 + g_c_g * 256 + g_c_b;
	else
		error = ft_error_cl(error);
	return (error);
}

void	ft_put_data()
{
	g_data_one = (int *)mlx_get_data_addr(g_textur_four, &g_t,&g_t,&g_t);
	g_data_two = (int *)mlx_get_data_addr(g_textur_two, &g_t,&g_t,&g_t);
	g_data_three = (int *)mlx_get_data_addr(g_textur_one, &g_t,&g_t,&g_t);
	g_data_four = (int *)mlx_get_data_addr(g_textur_three, &g_t,&g_t,&g_t);
	g_data_five = (int *)mlx_get_data_addr(g_textur_five, &g_t,&g_t,&g_t);
	g_x = 0;
	g_y = 0;
	g_num_rays = g_width_window;
	g_rays = malloc((g_num_rays) *  sizeof(t_rays));
    g_win_ptr = mlx_new_window(g_mlx_ptr, g_width_window, g_height_window, "cub3D");
	g_img.img = mlx_new_image(g_mlx_ptr, g_width_window, g_height_window);
	g_img.addr = mlx_get_data_addr(g_img.img, &g_img.bits_per_pixel, &g_img.line_length,&g_img.endian);
	ft_toll_line();
	ft_drawing();
	if(g_save == 1)
		ft_screenshot();
	else
		mlx_loop(g_mlx_ptr);
}

void ft_direction_texturs(int i, int x, float result)
{
	int n;

	n = (ft_check_y(i,g_wall_height) * g_tile_size) + result;
	if((n >= 4096) || (n < 0))	
			n = 4095;
	if((g_was_vertical) && (g_is_ray_facing_left))
		my_mlx_pixel_put(&g_img,x,i,g_data_one[n]);
	if((g_was_vertical) && (g_is_ray_facing_right))
		my_mlx_pixel_put(&g_img,x,i,g_data_two[n]);
	if((g_was_vertical == 0) && (g_is_ray_facing_up))
		my_mlx_pixel_put(&g_img,x,i,g_data_three[n]);
	if((g_was_vertical == 0) && (g_is_ray_facing_down))
		my_mlx_pixel_put(&g_img,x,i,g_data_four[n]);

}

void	ft_app_colors(int i, int j, int x, float result)
{
	while (j < g_wall_height && i < g_height_window)
    {
		if(i > 0)
			ft_direction_texturs(i,x,result);
        i++;
        j++;
    }
	while (i < g_height_window)
	{
		my_mlx_pixel_put(&g_img,x,i,g_color_floor);
		i++;
	}
}

void	ft_color_window()
{
	int j;
	int i;

	j = 0;
	i = 0;
	while (j < g_height_window)
	{
		i = 0;
		while (i < g_width_window)
		{
			my_mlx_pixel_put(&g_img,i,j,0x000000);
			i++;
		}
		j++;
	}
}

void	ft_mov()
{
	ft_color_window();
	ft_drawing();
}

void	ft_continue_hz()
{
	g_found_horizontal = 0;
	g_wall_horizontal_x = 0;
	g_wall_horizontal_y = 0;
	 g_closet_one_y = (int)(g_y / g_tile_size) * g_tile_size;
	 if(g_is_ray_facing_down == 1)
		 g_closet_one_y = g_closet_one_y + g_tile_size;
	 else
	 	g_closet_one_y = g_closet_one_y + 0;
	 g_closet_one_x = g_x + ((g_closet_one_y - g_y) / tan(g_ray_angle));
	 g_y_step = g_tile_size;
	 if (g_is_ray_facing_up == 1)
		 g_y_step = g_y_step * -1;
	 else
	 {
		 if(g_is_ray_facing_down == 1)
		 	g_y_step = g_y_step * 1;
	 }
	 g_x_step = g_tile_size / tan(g_ray_angle);
	 if((g_is_ray_facing_left == 1) && (g_x_step > 0))
	 	g_x_step = g_x_step * -1;
	  else
		  g_x_step = g_x_step * 1;
}

void	ft_horizontal()
{
	ft_continue_hz();
	if((g_is_ray_facing_right == 1) && (g_x_step < 0))
		g_x_step = g_x_step * -1;
	else
		g_x_step = g_x_step * 1;
	g_next_one_x = g_closet_one_x;
	g_next_one_y = g_closet_one_y;
		while((g_next_one_x >= 0) && (g_next_one_x <= ((g_toll - 1) * g_tile_size)) 
		&& (g_next_one_y >= 0) && (g_next_one_y <= ((g_get_y - 1) * g_tile_size)))
		{
			if(ft_has_wallat(g_next_one_x,g_next_one_y -  g_is_ray_facing_up) == 1)
			{
				g_found_horizontal = 1;
				g_wall_horizontal_x = g_next_one_x;
				g_wall_horizontal_y = g_next_one_y;
				break;
			}
			else
			{
				g_next_one_x = g_next_one_x + g_x_step;
				g_next_one_y = g_next_one_y + g_y_step;
			}
		}
}

void	ft_continue_vr()
{
	if((g_is_ray_facing_down == 1) && (g_y_step < 0))
		g_y_step = g_y_step * -1;
	else
		g_y_step = g_y_step * 1;
}

void	ft_vertical()
{
	g_found_vertical = 0;
	g_wall_vertical_x = 0;
	g_wall_vertical_y = 0;
	 g_closet_one_x = (int)(g_x / g_tile_size) * g_tile_size;
	 if(g_is_ray_facing_right == 1)
		 g_closet_one_x = g_closet_one_x + g_tile_size;
	 else
	 	g_closet_one_x = g_closet_one_x + 0;
	 g_closet_one_y = g_y + ((g_closet_one_x - g_x) * tan(g_ray_angle));
	 g_x_step = g_tile_size;
	 if (g_is_ray_facing_left == 1)
		 g_x_step = g_x_step * -1;
	 else
	 {
		 if(g_is_ray_facing_right == 1)
		 	g_x_step = g_x_step * 1;
	 }
	 g_y_step = g_tile_size * tan(g_ray_angle);
	 if((g_is_ray_facing_up == 1) && (g_y_step > 0))
	 	g_y_step = g_y_step * -1;
	  else
		  g_y_step = g_y_step * 1;
		ft_continue_vr();
}

void	ft_continue_ds()
{
	if(g_found_horizontal == 1)
			g_horizontal_distance = ft_between_points(g_x,g_y,g_wall_horizontal_x,g_wall_horizontal_y);
	else
		g_horizontal_distance = INT64_MAX;
	if(g_found_vertical == 1)
		g_vertical_distance = ft_between_points(g_x,g_y,g_wall_vertical_x,g_wall_vertical_y);
	else
		g_vertical_distance = INT64_MAX;
	if(g_horizontal_distance < g_vertical_distance)
		g_wall_x = g_wall_horizontal_x;
	else
		g_wall_x = g_wall_vertical_x;
	if(g_horizontal_distance < g_vertical_distance)
		g_wall_y = g_wall_horizontal_y;
	else
		g_wall_y = g_wall_vertical_y;
	if (g_horizontal_distance < g_vertical_distance)
		g_distance = g_horizontal_distance;
	else
		g_distance = g_vertical_distance;
	if(g_vertical_distance < g_horizontal_distance)
		g_was_vertical = 1;
	else
		g_was_vertical = 0;
}

void	ft_distance()
{
		g_next_one_v_x = g_closet_one_x;
	g_next_one_v_y = g_closet_one_y;
		while((g_next_one_v_x >= 0) && (g_next_one_v_x <= ((g_toll - 1) * g_tile_size)) && (g_next_one_v_y >= 0) && (g_next_one_v_y <= ((g_get_y - 1) * g_tile_size)))
		{
			if(ft_has_wallat(g_next_one_v_x - g_is_ray_facing_left,g_next_one_v_y) == 1)
			{
				g_found_vertical = 1;
				g_wall_vertical_x = g_next_one_v_x;
				g_wall_vertical_y = g_next_one_v_y;
				break;
			}
			else
			{
				g_next_one_v_x = g_next_one_v_x + g_x_step;
				g_next_one_v_y = g_next_one_v_y + g_y_step;
			}
		}
		ft_continue_ds();
}

int            ft_close(void)
{
    mlx_destroy_window(g_mlx_ptr, g_win_ptr);
    exit(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	ft_toll_line()
{
	int i;
	size_t len;

	i = 0;
	len = 0;
	while(i != g_get_y)
	{
		if(ft_strlen(g_map[i]) > len)
			g_toll = ft_strlen(g_map[i]);
		len = ft_strlen(g_map[i]);
		i++;
	}
}

void    ft_draw_line(float x_one,float y_one,float x_zero,float y_zero)
{

    float steps;
    float x_inc;
    float y_inc;
    float i;
    i = 0;
    g_dx = x_one - x_zero;
    g_dy = y_one - y_zero;

    if (fabsf(g_dx) > fabsf(g_dy))
        steps = fabsf(g_dx);
    else 
        steps = fabsf(g_dy);
    x_inc = g_dx / steps;
    y_inc = g_dy / steps;
    while (i < steps)
    {        
        my_mlx_pixel_put(&g_img,x_zero,y_zero,0xFF0000);
        x_zero += x_inc;
        y_zero  += y_inc;
        i++;
    }
}

int     ft_has_wallat_p(float i, float j)
{
    int wallat;
    int position_x;
    int position_y;
	
    wallat = 0;
    position_x = (i / g_tile_size);
    position_y = (j / g_tile_size);
	if((position_y >= g_get_y) || (position_x >= (int)ft_strlen(g_map[position_y])))
		return(1);
    if((g_map[position_y][position_x] == '1') 
	|| (g_map[position_y][position_x] == ' ') 
	|| (g_map[position_y][position_x] == '\0'))
    	wallat = 1;
    else
		wallat = 0;
    return(wallat);
}

int     ft_has_wallat(float i, float j)
{
    int wallat;
    int position_x;
    int position_y;
	
    wallat = 0;
    position_x = (i / g_tile_size);
    position_y = (j / g_tile_size);
	if((position_y >= g_get_y) || (position_x >= (int)ft_strlen(g_map[position_y])))
		return(1);
    if((g_map[position_y][position_x] == '1') || (g_map[position_y][position_x] == ' ') || (g_map[position_y][position_x] == '\0'))
    	wallat = 1;
    else
		wallat = 0;
    return(wallat);
}

void        ft_ray_push(double x2, double y2)
{
    double      xinc;
    double      yinc;
    int         steps;
	int			g_tilecolor;

    g_x1 = g_x;
    g_y1 = g_y;
    g_tilecolor = 16711680;
    steps = abs((int)x2 - (int)g_x1) > abs((int)y2 - (int)y1) ? abs((int)x2 -
            (int)g_x1) : abs((int)y2 - (int)y1);
    xinc = (x2 - g_x1) / (double)steps;
    yinc = (y2 - g_y1) / (double)steps;
    x2 = -1;
    while (++x2 <= steps)
    {	
        g_x1 = g_x1 + xinc;
        g_y1 = g_y1 + yinc;
		my_mlx_pixel_put(&g_img,g_x1,g_y1,0xFF0000);
    }
}

double	ft_between_points(float x1, float y1, float x2, float y2)
{
	return(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	ft_draw_rays()
{
	int i;

	i = 0;
	while(i < g_num_rays)
	{
	g_ray_angle = ft_normalaize_angle(g_ray_angle);
	ft_check_ray_face();
	g_wall_x = 0;
	g_wall_y = 0;
	g_distance = 0;
	g_was_vertical = 0;
	ft_cast();
	ft_3d_walls(i);
	g_rays[i].distance = g_distance;
	g_ray_angle = g_ray_angle + (60 * (M_PI / 180) / g_num_rays);
		i++;
	}
}

float	ft_normalaize_angle(float angle)
{
	g_fo_v = 2 * M_PI;
	angle = fmod(angle,g_fo_v);
	if(angle < 0)
		angle = g_fo_v + angle;
	return(angle);
}

void	ft_cast()
{
	ft_horizontal();
	ft_vertical();
	ft_distance();
}

void	ft_check_ray_face()
{
	if((g_ray_angle > 0) && (g_ray_angle < M_PI))
	{
		g_is_ray_facing_down = 1;
		g_is_ray_facing_up = 0;
	}
	else
	{
		g_is_ray_facing_down = 0;
		g_is_ray_facing_up = 1;
	}
	if((g_ray_angle < (0.5 * M_PI)) || (g_ray_angle > (1.5 * M_PI)))
	{
		g_is_ray_facing_right = 1;
		g_is_ray_facing_left = 0;
	}
	else
	{
		g_is_ray_facing_right = 0;
		g_is_ray_facing_left = 1;
	}
}

void	ft_draw_player()
{
	g_new_playerx = g_x + cos(g_rotation_angle + g_b) * g_move_step * (g_walk_direction * 4);
	g_new_playery = g_y + sin(g_rotation_angle + g_b) * g_move_step * (g_walk_direction * 4);
    if(ft_has_wallat_p(g_new_playerx, g_new_playery) == 0)
    {
        g_x = g_x + cos(g_rotation_angle + g_b) * g_move_step * (g_walk_direction);
        g_y = g_y + sin(g_rotation_angle + g_b) * g_move_step * (g_walk_direction);
    }
		
	g_b = 0;
}

void	ft_draw_map()
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(g_map[j])
	{
		i = 0;
		while(g_map[j][i])
		{
			if(((g_map[j][i] == 'N') || (g_map[j][i] == 'S') || (g_map[j][i] == 'E') || (g_map[j][i] == 'W')) && (g_x == 0))
			{
				g_x = (g_tile_size * i) + g_tile_size / 2;
				g_y = (g_tile_size * j) + g_tile_size / 2;
			}
			i++;
		}
		j++;
	}
}

void	ft_drawing()
{
	g_rotation_angle = (g_check_direction) + (g_turn_direction + g_stock_direction)  * 10 * (M_PI / 180);
	g_ray_angle = g_rotation_angle - ((60 * M_PI / 180) / 2);
	g_move_step = 20;
	g_stock_direction = g_turn_direction + g_stock_direction;
	g_stock_walk = g_walk_direction + g_stock_walk;
	ft_draw_map();
	ft_draw_player();
	ft_draw_rays();
	ft_sprite();
	g_move_step = 0;
	mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_img.img, 0, 0);
	mlx_hook(g_win_ptr,2,0,&deal_key,&g_img);
	mlx_hook(g_win_ptr,3,0,&deal_key_release,&g_img);
	mlx_hook(g_win_ptr, 17, 1L << 17, ft_close, (void *)0);
}

void	ft_window()
{ 
	int error;

	error = 0;
	if(g_side_p)
	{
		ft_organize();
		error = ft_texturs(error);
		error = ft_colors(error);
		if(error == 0)
			ft_put_data();
	}
	else
	{
		if(g_all_info == 8)
		{
			write(1,"Error\n",7);
			write(1,"No Player in the map\n",21);
		}
		else
		{
			write(1,"Error\n",7);
			write(1,"lack the identifier\n",20);
		}
	}
}

void	ft_sprite_distance()
{
	int x_s;
	int y_s;

	t_list *tmp;
	tmp = g_sprite_h;
	while (tmp!= NULL)
	{
		x_s = ((t_sprite *)tmp->content)->x;
		y_s = ((t_sprite *)tmp->content)->y;

		((t_sprite *)tmp->content)->distance = distance_two_points(g_x,g_y,x_s,y_s);
		tmp = tmp -> next;
	}
}

void ft_sort_sprites()
{

	t_list	*new;
	t_list	*temp;
	t_sprite	*inter;

	new = g_sprite_h;
	while (new != NULL)
	{
		temp = new;
		while (temp->next != NULL)
		{
			if (((t_sprite *)temp->content)->distance < ((t_sprite *)temp->next->content)->distance)
			{
				inter = (t_sprite *)temp->content;
				temp->content = temp->next->content;
				temp->next->content = (void *)inter;
			}
			temp = temp->next;
		}
		new = new->next;
}
}

int	 protect_x(t_sprite *sprite, int i)
{
	int valid;
	valid = 1;
	if (sprite->x_offset + i < 0 ||
				 (int)sprite->x_offset + i >= g_num_rays ||
			 sprite->distance > g_rays[(int)sprite->x_offset + i].distance)
				valid = 0;
	return (valid);
}

void	ft_draw_sprite(t_sprite *sprite, int i, int j)
{
	int color;

	color = g_data_five[((int)g_sprite_width* (j * \
	(int)g_sprite_height/
			(int)sprite->size)) + (i * (int)g_sprite_width /
			(int)sprite->size)];
			if(color != 0)
					my_mlx_pixel_put(&g_img, sprite->x_offset + i,sprite->y_offset + j ,color);
	
}

void	ft_start_draw_sprite(t_sprite *sprite)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < sprite->size - 1)
	{
		if (!protect_x(sprite, i))
		{
			i++;
			continue;
		}
				j = 0;
		while (j < sprite->size - 1)
		{

			if (sprite->y_offset + j < 0 ||
					sprite->y_offset + j >= g_height_window)
			{
				j++;
				continue;
			}
			ft_draw_sprite(sprite, i, j);
			j++;
		}
		i++;
	}
}

void ft_render_sprite(t_sprite *sprite)
{
	float s_angle;

	s_angle = atan2(sprite->y - g_y, sprite->x - g_x);
	while (s_angle - (g_rotation_angle) > M_PI)
		s_angle -= 2 * M_PI;
	while (s_angle - (g_rotation_angle) < -M_PI)
		s_angle += 2 * M_PI;
	s_angle -= g_rotation_angle;
	if (g_height_window > g_width_window)
		sprite->size = (g_height_window/ sprite->distance) * g_tile_size;
	else
		sprite->size = (g_width_window/ sprite->distance) * g_tile_size;
	sprite->y_offset = (g_height_window / 2) - (sprite->size / 2);
	sprite->x_offset = ((s_angle * g_width_window) / (60 * M_PI / 180)) +
		((g_width_window / 2) - (sprite->size / 2));
		ft_start_draw_sprite(sprite);
}

void ft_render_sprites()
{
	t_list *new;

	new = g_sprite_h;
	while (new)
	{
		ft_render_sprite((t_sprite *) new ->content);
		new = new ->next;
	}
}
void	ft_sprite()
{
	ft_sprite_distance();
	ft_sort_sprites();
    ft_render_sprites();
}

int		*get_colors(int color)
{
	int		*colors;

	if (!(colors = malloc(3 * sizeof(int))))
		ft_error();
	colors[0] = ((color >> 16) & 0xFF);
	colors[1] = ((color >> 8) & 0xFF);
	colors[2] = ((color) & 0xFF);
	return (colors);
}

void	ft_screenshot(void)
{
	int				*color;
	t_header		info;
	unsigned char	*header;
	
	header = ft_calloc(54, sizeof(unsigned char));
	ft_init_header(header, &info, 10);
	if (!(info.buf = malloc(info.image_size)))
		ft_error();
	while (info.row > 0)
	{
		info.col = 0;
		while (info.col < info.width)
		{
			color = get_colors(info.data[(g_height_window - info.row) * \
				g_width_window + info.col]);
							info.buf[info.row * info.w_in_b + info.col * 3 + 0] = color[2];
			info.buf[info.row * info.w_in_b + info.col * 3 + 1] = color[1];
			info.buf[info.row * info.w_in_b + info.col * 3 + 2] = color[0];
			free(color);
			info.col++;
		}
		info.row--;
	}
	fill_image(header, info, (char *)info.buf);
}