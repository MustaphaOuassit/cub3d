/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:47:00 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/11 19:32:49 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_write_argv(char *argv)
{
	write(1, "Error\n", 7);
	write(1, "File ", 5);
	write(1, argv, (int)ft_strlen(argv));
	write(1," no valid\n", 10);
}

void	ft_check_elements(char *line, int error)
{
	if (ft_continue(line, error) == 0)
	{
		free(line);
		if (g_all_info == 8)
		{
			g_mlx_ptr = mlx_init();
			ft_window();
		}
		else
		{
			write(1, "Error\n", 7);
			write(1, "lack the identifier\n", 21);
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
	ft_check_elements(line, error);
}

void	ft_change_dup(void)
{
	g_duplicate_r = 1;
	g_all_info = g_all_info + 1;
}
