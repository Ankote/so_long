/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:09:07 by aankote           #+#    #+#             */
/*   Updated: 2022/12/16 18:09:12 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
#include <stdio.h>
#include <mlx.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
char *read_map(int fd);
char **split_map(char *map);

typedef struct	s_graph 
{
	void	*mlx;
	char	*mlx_win;
	char	*map;
	char 	**p;
	int     x_pos;
    int     y_pos;
	void	*wall;
	void	*floor;
	void	*player;
	void	*coin;
	void	*dor;
	void	*img;
	char	*addr;
    
}t_graph;

t_graph *check_player(char *map,t_graph *crd);
int event(int keyhook ,t_graph *graph );
int keyhook(int keyhook ,t_graph *graph );
int	right_move(t_graph *data);
int	left_move(t_graph *data);
int	top_move(t_graph *data);
int	bottom_move(t_graph *data);
int addimg(t_graph *data);
int imgadd(t_graph *data, int x, int y, int base);
#endif
