/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 10:04:00 by rcarmen           #+#    #+#             */
/*   Updated: 2022/01/31 17:47:51 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_error(t_errors code, t_main *data)
{
	if (code == INVALID_NUM_OF_ARGS_ERROR)
		ft_putstr_fd("Error: Invalid num of args\n", 2);
	else if (code == FILE_DOES_NOT_OPEN_ERROR)
		ft_putstr_fd("Error: File does not open or no such file exists\n", 2);
	else if (code == INVALID_MAP_ERROR)
		ft_putstr_fd("Error: Invalid map\n", 2);
	(void)data;
	return (code);
}
