/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:22:15 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/12 16:41:14 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sprite(void)
{
	ft_sprite_distance();
	ft_sort_sprites();
	ft_render_sprites();
}

int		*get_colors(int color)
{
	int		*colors;

	if (!(colors = malloc(3 * sizeof(int))))
		ft_error();
	colors[0] = ((color >> 16) & 0xFF);
	colors[1] = ((color >> 8) & 0xFF);
	colors[2] = ((color) & 0xFF);
	return (colors);
}

void	ft_screenshot(void)
{
	int				*color;
	t_header		info;
	unsigned char	*header;

	header = ft_calloc(54, sizeof(unsigned char));
	ft_init_header(header, &info, 10);
	if (!(info.buf = malloc(info.image_size)))
		ft_error();
	while (info.row > 0)
	{
		info.col = 0;
		while (info.col < info.width)
		{
			color = get_colors(info.data[(g_height_window - info.row) * \
					g_width_window + info.col]);
			info.buf[info.row * info.w_in_b + info.col * 3 + 0] = color[2];
			info.buf[info.row * info.w_in_b + info.col * 3 + 1] = color[1];
			info.buf[info.row * info.w_in_b + info.col * 3 + 2] = color[0];
			free(color);
			info.col++;
		}
		info.row--;
	}
	fill_image(header, info, (char *)info.buf);
}

int		ft_check_i(int i)
{
	int error;

	error = 0;
	if (i == 1)
		g_text_error = "Entre the file in NO";
	else
		g_text_error = "Info invalid in NO";
	return (error);
}
