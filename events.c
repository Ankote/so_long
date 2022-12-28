/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:34:16 by aankote           #+#    #+#             */
/*   Updated: 2022/12/18 22:34:20 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	keyhook(int keyhook, t_graph *graph)
{
	if (!graph->game_over)
	{
		if (keyhook == 123 || keyhook == 0)
			left_move(graph);
		if (keyhook == 124 || keyhook == 2)
			right_move(graph);
		if (keyhook == 125 || keyhook == 1)
			bottom_move(graph);
		if (keyhook == 126 || keyhook == 13)
			top_move(graph);
	}
	if (keyhook == 53)
	{
		mlx_destroy_window(graph->mlx, graph->mlx_win);
		exit(0);
	}
	return (0);
}

int	close_prog(t_graph *graph)
{
	mlx_destroy_window(graph->mlx, graph->mlx_win);
	exit(0);
	return (0);
}

void	anime_gold(t_graph *data)
{
	int	w;

	if (data->frame == 20)
	{
		data->coin = mlx_xpm_file_to_image(data->mlx,
				"assets/images/coin-bag.xpm", &w, &w);
		data->toxic = mlx_xpm_file_to_image(data->mlx,
				"assets/images/toxic-red.xpm", &w, &w);
	}
	else if (data->frame == 40)
	{
		data->coin = mlx_xpm_file_to_image(data->mlx,
				"assets/images/coin-bag2.xpm", &w, &w);
		data->toxic = mlx_xpm_file_to_image(data->mlx,
				"assets/images/toxic-river.xpm", &w, &w);
	}
	if (data->frame == 40)
		data->frame = -1;
}

int	anim(t_graph *data)
{
	char	*s;
	char	*p;

	p = ft_itoa(data->move_cpt);
	s = ft_strjoin("Move : ", p);
	if (!data->game_over)
	{
		anime_gold(data);
		mlx_clear_window(data->mlx, data->mlx_win);
		addimg(data);
		mlx_string_put(data->mlx, data->mlx_win, 5, 5, 0xFF0000,
			s);
		data->frame++;
	}
	free(p);
	free (s);
	return (0);
}
