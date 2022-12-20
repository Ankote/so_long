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

t_graph *check_player(char *map,t_graph *crd)
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
                
                return (free (p), crd);
            }
            j ++;
        }
        i ++;
    } 
    
    return (free(p),  NULL);  
}

int keyhook(int keyhook ,t_graph *graph )
{
    if (keyhook == 123 || keyhook == 0)
    {
       
        left_move(graph);
        
    }
    if (keyhook == 124 || keyhook == 2)   
        right_move(graph);
    if (keyhook == 125 || keyhook == 1) 
        bottom_move(graph);
    if (keyhook == 126 || keyhook == 13)
         top_move(graph);
    if(keyhook == 53)
    {
        mlx_destroy_window(graph->mlx, graph->mlx_win);
        exit(0);
    }
        printf("\n\n %d\n", keyhook);
    return (0);
}

