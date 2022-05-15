/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 13:58:13 by rcarmen           #+#    #+#             */
/*   Updated: 2022/02/01 12:28:51 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	smooth_move(t_main *data)
{
	if (data->keyflags.right == PRESS)
		data->color += 0x9a9f95;
	if (data->keyflags.left == PRESS)
		data->color -= 0x9a9f95;
	if (data->keyflags.plus == PRESS)
		data->zoom += 3;
	if (data->keyflags.minus == PRESS && data->zoom > 1)
		data->zoom -= 3;
	if (data->keyflags.d == PRESS)
		data->x -= 3;
	if (data->keyflags.a == PRESS)
		data->x += 3;
	if (data->keyflags.w == PRESS)
		data->y += 3;
	if (data->keyflags.s == PRESS)
		data->y -= 3;
	if (data->keyflags.up == PRESS)
		data->z += 1;
	if (data->keyflags.down == PRESS)
		data->z -= 1;
}

void	draw_background(t_main *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->screen_height)
	{
		x = 0;
		while (x < data->screen_width)
		{
			my_mlx_pixel_put(data, x, y, 0x000000);
			x++;
		}
		y++;
	}
	normalize_matrix(data);
}

void	draw_isometric(t_main *data)
{
	t_xy	xy;

	xy.y0 = 0;
	while (xy.y0 < data->height)
	{
		xy.x0 = 0;
		while (xy.x0 < data->width)
		{
			if (xy.x0 < data->width - 1)
				bresenham(xy, xy.x0 + 1, xy.y0, data);
			if (xy.y0 < data->height - 1)
				bresenham(xy, xy.x0, xy.y0 + 1, data);
			xy.x0++;
		}
		xy.y0++;
	}
}

int	render_frame(void *tmp)
{
	t_main	*data;

	data = tmp;
	smooth_move(data);
	draw_background(data);
	draw_isometric(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	mlx_do_sync(data->mlx_ptr);
	return (0);
}
