/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 12:33:43 by mouassit          #+#    #+#             */
/*   Updated: 2021/01/24 12:33:46 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_error()
{
	if (mlx_ptr && win_ptr)
		mlx_destroy_window(mlx_ptr, win_ptr);
	exit(1);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	void			*ptr;

	i = 0;
	ptr = (char *)malloc(count * size);
	while (count * size > i)
	{
		((unsigned char*)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == src)
		return (dest);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

void	ft_init_header(unsigned char *header, t_header *info, int i)
{
	i = 0;
	info->width = width_window;
	info->height = height_window;
	info->bitcount = 24;
	info->bi_planes = 1;
	info->w_in_b = ((info->width * info->bitcount + 31) / 32) * 4;
	info->image_size = info->w_in_b * info->height;
	info->bi_size = 40;
	info->bf_off_bits = 54;
	info->file_size = 54 + info->image_size;
	info->data = (int *)mlx_get_data_addr(img.img, &i, &i, &i);
	info->row = info->height - 1;
	info->col = 0;
	ft_memcpy(header, "BM", 2);
	ft_memcpy(header + 2, &info->file_size, 4);
	ft_memcpy(header + 10, &info->bf_off_bits, 4);
	ft_memcpy(header + 14, &info->bi_size, 4);
	ft_memcpy(header + 18, &info->width, 4);
	ft_memcpy(header + 22, &info->height, 4);
	ft_memcpy(header + 26, &info->bi_planes, 2);
	ft_memcpy(header + 28, &info->bitcount, 2);
	ft_memcpy(header + 34, &info->image_size, 4);
}

void	fill_image(unsigned char *header, t_header header_info, char *buf)
{
	int fout;

	fout = open("screen.bmp", O_WRONLY | O_CREAT, 0644);
	write(fout, header, 54);
	write(fout, buf, header_info.image_size);
	close(fout);
	free(header_info.buf);
	free(header);
	exit(1);
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
			color = get_colors(info.data[(height_window - info.row) * \
				width_window + info.col]);
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