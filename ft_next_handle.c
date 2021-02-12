/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:42:28 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/12 15:08:51 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_organize(void)
{
	if (g_width_window > 2560)
		g_width_window = 2560;
	if (g_height_window > 1440)
		g_height_window = 1440;
	if (g_side_p == 'N')
		g_check_direction = (M_PI / 2) + (M_PI / 2) + (M_PI / 2);
	if (g_side_p == 'S')
		g_check_direction = M_PI / 2;
	if (g_side_p == 'E')
		g_check_direction = M_PI + M_PI;
	if (g_side_p == 'W')
		g_check_direction = M_PI;
}

int		ft_no_ea(int error)
{
	if (!(g_textur_three = mlx_xpm_file_to_image
(g_mlx_ptr, g_textur_no, &g_t, &g_t)))
	{
		if (error == 0)
		{
			write(1, "Error\n", 7);
			write(1, g_textur_no, (int)ft_strlen(g_textur_no));
			write(1, " Invalid file\n", 14);
			error = 1;
		}
	}
	if (!(g_textur_four = mlx_xpm_file_to_image
(g_mlx_ptr, g_textur_ea, &g_t, &g_t)))
	{
		if (error == 0)
		{
			write(1, "Error\n", 7);
			write(1, g_textur_ea, (int)ft_strlen(g_textur_ea));
			write(1, " Invalid file\n", 14);
			error = 1;
		}
	}
	return (error);
}

int		ft_s(int error)
{
	if (!(g_textur_five = mlx_xpm_file_to_image
(g_mlx_ptr, g_textur_sprite, &g_sprite_width, &g_sprite_height)))
	{
		if (error == 0)
		{
			write(1, "Error\n", 7);
			write(1, g_textur_sprite, (int)ft_strlen(g_textur_sprite));
			write(1, " Invalid file\n", 14);
			error = 1;
		}
	}
	return (error);
}

int		ft_texturs(int error)
{
	if (!(g_textur_one = mlx_xpm_file_to_image
(g_mlx_ptr, g_textur_so, &g_t, &g_t)))
	{
		write(1, "Error\n", 7);
		write(1, g_textur_so, (int)ft_strlen(g_textur_so));
		write(1, " Invalid file\n", 14);
		error = 1;
	}
	if (!(g_textur_two = mlx_xpm_file_to_image
(g_mlx_ptr, g_textur_we, &g_t, &g_t)))
	{
		if (error == 0)
		{
			write(1, "Error\n", 7);
			write(1, g_textur_we, (int)ft_strlen(g_textur_we));
			write(1, " Invalid file\n", 14);
			error = 1;
		}
	}
	error = ft_no_ea(error);
	error = ft_s(error);
	return (error);
}

int		ft_error_cl(int error)
{
	if (error == 0)
	{
		write(1, "Error\n", 7);
		write(1, "Color no valid in C\n", 20);
		error = 1;
	}
	return (error);
}
