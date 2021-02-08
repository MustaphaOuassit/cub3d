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