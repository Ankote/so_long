/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:32:47 by aankote           #+#    #+#             */
/*   Updated: 2022/12/28 22:32:50 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_join(char *r_buff, char *buff)
{
	char	*temp;

	temp = ft_strjoin(r_buff, buff);
	free(r_buff);
	return (temp);
}

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 1);
	exit(1);
}

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
		if (ft_strlen(buff) == 1)
			ft_error("ERROR!\nEmpty line in map.\n");
		free(buff);
		res = ft_join(res, buff);
	}
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
