/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 09:31:58 by rcarmen           #+#    #+#             */
/*   Updated: 2022/02/01 03:39:28 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	init_matrix(t_main *data)
{
	int	i;

	data->z_matix = (int **)ft_calloc(data->height + 1, sizeof(int *));
	if (!data->z_matix)
		return (ft_error(CALLOC_ERROR, data));
	i = 0;
	while (i < data->height)
	{
		data->z_matix[i++] = (int *)ft_calloc(data->width, sizeof(int));
		if (!data->z_matix)
			return (ft_error(CALLOC_ERROR, data));
	}
	return (0);
}

int	fill_matrix_helper(int fd, t_main *data)
{
	char	*line;
	char	**nums;
	int		i;
	int		j;

	j = 0;
	while (get_next_line(fd, &line) == 1)
	{
		nums = ft_split(line, ' ');
		i = 0;
		while (nums[i])
		{
			data->z_matix[j][i] = ft_atoi(nums[i]);
			free(nums[i++]);
		}
		free(nums);
		free(line);
		j++;
	}
	free(line);
	return (0);
}

int	fill_matrix(t_main *data, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_error(FILE_DOES_NOT_OPEN_ERROR, data));
	if (init_matrix(data))
		return (ft_error(CALLOC_ERROR, data));
	fill_matrix_helper(fd, data);
	close(fd);
	return (0);
}

int	count_of_nums_in_line(char *line)
{
	char	**nums;
	int		width;

	width = 0;
	nums = ft_split(line, ' ');
	while (nums[width])
	{
		free(nums[width]);
		width++;
	}
	free(nums);
	return (width);
}

int	scan_map(char *filename, t_main *data)
{
	int		fd;
	char	*line;
	char	*buf;

	fd = open(filename, O_RDONLY);
	if (fd == -1 || read(fd, buf, 0) == -1)
		return (ft_error(FILE_DOES_NOT_OPEN_ERROR, data));
	if (get_next_line(fd, &line) == 1)
	{
		data->width = count_of_nums_in_line(line);
		data->height++;
		free(line);
	}
	if (scan_map_helper(fd, data) == INVALID_MAP_ERROR)
		return (INVALID_MAP_ERROR);
	close(fd);
	return (fd);
}
