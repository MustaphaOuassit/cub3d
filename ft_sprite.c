/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:19:48 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/11 19:17:25 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

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

void	ft_sprite_position(int i, int j)
{
	t_sprite *tmp;

	tmp = (t_sprite *)malloc(sizeof(t_sprite));
	tmp->x = j * g_tile_size + g_tile_size / 2;
	tmp->y = i * g_tile_size + g_tile_size / 2;
	ft_lstadd_back(&g_sprite_h, ft_lstnew((void *)tmp));
}

float	distance_two_points(float x_one, float y_one, float x_two, float y_two)
{
	return (sqrt((x_one - x_two) *
			(x_one - x_two) +
			(y_one - y_two) *
			(y_one - y_two)));
}
