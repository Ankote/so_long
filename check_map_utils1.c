/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 02:59:25 by aankote           #+#    #+#             */
/*   Updated: 2022/12/23 02:59:26 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int check_name(char *mapname)
{
    int i;
    char *p;

    p = ft_calloc(4,1);
    p = "ber";
    i = 0;
    while(mapname[i] && mapname[i] != '.')
        i++;
    i ++;
    if (ft_strncmp(p, mapname + i, 4))
    {
        printf("ERROR!\n the map name has to ended with .ber extention.\n");
        return (0);
    }
    //free(p);
    return (1);
}

static int ft_check_hor(t_graph *data)
{
    int i;

    i = 0;
    while (data->p[0][i])
    {
        if(data->p[0][i] != '1')
            return (0);
        i ++;
    }
    return (1);
}

static int check_vir(t_graph *data)
{
    int i;

    i = 0;
    while (data->p[i])
    {
        if (data->p[i][0] != '1' || data->p[i][ft_strlen(data->p[i]) - 1] != '1' )
            return (0);
        i ++;
    }
    return (1);
}

int check_circumf(t_graph *data)
{
    int i;

    i = 0;
    while(data->p[i])
        i ++;
    if (!ft_check_hor(data) || !ft_check_hor(data)
        || !check_vir(data))
    {
        printf("ERROR!\n the has to be closed.\n");
        return (0);

    }
    return (1);
}

int check_coin(t_graph *data)
{
    if(!ft_strchr(data->map, 'C'))
    {
        printf("ERROR!\n The map must contain  at least 1 collectible.\n");
        return (0);
    }
        
    return (1);
}