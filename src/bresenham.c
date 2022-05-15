/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:13:52 by rcarmen           #+#    #+#             */
/*   Updated: 2022/01/31 21:57:41 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	turn(float *x, float *y, int z, t_main *data)
{
	*x = (*x - *y) * cos(data->cos);
	*y = (*x + *y) * sin(data->sin) - z;
}

void	bresenham_helper_one(t_xy *xy, float *x1, float *y1, t_main *data)
{
	xy->x0 *= data->zoom * 0.1;
	*x1 *= data->zoom * 0.1;
	xy->y0 *= data->zoom * 0.1;
	*y1 *= data->zoom * 0.1;
}

void	bresenham_helper_two(t_xy *xy, float *x1, float *y1, t_main *data)
{
	xy->x0 += (data->screen_width / 2) - data->width + data->x;
	xy->y0 += (data->screen_height / 3) - data->height + data->y;
	*x1 += (data->screen_width / 2) - data->width + data->x;
	*y1 += (data->screen_height / 3) - data->height + data->y;
}

void	print_to_screen(t_main *data, t_xy xy, int z0, int z1)
{
	if (z0 > 1 || z1 > 10)
		my_mlx_pixel_put(data, (int)xy.x0, (int)xy.y0, data->color / 1000);
	else if (z0 < 0 || z1 < 0)
		my_mlx_pixel_put(data, (int)xy.x0, (int)xy.y0, data->color * 1000);
	else
		my_mlx_pixel_put(data, (int)xy.x0, (int)xy.y0, data->color);
}

void	bresenham(t_xy xy, float x1, float y1, t_main *data)
{
	float	xdelta;
	float	ydelta;
	float	max;
	int		z0;
	int		z1;

	z0 = (data->z_matix[(int)xy.y0][(int)xy.x0])
		* ((data->zoom / 6) * (data->z * 0.001));
	z1 = (data->z_matix[(int)y1][(int)x1])
		* ((data->zoom / 6) * (data->z * 0.001));
	bresenham_helper_one(&xy, &x1, &y1, data);
	turn(&xy.x0, &xy.y0, z0, data);
	turn(&x1, &y1, z1, data);
	bresenham_helper_two(&xy, &x1, &y1, data);
	xdelta = x1 - xy.x0;
	ydelta = y1 - xy.y0;
	max = max_num(fabs(xdelta), fabs(ydelta));
	xdelta /= max;
	ydelta /= max;
	while ((int)(xy.x0 - x1) || (int)(xy.y0 - y1))
	{
		print_to_screen(data, xy, z0, z1);
		xy.x0 += xdelta;
		xy.y0 += ydelta;
	}
}
