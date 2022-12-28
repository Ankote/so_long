/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 04:00:09 by aankote           #+#    #+#             */
/*   Updated: 2022/12/19 04:00:10 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	count_coins(t_graph *data)
{
	int	i;
	int	j;
	int	cpt;

	i = 0;
	cpt = 0;
	while (data->p[i])
	{
		j = 0;
		while (data->p[i][j])
		{
			if (data->p[i][j] == 'C')
				cpt++;
			j++;
		}
		i++;
	}
	return (cpt);
}

int	right_move(t_graph *data)
{
	if (data->p[data->y_pos][data->x_pos + 1] == 'T')
	{
		imgadd(data, data->x_pos * 32, data->y_pos * 32, '0');
		data->x_pos += 1;
		game_over(data);
	}
	else if (data->p[data->y_pos][data->x_pos + 1] != '1'
			&& data->p[data->y_pos][data->x_pos + 1] != 'E')
	{
		right_move_p(data);
		if (!count_coins(data))
			opendor(data);
		if (data->p[data->y_pos][data->x_pos] == 'O')
			succeed(data);
	}
	return (0);
}

int	left_move(t_graph *data)
{
	if (data->p[data->y_pos][data->x_pos - 1] == 'T')
	{
		imgadd(data, data->x_pos * 32, data->y_pos * 32, '0');
		data->x_pos -= 1;
		game_over(data);
	}
	else if (data->p[data->y_pos][data->x_pos - 1] != '1'
			&& data->p[data->y_pos][data->x_pos - 1] != 'E')
	{
		left_move_p(data);
		if (!count_coins(data))
			opendor(data);
		if (data->p[data->y_pos][data->x_pos] == 'O')
			succeed(data);
	}
	return (0);
}

int	top_move(t_graph *data)
{
	if (data->p[data->y_pos - 1][data->x_pos] == 'T')
	{
		imgadd(data, data->x_pos * 32, data->y_pos * 32, '0');
		data->y_pos -= 1;
		game_over(data);
	}
	else if (data->p[data->y_pos - 1][data->x_pos] != '1' && data->p[data->y_pos
			- 1][data->x_pos] != 'E')
	{
		top_move_p(data);
		if (!count_coins(data))
			opendor(data);
		if (data->p[data->y_pos][data->x_pos] == 'O')
			succeed(data);
	}
	return (0);
}

int	bottom_move(t_graph *data)
{
	if (data->p[data->y_pos + 1][data->x_pos] == 'T')
	{
		imgadd(data, data->x_pos * 32, data->y_pos * 32, '0');
		data->y_pos += 1;
		game_over(data);
	}
	else if (data->p[data->y_pos + 1][data->x_pos] != '1' && data->p[data->y_pos
			+ 1][data->x_pos] != 'E')
	{
		bottom_move_p(data);
		if (!count_coins(data))
			opendor(data);
		if (data->p[data->y_pos][data->x_pos] == 'O')
			succeed(data);
	}
	return (0);
}
