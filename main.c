/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:59:14 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/07 19:21:50 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		fd;
	int		error;

	error = 0;
	if ((argc == 2) || (argc == 3))
	{
		fd = open(argv[1], O_RDONLY);
		if ((fd != -1) && (ft_extention(argv[1]) == 0))
		{
			error = ft_check_save(argc, argv, error);
			if (error == 0)
				ft_take_informations(fd, error);
		}
		else
			ft_write_argv(argv[1]);
	}
	else
	{
		write(1, "Error\n", 7);
		write(1, "Wrong numbers of argc\n", 22);
	}
}
