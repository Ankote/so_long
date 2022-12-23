/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:46:14 by aankote           #+#    #+#             */
/*   Updated: 2022/12/23 21:46:16 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_player(t_graph *data)
{
    int i;
    int cpt;

    i = 0;
    cpt = 0;
    while (data->map[i])
    {
        if(data->map[i] == 'P')
            cpt ++;
        i++;
        if(cpt > 1)
            return (0);
    }
    if (!cpt)
        return (0);
   return (1); 
}

int check_exit(t_graph *data)
{
    int i;
    int cpt;

    cpt = 0;
    i = 0;
    while (data->map[i])
    {
        if(data->map[i] == 'E')
            cpt ++;
        i++;
        if(cpt > 1)
            return (0);
    }
    if (!cpt)
        return (0);
   return (1); 
}

