/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 13:48:01 by rcarmen           #+#    #+#             */
/*   Updated: 2022/02/01 12:21:32 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	my_mlx_pixel_put(t_main *data, int x, int y, int color)
{
	char	*dst;

	if (x >= data->screen_width || y >= data->screen_height || x < 0 || y < 0)
		return ;
	dst = data->img.addr + (y * data->img.line_length + x
			* (data->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	init_mlx(t_main *data)
{
	data->mlx_ptr = mlx_init();
	mlx_get_screen_size(data->mlx_ptr, &data->screen_width,
		&data->screen_height);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->screen_width,
			data->screen_height, "fdf");
	data->img.img = mlx_new_image(data->mlx_ptr, data->screen_width,
			data->screen_height);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*mem;
	size_t			i;
	size_t			sl;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	sl = ft_strlen(s + start);
	if (sl < len)
		len = sl;
	mem = malloc(len + 1);
	if (!(mem))
		return (NULL);
	i = 0;
	while (*s != '\0' && len > 0)
	{
		mem[i] = s[i + start];
		i++;
		len--;
	}
	mem[i] = '\0';
	return (mem);
}

ssize_t	get_rs(char *buf, int fd, ssize_t *rs)
{
	*rs = read(fd, buf, BUFFER_SIZE);
	return (*rs);
}
