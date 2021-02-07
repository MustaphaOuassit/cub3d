/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:59:14 by mouassit          #+#    #+#             */
/*   Updated: 2020/12/08 13:55:26 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	char	*text_save;
	int		error;
	
	text_save = "--save";
	error = 0;
	if((argc == 2) || (argc == 3))
	{
		fd = open(argv[1], O_RDONLY);
		if ((fd != -1) && (ft_extention(argv[1]) == 0))
		{
			if(argc == 3)
			{ 
				if(ft_strcmp(text_save,argv[2]) == 0)
				{
					g_save = 1;
				}
				else
				{
					error = 1;
					write(1,"Error\n",7);
					write(1,argv[2],(int)ft_strlen(argv[2]));
					write(1," no valid\n",10);
				}
			}
			if(error == 0)
			{
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
				if (ft_continue(line, error) == 0)
				{
					free(line);
					g_mlx_ptr = mlx_init();
					ft_window();
				}
				else
				{
					write(1,"Error\n",7);
					write(1,g_text_error,(int)ft_strlen(g_text_error));
					write(1,"\n",1);
				}
			}
		}
		else
		{
			write(1,"Error\n",7);
			write(1,"File ",5);
			write(1,argv[1],(int)ft_strlen(argv[1]));
			write(1," no valid\n",10);
		}
	}
	else
	{
		write(1,"Error\n",7);
		write(1,"Wrong numbers of argc\n",22);
	}
}
