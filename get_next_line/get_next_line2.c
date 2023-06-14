/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 09:12:28 by kortolan          #+#    #+#             */
/*   Updated: 2022/11/29 15:57:59 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*dest;
	static char	*r_src;
	int			i;
	int			y;

	r_src = malloc(BUFFER_SIZE);
	while(1)
	{
		i = 1;
		y = read(fd, r_src, BUFFER_SIZE);
		i++;
		if (y < BUFFER_SIZE)
			return (r_src);
		if (end_of_line(dest, r_src, i * BUFFER_SIZE) >= 0)
		{
			deplace_end_of_char(r_src, end_of_line(dest, r_src, i * BUFFER_SIZE), i * BUFFER_SIZE)
		}
		ft_realloc(r_src, (i * BUFFER_SIZE) - end_of_line(dest, r_src, i * BUFFER_SIZE));

	}
}

char	*end_of_line(void *dest, void *src, int len)
{
	int		i;

	i = -1;
	while (i < len)
	{
		i++;
		if (ptr[i] == '\n')
		{
			c = malloc(i + 1);
			ft_memcpy(dest, src, i + 1);
			return (i);
		}
	}
	return (-1);
}

char	*deplace_end_of_char(void *src, int i, int y)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * (y - i));
	if (!tmp)
		return (NULL);
	while (i < y)
	{
		*tmp = src[i];
		tmp++;
		i++;
	}
	free (src);
	return (*tmp);
}
