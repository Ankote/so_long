/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:09:39 by aankote           #+#    #+#             */
/*   Updated: 2022/12/16 18:09:41 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(int fd)
{
	char	*buff;
	char	*res;

	res = ft_calloc(1, 1);
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		res = ft_strjoin(res, buff);
	}
	free (buff);
	return (res);
}

char	**split_map(char *map)
{
	char	**p;

	if (!map)
		return (0);
	p = ft_split(map, '\n');
	return (p);
}
