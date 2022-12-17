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

typedef struct	s_data 
{
	void	*img;
	char	*addr;
   
}				t_data;

typedef struct	s_graph 
{
	void	*mlx;
	char	*mlx_win;
     int     x;
    int     y;
}	 t_graph;
#endif
