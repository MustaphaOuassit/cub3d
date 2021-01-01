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
	int		error;

	if(argc == 2)
	{
		get = malloc(2);
		*get = '\0';
		resolution = malloc(2);
		tile_size = 64; 
		fd = open(argv[1], O_RDONLY);
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
			ft_window(resolution);
		}
	}
}
