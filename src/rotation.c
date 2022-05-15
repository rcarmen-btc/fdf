/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:13:35 by rcarmen           #+#    #+#             */
/*   Updated: 2022/01/31 22:03:51 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	rotate_x(t_main *data, float *x, float *y, int *z)
{
	float	starting_y;

	(void)x;
	starting_y = *y;
	*y = starting_y * cos(data->cos) * *z * sin(data->sin);
	*z = -starting_y * sin(data->sin) * *z * cos(data->cos);
}

int	scan_map_helper(int fd, t_main *data)
{
	char	*line;

	while (get_next_line(fd, &line) == 1)
	{
		data->height++;
		if (data->width != count_of_nums_in_line(line))
		{
			free(line);
			return (ft_error(INVALID_MAP_ERROR, data));
		}
		free(line);
	}
	free(line);
	return (0);
}
