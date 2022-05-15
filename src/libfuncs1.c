/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfuncs1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:14:07 by rcarmen           #+#    #+#             */
/*   Updated: 2022/02/01 03:26:08 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

size_t	ft_strlen(const char *s)
{
	size_t	j;

	j = 0;
	while (s[j] != '\0')
		j++;
	return (j);
}

void	ft_putstr_fd(char *s, int fd)
{
	int		ws;

	ws = write(fd, s, ft_strlen(s));
	(void)ws;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem;

	mem = malloc(nmemb * size);
	if (!(mem))
		return (NULL);
	return (ft_memset(mem, 0, nmemb * size));
}

int	ft_atoi(const char *np)
{
	int				sign;
	int				res;

	sign = 1;
	res = 0;
	while (ft_isspace(*np))
		np++;
	if (*np == '-' || *np == '+')
		if (*np++ == '-')
			sign = -1;
	while (ft_isdigit(*np))
		res = (res * 10) + (*np++ - '0');
	return (res * sign);
}

int	ft_isspace(char c)
{
	if ((c == '\t' || c == '\v' || c == '\n' || c == '\f'
			|| c == '\r' || c == ' '))
		return (1);
	return (0);
}
