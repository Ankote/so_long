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

int check_rect(t_graph *data)
{
    int i;

    i = 0;
    while (data->p[i] && data->p[i + 1])
    {
        if(ft_strlen(data->p[i]) != ft_strlen(data->p[i + 1]))
            return (0);
        i ++;
    }
    return (1);
}

int check_caract(t_graph *data)
{
    int i;
    int j;

    i = 0;
    while(data->p[i])
    {
        j = 0;
        while (data->p[i][j])
        {
            if (data->p[i][j] != '0' && data->p[i][j] != '1' 
                && data->p[i][j] != 'C' && data->p[i][j] != 'E'
                    && data->p[i][j] != 'P')
                return (0);
            j ++;
        }
        i++;
    }
    return (1);
}

