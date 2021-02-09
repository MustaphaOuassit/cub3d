/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:47:00 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/07 14:47:02 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_write_argv(char *argv)
{
	write(1,"Error\n",7);
	write(1,"File ",5);
	write(1,argv,(int)ft_strlen(argv));
	write(1," no valid\n",10);
}

void	ft_check_elements(char *line, int error)
{
	if (ft_continue(line, error) == 0)
	{
		free(line);
		if(g_all_info == 8)
		{
			g_mlx_ptr = mlx_init();
			ft_window();
		}
		else
		{
			write(1,"Error\n",7);
			write(1,"lack the identifier\n",21);
		}
	}
	else
    {
		write(1,"Error\n",7);
		write(1,g_text_error,(int)ft_strlen(g_text_error));
		write(1,"\n",1);
	}
}
int ft_check_save(int argc, char *argv[],int error)
{
    char	*text_save;

    text_save = "--save";
    if(argc == 3)
	{ 
        if(ft_strcmp(text_save,argv[2]) == 0)
            g_save = 1;
		else
        {
            error = 1;
			write(1,"Error\n",7);
			write(1,argv[2],(int)ft_strlen(argv[2]));
			write(1," no valid\n",10);
		}
	}
    return(error);
}

void    ft_take_informations(int fd,int error)
{
	char *line;

	g_get = ft_strdup("");
    g_tile_size = 64;
    while (get_next_line(fd, &line) == 1)
	{
        g_entre = 1;
		if (ft_check_errors(line) == 0)
		{
            error = 1;
			break ;
		}
        else
            error = 0;
		free(line);
	}
	ft_check_elements(line,error);
}
void ft_change_dup()
{
	g_duplicate_r = 1;
	g_all_info = g_all_info + 1;
}

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
