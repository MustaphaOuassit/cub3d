/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:19:48 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/03 17:19:52 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
	if (new == NULL)
		return (new);
	new->content = content;
	new->next = NULL;
	return (new);
}
t_list	*ft_lstlast(t_list *lst)
{
	t_list *current;

	if (!lst)
		return (NULL);
	current = lst;
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last;

	if (*lst == NULL)
		*lst = new;
	else if (lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
void ft_sprite_position(int i,int j)
{
	t_sprite *tmp;
	tmp = (t_sprite *)malloc(sizeof(t_sprite));
	tmp->x = j * g_tile_size + g_tile_size/2;
	tmp->y = i * g_tile_size + g_tile_size/2;

	ft_lstadd_back(&g_sprite_h, ft_lstnew((void *)tmp));
}

float	distance_two_points(float x_one,float y_one,float x_two,float y_two)
{
	return (sqrt((x_one - x_two) * (x_one - x_two) + (y_one - y_two) * (y_one - y_two)));
}

void	ft_sprite_distance()
{
	int x_s;
	int y_s;

	t_list *tmp;
	tmp = g_sprite_h;
	while (tmp!= NULL)
	{
		x_s = ((t_sprite *)tmp->content)->x;
		y_s = ((t_sprite *)tmp->content)->y;

		((t_sprite *)tmp->content)->distance = distance_two_points(g_x,g_y,x_s,y_s);
		tmp = tmp -> next;
	}
}

void ft_sort_sprites()
{

	t_list	*new;
	t_list	*temp;
	t_sprite	*inter;

	new = g_sprite_h;
	while (new != NULL)
	{
		temp = new;
		while (temp->next != NULL)
		{
			if (((t_sprite *)temp->content)->distance < ((t_sprite *)temp->next->content)->distance)
			{
				inter = (t_sprite *)temp->content;
				temp->content = temp->next->content;
				temp->next->content = (void *)inter;
			}
			temp = temp->next;
		}
		new = new->next;
}
}

int	 protect_x(t_sprite *sprite, int i)
{
	int valid;
	valid = 1;
	if (sprite->x_offset + i < 0 ||
				 (int)sprite->x_offset + i >= g_num_rays ||
			 sprite->distance > g_rays[(int)sprite->x_offset + i].distance)
				valid = 0;
	return (valid);
}

void	ft_draw_sprite(t_sprite *sprite, int i, int j)
{
	int color;

	color = g_data_five[((int)g_sprite_width* (j * \
	(int)g_sprite_height/
			(int)sprite->size)) + (i * (int)g_sprite_width /
			(int)sprite->size)];
			if(color != 0)
					my_mlx_pixel_put(&g_img, sprite->x_offset + i,sprite->y_offset + j ,color);
	
}

void	ft_start_draw_sprite(t_sprite *sprite)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < sprite->size - 1)
	{
		if (!protect_x(sprite, i))
		{
			i++;
			continue;
		}
				j = 0;
		while (j < sprite->size - 1)
		{

			if (sprite->y_offset + j < 0 ||
					sprite->y_offset + j >= g_height_window)
			{
				j++;
				continue;
			}
			ft_draw_sprite(sprite, i, j);
			j++;
		}
		i++;
	}
}

void ft_render_sprite(t_sprite *sprite)
{
	float s_angle;

	s_angle = atan2(sprite->y - g_y, sprite->x - g_x);
	while (s_angle - (g_rotation_angle) > M_PI)
		s_angle -= 2 * M_PI;
	while (s_angle - (g_rotation_angle) < -M_PI)
		s_angle += 2 * M_PI;
	s_angle -= g_rotation_angle;
	if (g_height_window > g_width_window)
		sprite->size = (g_height_window/ sprite->distance) * g_tile_size;
	else
		sprite->size = (g_width_window/ sprite->distance) * g_tile_size;
	sprite->y_offset = (g_height_window / 2) - (sprite->size / 2);
	sprite->x_offset = ((s_angle * g_width_window) / (60 * M_PI / 180)) +
		((g_width_window / 2) - (sprite->size / 2));
		ft_start_draw_sprite(sprite);
}

void ft_render_sprites()
{
	t_list *new;

	new = g_sprite_h;
	while (new)
	{
		ft_render_sprite((t_sprite *) new ->content);
		new = new ->next;
	}
}
void	ft_sprite()
{
	ft_sprite_distance();
	ft_sort_sprites();
    ft_render_sprites();
}