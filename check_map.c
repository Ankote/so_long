/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:41:57 by aankote           #+#    #+#             */
/*   Updated: 2022/12/27 21:42:00 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	floodfill(char **p, int sr, int sc, int base)
{
	if (p[sr][sc] != '0' && p[sr][sc] != 'P' && p[sr][sc] != base
		&& p[sr][sc] != 'C')
		return ;
	p[sr][sc] = 'V';
	floodfill(p, sr, sc - 1, base);
	floodfill(p, sr + 1, sc, base);
	floodfill(p, sr - 1, sc, base);
	floodfill(p, sr, sc + 1, base);
}

static int	check_exist(char **p, int base)
{
	int	i;
	int	j;

	i = 0;
	while (p[i])
	{
		j = 0;
		while (p[i][j])
		{
			if (p[i][j] == base)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_path(t_graph *data, int base)
{
	char	**p;
	int		x;
	int		y;

	x = data->x_pos;
	y = data->y_pos;
	p = ft_split(data->map, '\n');
	floodfill(p, y, x, base);
	if (base == 'E')
	{
		if (!check_exist(p, 'E'))
		{
			ft_putstr_fd("ERROR!\nthere is no valid\
path to go the exit.\n", 1);
			return (free_p(p), 0);
		}
	}
	else if (base == 'C')
	{
		if (!check_exist(p, 'C'))
		{
			ft_putstr_fd("ERROR!\nthere is no valid path\
to catch all collectibles\n", 1);
			return (free_p(p), 0);
		}
	}
	return (free_p(p), 1);
}
