/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:36:48 by aankote           #+#    #+#             */
/*   Updated: 2022/12/28 22:36:59 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_name(char *mapname)
{
	int		i;
	char	*p;

	p = ft_strdup("ber");
	i = 0;
	if (ft_strlen (mapname) <= 4)
		ft_error("ERROR!\n the map name has to ended with .ber extention.\n");
	while (mapname[i] && mapname[i] != '.')
		i++;
	i++;
	if (ft_strncmp(p, mapname + i, 4))
	{
		ft_putstr_fd("ERROR!\n the map name has to ended with .ber extention.\n",
			1);
		return (free(p), 0);
	}
	free(p);
	return (1);
}

static int	ft_check_hor(t_graph *data, int line)
{
	int	i;

	i = 0;
	while (data->p[line][i])
	{
		if (data->p[line][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_vir(t_graph *data)
{
	int	i;

	i = 0;
	while (data->p[i])
	{
		if (data->p[i][0] && (data->p[i][0] != '1'
			|| data->p[i][ft_strlen(data->p[i])
			- 1] != '1'))
			return (0);
		i++;
	}
	return (1);
}

int	check_circumf(t_graph *data)
{
	int	i;

	i = 0;
	while (data->p[i])
		i++;
	if (!ft_check_hor(data, 0) || !ft_check_hor(data, i - 1)
		|| !check_vir(data))
	{
		ft_putstr_fd("ERROR!\n the has to be closed.\n", 1);
		return (0);
	}
	return (1);
}

int	check_coin(t_graph *data)
{
	if (!ft_strchr(data->map, 'C'))
	{
		ft_putstr_fd("ERROR!\n The map must contain  at least 1 \
collectible.\n", 1);
		return (0);
	}
	return (1);
}
