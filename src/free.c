/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 03:12:23 by rcarmen           #+#    #+#             */
/*   Updated: 2022/02/01 03:12:23 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_free(void **ptr)
{
	if (*ptr == NULL)
		return (1);
	free(*ptr);
	*ptr = NULL;
	return (0);
}

int	free_matrix(t_main *data)
{
	int	y;

	y = 0;
	while (y < data->height)
	{
		free(data->z_matix[y]);
		y++;
	}
	free(data->z_matix);
	return (0);
}
