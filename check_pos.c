/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:43:47 by aankote           #+#    #+#             */
/*   Updated: 2022/12/21 17:43:49 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

t_graph *check_player_pos(char *map, t_graph *crd)
{
    int i;
    int j;
    char **p;
    
    i = 0;
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
            j ++;
        }
        i ++;
    } 
    return (free(p), crd);  
}