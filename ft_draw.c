/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 10:07:03 by mouassit          #+#    #+#             */
/*   Updated: 2020/12/09 10:07:05 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	deal_key_release()
{
	turn_direction = 0;
}
int deal_key(int key, void *param)
{
	int walk_direction;

	walk_direction = 0;
	turn_direction = 0;
	if(key == 126)
		walk_direction = 1;
	else
	{
		if(key == 125)
			walk_direction = -1;
		else
		{
			if(key == 123)
				turn_direction = 1;
			else
			{
				if(key == 124)
					turn_direction = -1;
			}
		}
		ft_draw(resolution, get_y);
	}
	return(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	ft_draw(char **resolution, int get_y)
{
	int j;
	int i;
	int t;
	int x;
	int color;
	int y;
	int loop_x;
	int loop_y;
	int m;
	float retation_angle;
	t_data img;
	j = 0;
	i = 0;
	t = 0;
	x = 0;
	y = 0;
	retation_angle = M_PI / 2 + (turn_direction + stock_direction) * 10 * (M_PI / 180);
	img.img = mlx_new_image(mlx_ptr, width_window, height_window);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	j = 0;
	i = 0;
	mlx_hook(win_ptr,2,0,&deal_key,&img);
	mlx_hook(win_ptr,3,0,&deal_key_release,&img);
	while(map[j])
	{
		i = 0;
		while(map[j][i])
		{
			if(map[j][i] == '1')
				color = 0xFF0000;
			else
			{
				if(map[j][i] == '0')
					color = 0xFFFFFF;
				else
				{
					if(map[j][i] == '2')
						color = 0xFFFFFF;
					else
						color = 0;
				}
			}
			y = 0;
			while(y != tile_size)
			{
				x = 0;
				while(x != tile_size)
				{
					my_mlx_pixel_put(&img, (tile_size * i) + x, (tile_size * j) + y, color);
					x++;
				}
				y++;
			}
			if(map[j][i] == '2')
			{
				my_mlx_pixel_put(&img, (tile_size * i) + tile_size / 2, (tile_size * j) + tile_size / 2, 0x008000);
				x = (tile_size * i) + tile_size / 2;
				y = (tile_size * j) + tile_size / 2;
				m = 0;
				while(m != 30)
				{
					loop_x = x + cos(retation_angle) * m;
					loop_y = y + sin(retation_angle) * m;
					my_mlx_pixel_put(&img,loop_x,loop_y,0xFF0000);
					m++;
				}
			}
			i++;
		}
		j++;
	}
	stock_direction = turn_direction + stock_direction;
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
}
void	ft_window(char **resolution)
{
	width_window = ft_atoi(resolution[0]);
	height_window = ft_atoi(resolution[1]);
	mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, width_window, height_window, "cub3d");
	ft_draw(resolution,get_y);
	mlx_loop(mlx_ptr);
}
