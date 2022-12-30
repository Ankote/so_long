/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:38:34 by aankote           #+#    #+#             */
/*   Updated: 2022/12/28 22:38:47 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_graph	*check_pos(char *map, int i, t_graph *crd)
{
	int		j;
	char	**p;

	p = split_map(map);
	while (p[i])
	{
		j = 0;
		while (p[i][j])
		{
			if (p[i][j] == 'P')
			{
				crd->x_pos = j;
				crd->y_pos = i;
			}
			if (p[i][j] == 'E')
			{
				crd->x_dor = j;
				crd->y_dor = i;
			}
			j++;
		}
		i++;
	}
	return (free_p(p), crd);
}
