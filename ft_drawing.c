/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 09:53:48 by mouassit          #+#    #+#             */
/*   Updated: 2020/12/19 09:53:52 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_check_y(int y, int wall_strip_height)
{
	int distance_from_top;
	distance_from_top = y + (wall_strip_height / 2) - (height_window / 2);
	return (distance_from_top * ((float)tile_size / wall_strip_height));
}

void	ft_3d_walls(int x)
{
	float j;
	float i;
	float ray_distance;
	int result;
	int n;

	j = 0; 
	i = 0;
	ray_distance = distance * cos(ray_angle - rotation_angle);
	distance_projection = (width_window / 2) / tan(1.0471975512 / 2);
	wall_height = (tile_size / ray_distance) * distance_projection;
	while (i < ((height_window / 2) - (wall_height / 2)))
	{
		my_mlx_pixel_put(&img,x,i,color_sky);
		i++;
	}
	i = (height_window / 2) - (wall_height / 2);
	if (was_vertical)
		result = fmod(wall_y,tile_size);
	else
		result = fmod(wall_x,tile_size);
    while (j < wall_height && i < height_window)
    {			

		if(i > 0)
		{
			n = (ft_check_y(i,wall_height) * tile_size) + result;
			if((n >= 4096) || (n < 0))
			{	
				n = 4095;
			}
			if((was_vertical) && (is_ray_facing_left))
			{
				my_mlx_pixel_put(&img,x,i,data_one[n]);
			}
			if((was_vertical) && (is_ray_facing_right))
			{
				my_mlx_pixel_put(&img,x,i,data_two[n]);
			}
			if((was_vertical == 0) && (is_ray_facing_up))
			{
				my_mlx_pixel_put(&img,x,i,data_three[n]);
			}
			if((was_vertical == 0) && (is_ray_facing_down))
			{
				my_mlx_pixel_put(&img,x,i,data_four[n]);
			}
		}
        i++;
        j++;
    }
	while (i < height_window)
	{
		my_mlx_pixel_put(&img,x,i,color_floor);
		i++;
	}
	
}

int	deal_key_release()
{
	turn_direction = 0;
	walk_direction = 0;
	return(0);
}

int deal_key(int key)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if(key == 13)
		walk_direction = 1;
	if(key == 1)
		walk_direction = -1;
	if(key == 2)
	{
		walk_direction = 1;
		b = M_PI / 2;
	}
	if(key == 0)
	{
		walk_direction = -1;
		b = M_PI / 2;
	}
	if(key == 124)
		turn_direction = 1;
	if(key == 123)
		turn_direction = -1;
	if(key == 53)
		exit(1);
	while (j < height_window)
	{
		i = 0;
		while (i < width_window)
		{
			my_mlx_pixel_put(&img,i,j,0x000000);
			i++;
		}
		j++;
	}
	ft_drawing();

	return(0);
}

int            ft_close(void)
{
    mlx_destroy_window(mlx_ptr, win_ptr);
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
	while(i != get_y)
	{
		if(ft_strlen(map[i]) > len)
			toll = ft_strlen(map[i]);
		len = ft_strlen(map[i]);
		i++;
	}
}

void    ft_draw_line(float x_one,float y_one,float x_zero,float y_zero)
{
    float dx;
    float dy;
    float steps;
    float x_inc;
    float y_inc;
    float i;
    i = 0;
    dx = x_one - x_zero;
    dy = y_one - y_zero;

    if (fabsf(dx) > fabsf(dy))
        steps = fabsf(dx);
    else 
        steps = fabsf(dy);
    x_inc = dx / steps;
    y_inc = dy / steps;
    while (i < steps)
    {        
        my_mlx_pixel_put(&img,x_zero,y_zero,0xFF0000);
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
    position_x = (i / tile_size);
    position_y = (j / tile_size);
	if((position_y >= get_y) || (position_x >= (int)ft_strlen(map[position_y])))
		return(1);
    if((map[position_y][position_x] == '1') || (map[position_y][position_x] == ' ') || (map[position_y][position_x] == '\0'))
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
    position_x = (i / tile_size);
    position_y = (j / tile_size);
	if((position_y >= get_y) || (position_x >= (int)ft_strlen(map[position_y])))
		return(1);
    if((map[position_y][position_x] == '1') || (map[position_y][position_x] == ' ') || (map[position_y][position_x] == '\0'))
    	wallat = 1;
    else
		wallat = 0;
    return(wallat);
}

void        ft_ray_push(double x2, double y2)
{
    double      y1;
    double      x1;
    double      xinc;
    double      yinc;
    int         steps;
	int g_tilecolor;

    x1 = x;
    y1 = y;
    g_tilecolor = 16711680;
    steps = abs((int)x2 - (int)x1) > abs((int)y2 - (int)y1) ? abs((int)x2 -
            (int)x1) : abs((int)y2 - (int)y1);
    xinc = (x2 - x1) / (double)steps;
    yinc = (y2 - y1) / (double)steps;
    x2 = -1;
    while (++x2 <= steps)
    {	
        x1 = x1 + xinc;
        y1 = y1 + yinc;
		my_mlx_pixel_put(&img,x1,y1,0xFF0000);
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
	while(i < num_rays)
	{
	ray_angle = ft_normalaize_angle(ray_angle);
	ft_check_ray_face();
	wall_x = 0;
	wall_y = 0;
	distance = 0;
	was_vertical = 0;
	ft_cast();
	ft_3d_walls(i);
	g_rays->distance = distance;
	ray_angle = ray_angle + (60 * (M_PI / 180) / num_rays);

		i++;
	}
}

float	ft_normalaize_angle(float angle)
{
	fo_v = 2 * M_PI;
	angle = fmod(angle,fo_v);
	if(angle < 0)
		angle = fo_v + angle;
	return(angle);
}

void	ft_cast()
{

	found_horizontal = 0;
	wall_horizontal_x = 0;
	wall_horizontal_y = 0;
	 closet_one_y = (int)(y / tile_size) * tile_size;
	 if(is_ray_facing_down == 1)
		 closet_one_y = closet_one_y + tile_size;
	 else
	 	closet_one_y = closet_one_y + 0;
	 closet_one_x = x + ((closet_one_y - y) / tan(ray_angle));
	 //////////////////////////
	 y_step = tile_size;
	 if (is_ray_facing_up == 1)
		 y_step = y_step * -1;
	 else
	 {
		 if(is_ray_facing_down == 1)
		 	y_step = y_step * 1;
	 }
	 x_step = tile_size / tan(ray_angle);
	 if((is_ray_facing_left == 1) && (x_step > 0))
	 	x_step = x_step * -1;
	  else
		  x_step = x_step * 1;
	if((is_ray_facing_right == 1) && (x_step < 0))
		x_step = x_step * -1;
	else
		x_step = x_step * 1;
	/////////////////
	next_one_x = closet_one_x;
	next_one_y = closet_one_y;
		while((next_one_x >= 0) && (next_one_x <= ((toll - 1) * tile_size)) && (next_one_y >= 0) && (next_one_y <= ((get_y - 1) * tile_size)))
		{
			if(ft_has_wallat(next_one_x,next_one_y -  is_ray_facing_up) == 1)
			{
				found_horizontal = 1;
				wall_horizontal_x = next_one_x;
				wall_horizontal_y = next_one_y;
				break;
			}
			else
			{
				next_one_x = next_one_x + x_step;
				next_one_y = next_one_y + y_step;
			}
		}
	//////////////------------------vertical-----------------------------/////////////////////

	found_vertical = 0;
	wall_vertical_x = 0;
	wall_vertical_y = 0;
	 closet_one_x = (int)(x / tile_size) * tile_size;
	 if(is_ray_facing_right == 1)
		 closet_one_x = closet_one_x + tile_size;
	 else
	 	closet_one_x = closet_one_x + 0;
	 closet_one_y = y + ((closet_one_x - x) * tan(ray_angle));
	 //////////////////////////
	 x_step = tile_size;
	 if (is_ray_facing_left == 1)
		 x_step = x_step * -1;
	 else
	 {
		 if(is_ray_facing_right == 1)
		 	x_step = x_step * 1;
	 }
	 y_step = tile_size * tan(ray_angle);
	 if((is_ray_facing_up == 1) && (y_step > 0))
	 	y_step = y_step * -1;
	  else
		  y_step = y_step * 1;
	if((is_ray_facing_down == 1) && (y_step < 0))
		y_step = y_step * -1;
	else
		y_step = y_step * 1;
	/////////////////
	next_one_v_x = closet_one_x;
	next_one_v_y = closet_one_y;
		while((next_one_v_x >= 0) && (next_one_v_x <= ((toll - 1) * tile_size)) && (next_one_v_y >= 0) && (next_one_v_y <= ((get_y - 1) * tile_size)))
		{
			if(ft_has_wallat(next_one_v_x - is_ray_facing_left,next_one_v_y) == 1)
			{
				found_vertical = 1;
				wall_vertical_x = next_one_v_x;
				wall_vertical_y = next_one_v_y;
				break;
			}
			else
			{
				next_one_v_x = next_one_v_x + x_step;
				next_one_v_y = next_one_v_y + y_step;
			}
		}
		if(found_horizontal == 1)
			horizontal_distance = ft_between_points(x,y,wall_horizontal_x,wall_horizontal_y);
		else
			horizontal_distance = INT64_MAX;
		if(found_vertical == 1)
			vertical_distance = ft_between_points(x,y,wall_vertical_x,wall_vertical_y);
		else
			vertical_distance = INT64_MAX;
		if(horizontal_distance < vertical_distance)
			wall_x = wall_horizontal_x;
		else
			wall_x = wall_vertical_x;
		if(horizontal_distance < vertical_distance)
			wall_y = wall_horizontal_y;
		else
			wall_y = wall_vertical_y;
		if (horizontal_distance < vertical_distance)
			distance = horizontal_distance;
		else
			distance = vertical_distance;
		if(vertical_distance < horizontal_distance)
			was_vertical = 1;
		else
			was_vertical = 0;
}

void	ft_check_ray_face()
{
	if((ray_angle > 0) && (ray_angle < M_PI))
	{
		is_ray_facing_down = 1;
		is_ray_facing_up = 0;
	}
	else
	{
		is_ray_facing_down = 0;
		is_ray_facing_up = 1;
	}
	if((ray_angle < (0.5 * M_PI)) || (ray_angle > (1.5 * M_PI)))
	{
		is_ray_facing_right = 1;
		is_ray_facing_left = 0;
	}
	else
	{
		is_ray_facing_right = 0;
		is_ray_facing_left = 1;
	}
}

void	ft_draw_player()
{
	new_playerx = x + cos(rotation_angle + b) * move_step * (walk_direction * 4);
	new_playery = y + sin(rotation_angle + b) * move_step * (walk_direction * 4);
    if(ft_has_wallat_p(new_playerx, new_playery) == 0)
    {
        x = x + cos(rotation_angle + b) * move_step * (walk_direction);
        y = y + sin(rotation_angle + b) * move_step * (walk_direction);
    }
		
	b = 0;
}

void	ft_draw_map()
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(map[j])
	{
		i = 0;
		while(map[j][i])
		{
			if(((map[j][i] == 'N') || (map[j][i] == 'S') || (map[j][i] == 'E') || (map[j][i] == 'W')) && (x == 0))
			{
				x = (tile_size * i) + tile_size / 2;
				y = (tile_size * j) + tile_size / 2;
			}
			if(map[j][i] == '2')
				ft_sprite_position(i,j);
			i++;
		}
		j++;
	}
}

void	ft_drawing()
{
	rotation_angle = (check_direction) + (turn_direction + stock_direction)  * 10 * (M_PI / 180);
	ray_angle = rotation_angle - ((60 * M_PI / 180) / 2);
	num_rays = width_window;
	move_step = 20;
	stock_direction = turn_direction + stock_direction;
	stock_walk = walk_direction + stock_walk;
	g_sprite_h = NULL;
	ft_draw_map();
	ft_draw_player();
	g_rays = malloc((num_rays) *  sizeof(t_rays));
	ft_draw_rays();
	ft_sprite();
	move_step = 0;
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_hook(win_ptr,2,0,&deal_key,&img);
	mlx_hook(win_ptr,3,0,&deal_key_release,&img);
	mlx_hook(win_ptr, 17, 1L << 17, ft_close, (void *)0);
}

void	ft_window()
{
	int error;

	error = 0;
	if(side_p)
	{
		if(width_window > 2048)
			width_window = 2048;
		if(height_window > 1111)
			height_window = 1111;
		if(side_p == 'N')
			check_direction = (M_PI / 2) + (M_PI / 2) + (M_PI / 2);
		if(side_p == 'S')
			check_direction = M_PI / 2;
		if(side_p == 'E')
			check_direction = M_PI + M_PI;
		if(side_p == 'W')
			check_direction = M_PI;
		if (!(textur_one = mlx_xpm_file_to_image(mlx_ptr,textur_so,&t,&t))) 
		{
			printf("Error :\n%s Invalid file\n",textur_so);
			error = 1;
		}
		if (!(textur_two = mlx_xpm_file_to_image(mlx_ptr, textur_we,&t,&t))) 
		{
			if(error == 0)
			{
				printf("Error\n%s Invalid file\n",textur_we);
				error = 1;
			}
		}
		if (!(textur_three = mlx_xpm_file_to_image(mlx_ptr, textur_no,&t,&t))) 
		{
			if(error == 0)
			{
				printf("Error\n%s Invalid file\n",textur_no);
				error = 1;
			}
		}
		if (!(textur_four = mlx_xpm_file_to_image(mlx_ptr, textur_ea,&t,&t)))
		{
			if(error == 0)
			{
				printf("Error\n%s Invalid file\n",textur_ea);
				error = 1;
			}
		}
		if (!(textur_five = mlx_xpm_file_to_image(mlx_ptr, textur_sprite,&g_sprite_width,&g_sprite_height)))
		{
			if(error == 0)
			{
				printf("Error\n%s Invalid file\n",textur_sprite);
				error = 1;
			}
		}
		if((color_f == 0) && ((f_r <= 255) && ((f_r >= 0))) && ((f_g <= 255) && ((f_g >= 0))) && ((f_b <= 255) && ((f_b >= 0))))
		{
			color_floor = f_r * 65536 + f_g * 256 + f_b;
		}
		else
		{
			if(error == 0)
			{
				printf("Error\nColor no valid in F\n");
				error = 1;
			}
		}
		if((color_c == 0) && ((c_r <= 255) && ((c_r >= 0))) && ((c_g <= 255) && ((c_g >= 0))) && ((c_b <= 255) && ((c_b >= 0))))
		{
			color_sky = c_r * 65536 + c_g * 256 + c_b;
		}
		else
		{
			if(error == 0)
			{
				printf("Error\nColor no valid in C\n");
				error = 1;
			}
		}
		if(error == 0)
		{
			data_one = (int *)mlx_get_data_addr(textur_one, &t,&t,&t);
			data_two = (int *)mlx_get_data_addr(textur_two, &t,&t,&t);
			data_three = (int *)mlx_get_data_addr(textur_three, &t,&t,&t);
			data_four = (int *)mlx_get_data_addr(textur_four, &t,&t,&t);
			data_five = (int *)mlx_get_data_addr(textur_five, &t,&t,&t);
			x = 0;
			y = 0;
    		win_ptr = mlx_new_window(mlx_ptr, width_window, height_window, "cub3d");
			img.img = mlx_new_image(mlx_ptr, width_window, height_window);
			img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
			ft_toll_line();
			ft_drawing();
			if(save == 1)
				ft_screenshot();
			else
				mlx_loop(mlx_ptr);
		}
	}
	else
	{
		if(all_info == 8)
			printf("Error\nNo Player in the map\n");
		else
			printf("Error\nlack the identifier\n");
	}
	

}