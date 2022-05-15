/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 09:31:33 by rcarmen           #+#    #+#             */
/*   Updated: 2022/02/01 12:26:29 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

float	max_num(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	normalize_matrix(t_main *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->z_matix[y][x] > 400 || data->z_matix[y][x] < -400)
				data->z_matix[y][x] = 0;
			x++;
		}
		y++;
	}
}

int	isinrange(int min, int max, int num)
{
	if (num >= min && num <= max)
		return (1);
	return (0);
}

int	inti_struct(t_main *data)
{
	data->zoom = 400;
	data->cos = 0.8;
	data->sin = 0.8;
	data->x = 0;
	data->y = 0;
	data->z = 100;
	data->color = 0xffffff;
	return (0);
}

int	main(int ac, char **av)
{
	t_main	data;

	if (ac != 2)
		return (ft_error(INVALID_NUM_OF_ARGS_ERROR, &data));
	if (isinrange(INVALID_NUM_OF_ARGS_ERROR, ERROR, scan_map(av[1], &data)))
		return (ERROR);
	if (isinrange(INVALID_NUM_OF_ARGS_ERROR, ERROR, fill_matrix(&data, av[1])))
		return (ERROR);
	inti_struct(&data);
	init_mlx(&data);
	set_hooks(&data);
	mlx_loop_hook(data.mlx_ptr, render_frame, (void *)&data);
	mlx_loop(data.mlx_ptr);
	free_matrix(&data);
	return (0);
}
