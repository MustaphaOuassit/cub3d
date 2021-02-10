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

void	ft_ptr_ln(char **str)
{
	int j;
	j = 0;
	while(str[j] != '\0')
		j++;
	fr_ee(str,j);
}
int		ft_check_y(int y, int wall_strip_height)
{
	int distance_from_top;
	distance_from_top = y + (wall_strip_height / 2) - (g_height_window / 2);
	return (distance_from_top * ((float)g_tile_size / wall_strip_height));
}

void	ft_3d_walls(int x)
{
	float j;
	float i;
	float ray_distance;
	int result;

	j = 0; 
	i = 0;
	ray_distance = g_distance * cos(g_ray_angle - g_rotation_angle);
	g_distance_projection = (g_width_window / 2) / tan(1.0471975512 / 2);
	g_wall_height = (g_tile_size / ray_distance) * g_distance_projection;
	while (i < ((g_height_window / 2) - (g_wall_height / 2)))
	{
		my_mlx_pixel_put(&g_img,x,i,g_color_sky);
		i++;
	}
	i = (g_height_window / 2) - (g_wall_height / 2);
	if (g_was_vertical)
		result = fmod(g_wall_y,g_tile_size);
	else
		result = fmod(g_wall_x,g_tile_size);
	ft_app_colors(i, j, x, result);
}

int	deal_key_release()
{
	g_turn_direction = 0;
	g_walk_direction = 0;
	return(0);
}

int deal_key(int key)
{
	int i;

	i = 0;
	if(key == 13)
		g_walk_direction = 1;
	if(key == 1)
		g_walk_direction = -1;
	if(key == 2)
	{
		g_walk_direction = 1;
		g_b = M_PI / 2;
	}
	if(key == 0)
	{
		g_walk_direction = -1;
		g_b = M_PI / 2;
	}
	if(key == 124)
		g_turn_direction = 1;
	if(key == 123)
		g_turn_direction = -1;
	if(key == 53)
		exit(1);
	ft_mov();
	return(0);
}

int            ft_close(void)
{
    mlx_destroy_window(g_mlx_ptr, g_win_ptr);
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
	while(i != g_get_y)
	{
		if(ft_strlen(g_map[i]) > len)
			g_toll = ft_strlen(g_map[i]);
		len = ft_strlen(g_map[i]);
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
        my_mlx_pixel_put(&g_img,x_zero,y_zero,0xFF0000);
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
    position_x = (i / g_tile_size);
    position_y = (j / g_tile_size);
	if((position_y >= g_get_y) || (position_x >= (int)ft_strlen(g_map[position_y])))
		return(1);
    if((g_map[position_y][position_x] == '1') 
	|| (g_map[position_y][position_x] == ' ') 
	|| (g_map[position_y][position_x] == '\0'))
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
    position_x = (i / g_tile_size);
    position_y = (j / g_tile_size);
	if((position_y >= g_get_y) || (position_x >= (int)ft_strlen(g_map[position_y])))
		return(1);
    if((g_map[position_y][position_x] == '1') || (g_map[position_y][position_x] == ' ') || (g_map[position_y][position_x] == '\0'))
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
	int			g_tilecolor;

    x1 = g_x;
    y1 = g_y;
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
		my_mlx_pixel_put(&g_img,x1,y1,0xFF0000);
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
	while(i < g_num_rays)
	{
	g_ray_angle = ft_normalaize_angle(g_ray_angle);
	ft_check_ray_face();
	g_wall_x = 0;
	g_wall_y = 0;
	g_distance = 0;
	g_was_vertical = 0;
	ft_cast();
	ft_3d_walls(i);
	g_rays[i].distance = g_distance;
	g_ray_angle = g_ray_angle + (60 * (M_PI / 180) / g_num_rays);

		i++;
	}
}

float	ft_normalaize_angle(float angle)
{
	g_fo_v = 2 * M_PI;
	angle = fmod(angle,g_fo_v);
	if(angle < 0)
		angle = g_fo_v + angle;
	return(angle);
}

void	ft_cast()
{

	g_found_horizontal = 0;
	g_wall_horizontal_x = 0;
	g_wall_horizontal_y = 0;
	 g_closet_one_y = (int)(g_y / g_tile_size) * g_tile_size;
	 if(g_is_ray_facing_down == 1)
		 g_closet_one_y = g_closet_one_y + g_tile_size;
	 else
	 	g_closet_one_y = g_closet_one_y + 0;
	 g_closet_one_x = g_x + ((g_closet_one_y - g_y) / tan(g_ray_angle));
	 //////////////////////////
	 g_y_step = g_tile_size;
	 if (g_is_ray_facing_up == 1)
		 g_y_step = g_y_step * -1;
	 else
	 {
		 if(g_is_ray_facing_down == 1)
		 	g_y_step = g_y_step * 1;
	 }
	 g_x_step = g_tile_size / tan(g_ray_angle);
	 if((g_is_ray_facing_left == 1) && (g_x_step > 0))
	 	g_x_step = g_x_step * -1;
	  else
		  g_x_step = g_x_step * 1;
	if((g_is_ray_facing_right == 1) && (g_x_step < 0))
		g_x_step = g_x_step * -1;
	else
		g_x_step = g_x_step * 1;
	/////////////////
	g_next_one_x = g_closet_one_x;
	g_next_one_y = g_closet_one_y;
		while((g_next_one_x >= 0) && (g_next_one_x <= ((g_toll - 1) * g_tile_size)) && (g_next_one_y >= 0) && (g_next_one_y <= ((g_get_y - 1) * g_tile_size)))
		{
			if(ft_has_wallat(g_next_one_x,g_next_one_y -  g_is_ray_facing_up) == 1)
			{
				g_found_horizontal = 1;
				g_wall_horizontal_x = g_next_one_x;
				g_wall_horizontal_y = g_next_one_y;
				break;
			}
			else
			{
				g_next_one_x = g_next_one_x + g_x_step;
				g_next_one_y = g_next_one_y + g_y_step;
			}
		}
	//////////////------------------vertical-----------------------------/////////////////////

	g_found_vertical = 0;
	g_wall_vertical_x = 0;
	g_wall_vertical_y = 0;
	 g_closet_one_x = (int)(g_x / g_tile_size) * g_tile_size;
	 if(g_is_ray_facing_right == 1)
		 g_closet_one_x = g_closet_one_x + g_tile_size;
	 else
	 	g_closet_one_x = g_closet_one_x + 0;
	 g_closet_one_y = g_y + ((g_closet_one_x - g_x) * tan(g_ray_angle));
	 //////////////////////////
	 g_x_step = g_tile_size;
	 if (g_is_ray_facing_left == 1)
		 g_x_step = g_x_step * -1;
	 else
	 {
		 if(g_is_ray_facing_right == 1)
		 	g_x_step = g_x_step * 1;
	 }
	 g_y_step = g_tile_size * tan(g_ray_angle);
	 if((g_is_ray_facing_up == 1) && (g_y_step > 0))
	 	g_y_step = g_y_step * -1;
	  else
		  g_y_step = g_y_step * 1;
	if((g_is_ray_facing_down == 1) && (g_y_step < 0))
		g_y_step = g_y_step * -1;
	else
		g_y_step = g_y_step * 1;
	/////////////////
	g_next_one_v_x = g_closet_one_x;
	g_next_one_v_y = g_closet_one_y;
		while((g_next_one_v_x >= 0) && (g_next_one_v_x <= ((g_toll - 1) * g_tile_size)) && (g_next_one_v_y >= 0) && (g_next_one_v_y <= ((g_get_y - 1) * g_tile_size)))
		{
			if(ft_has_wallat(g_next_one_v_x - g_is_ray_facing_left,g_next_one_v_y) == 1)
			{
				g_found_vertical = 1;
				g_wall_vertical_x = g_next_one_v_x;
				g_wall_vertical_y = g_next_one_v_y;
				break;
			}
			else
			{
				g_next_one_v_x = g_next_one_v_x + g_x_step;
				g_next_one_v_y = g_next_one_v_y + g_y_step;
			}
		}
		if(g_found_horizontal == 1)
			g_horizontal_distance = ft_between_points(g_x,g_y,g_wall_horizontal_x,g_wall_horizontal_y);
		else
			g_horizontal_distance = INT64_MAX;
		if(g_found_vertical == 1)
			g_vertical_distance = ft_between_points(g_x,g_y,g_wall_vertical_x,g_wall_vertical_y);
		else
			g_vertical_distance = INT64_MAX;
		if(g_horizontal_distance < g_vertical_distance)
			g_wall_x = g_wall_horizontal_x;
		else
			g_wall_x = g_wall_vertical_x;
		if(g_horizontal_distance < g_vertical_distance)
			g_wall_y = g_wall_horizontal_y;
		else
			g_wall_y = g_wall_vertical_y;
		if (g_horizontal_distance < g_vertical_distance)
			g_distance = g_horizontal_distance;
		else
			g_distance = g_vertical_distance;
		if(g_vertical_distance < g_horizontal_distance)
			g_was_vertical = 1;
		else
			g_was_vertical = 0;
}

void	ft_check_ray_face()
{
	if((g_ray_angle > 0) && (g_ray_angle < M_PI))
	{
		g_is_ray_facing_down = 1;
		g_is_ray_facing_up = 0;
	}
	else
	{
		g_is_ray_facing_down = 0;
		g_is_ray_facing_up = 1;
	}
	if((g_ray_angle < (0.5 * M_PI)) || (g_ray_angle > (1.5 * M_PI)))
	{
		g_is_ray_facing_right = 1;
		g_is_ray_facing_left = 0;
	}
	else
	{
		g_is_ray_facing_right = 0;
		g_is_ray_facing_left = 1;
	}
}

void	ft_draw_player()
{
	g_new_playerx = g_x + cos(g_rotation_angle + g_b) * g_move_step * (g_walk_direction * 4);
	g_new_playery = g_y + sin(g_rotation_angle + g_b) * g_move_step * (g_walk_direction * 4);
    if(ft_has_wallat_p(g_new_playerx, g_new_playery) == 0)
    {
        g_x = g_x + cos(g_rotation_angle + g_b) * g_move_step * (g_walk_direction);
        g_y = g_y + sin(g_rotation_angle + g_b) * g_move_step * (g_walk_direction);
    }
		
	g_b = 0;
}

void	ft_draw_map()
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(g_map[j])
	{
		i = 0;
		while(g_map[j][i])
		{
			if(((g_map[j][i] == 'N') || (g_map[j][i] == 'S') || (g_map[j][i] == 'E') || (g_map[j][i] == 'W')) && (g_x == 0))
			{
				g_x = (g_tile_size * i) + g_tile_size / 2;
				g_y = (g_tile_size * j) + g_tile_size / 2;
			}
			i++;
		}
		j++;
	}
}

void	ft_drawing()
{
	g_rotation_angle = (g_check_direction) + (g_turn_direction + g_stock_direction)  * 10 * (M_PI / 180);
	g_ray_angle = g_rotation_angle - ((60 * M_PI / 180) / 2);
	g_move_step = 20;
	g_stock_direction = g_turn_direction + g_stock_direction;
	g_stock_walk = g_walk_direction + g_stock_walk;
	ft_draw_map();
	ft_draw_player();
	ft_draw_rays();
	ft_sprite();
	g_move_step = 0;
	mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_img.img, 0, 0);
	mlx_hook(g_win_ptr,2,0,&deal_key,&g_img);
	mlx_hook(g_win_ptr,3,0,&deal_key_release,&g_img);
	mlx_hook(g_win_ptr, 17, 1L << 17, ft_close, (void *)0);
}

void	ft_window()
{ 
	int error;

	error = 0;
	if(g_side_p)
	{
		ft_organize();
		error = ft_texturs(error);
		error = ft_colors(error);
		if(error == 0)
			ft_put_data();
	}
	else
	{
		if(g_all_info == 8)
		{
			write(1,"Error\n",7);
			write(1,"No Player in the map\n",21);
		}
		else
		{
			write(1,"Error\n",7);
			write(1,"lack the identifier\n",20);
		}
	}
}