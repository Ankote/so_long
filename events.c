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
#include "so_long_bonus.h"

int	keyhook(int keyhook, t_graph *graph)
{
	if (keyhook == 123 || keyhook == 0)
		left_move(graph);
	if (keyhook == 124 || keyhook == 2)
		right_move(graph);
	if (keyhook == 125 || keyhook == 1)
		bottom_move(graph);
	if (keyhook == 126 || keyhook == 13)
		top_move(graph);
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
