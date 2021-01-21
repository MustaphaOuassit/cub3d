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

	mlx_ptr = mlx_init();
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
					save = 1;
				else
				{
					error = 1;
					printf("Error\n%s no valid\n",argv[2]);
				}
			}
			if(error == 0)
			{
				get = malloc(2);
				*get = '\0';
				tile_size = 64; 
				while (get_next_line(fd, &line) == 1)
				{
					entre = 1;
					if (ft_check_errors(line) == 0)
					{
						error = 1;
						break ;
					}
					else
						error = 0;
				}
				if (ft_continue(line, error) == 0)
				{

					ft_window();
					//printf("%s\n","GO");
				}
				else
					printf("Error\n%s\n",text_error);
			}
		}
		else
			printf("Error\nFile %s no valid\n",argv[1]);
	}
	else
		printf("Error\nMinimum argc is 3\n");
}
