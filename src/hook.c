/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:11:19 by rcarmen           #+#    #+#             */
/*   Updated: 2022/01/31 17:50:37 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	key_press_hook(int keycode, t_main *data)
{
	if (keycode == MLX_KEY_RIGHT)
		data->keyflags.right = PRESS;
	if (keycode == MLX_KEY_LEFT)
		data->keyflags.left = PRESS;
	if (keycode == MLX_KEY_PLUS)
		data->keyflags.plus = PRESS;
	if (keycode == MLX_KEY_MINUS)
		data->keyflags.minus = PRESS;
	if (keycode == MLX_KEY_A)
		data->keyflags.a = PRESS;
	if (keycode == MLX_KEY_D)
		data->keyflags.d = PRESS;
	if (keycode == MLX_KEY_W)
		data->keyflags.w = PRESS;
	if (keycode == MLX_KEY_S)
		data->keyflags.s = PRESS;
	else if (keycode == MLX_KEY_UP)
		data->keyflags.up = PRESS;
	else if (keycode == MLX_KEY_DOWN)
		data->keyflags.down = PRESS;
	else if (keycode == MLX_KEY_DOWN)
		data->keyflags.minus = PRESS;
	if (keycode == MLX_KEY_ESCAPE)
		exit_hook(data);
	return (0);
}

int	key_release_hook(int keycode, t_main *data)
{
	if (keycode == MLX_KEY_RIGHT)
		data->keyflags.right = RELEASE;
	if (keycode == MLX_KEY_LEFT)
		data->keyflags.left = RELEASE;
	if (keycode == MLX_KEY_PLUS)
		data->keyflags.plus = RELEASE;
	if (keycode == MLX_KEY_MINUS)
		data->keyflags.minus = RELEASE;
	if (keycode == MLX_KEY_A)
		data->keyflags.a = RELEASE;
	if (keycode == MLX_KEY_D)
		data->keyflags.d = RELEASE;
	if (keycode == MLX_KEY_W)
		data->keyflags.w = RELEASE;
	if (keycode == MLX_KEY_S)
		data->keyflags.s = RELEASE;
	if (keycode == MLX_KEY_UP)
		data->keyflags.up = RELEASE;
	if (keycode == MLX_KEY_DOWN)
		data->keyflags.down = RELEASE;
	return (0);
}

int	exit_hook(void *data)
{
	mlx_clear_window(((t_main *)data)->mlx_ptr, ((t_main *)data)->win_ptr);
	mlx_destroy_image(((t_main *)data)->mlx_ptr, ((t_main *)data)->img.img);
	mlx_destroy_window(((t_main *)data)->mlx_ptr, ((t_main *)data)->win_ptr);
	mlx_destroy_display(((t_main *)data)->mlx_ptr);
	free_matrix(data);
	free(((t_main *)data)->mlx_ptr);
	exit(0);
}

void	set_hooks(t_main *data)
{
	mlx_do_key_autorepeatoff(data->mlx_ptr);
	mlx_hook(data->win_ptr, 2, 1L << 0, key_press_hook, data);
	mlx_hook(data->win_ptr, 3, 1L << 1, key_release_hook, data);
}
