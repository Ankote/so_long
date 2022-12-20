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

int count_coins(t_graph *data)
{
    int i;
    int j;
    int cpt;

    i = 0;
    cpt = 0;
    while (data->p[i])
    {
        j = 0;
        while (data->p[i][j])
        {
            if (data->p[i][j] == 'C')
                cpt ++;
            j ++;
        }
        i ++;
    }
    return (cpt);
}

int right_move(t_graph *data)
{ 
     data->coin_cpt = 0;
    if (data->p[data->y_pos][data->x_pos + 1] != '1' && data->p[data->y_pos][data->x_pos + 1] != 'E')
    {
        data->p[data->y_pos][data->x_pos] = '0';
        data->p[data->y_pos][data->x_pos + 1] = 'P';
        imgadd(data, data->x_pos * 32 , data->y_pos * 32, data->p[data->y_pos][data->x_pos]);
        imgadd(data, (data->x_pos + 1) * 32 , data->y_pos * 32 , data->p[data->y_pos ][data->x_pos + 1]); 
        data->x_pos += 1;
        printf("--Right--\n");
    }
    if(data->p[data->y_pos][data->x_pos ] == 'C')
    {
        data->coin_cpt ++;
        if (data->coin_cpt == count_coins(data))
            exit(0);
    }
    if (data->p[data->y_pos][data->x_pos + 1] == 'E' )
     {
        mlx_clear_window(data->mlx, data->mlx_win);
        printf("--Game over--\n");
        exit(0);
     }
    return (0); 
}

int left_move(t_graph *data)
{
    data->coin_cpt = 0;
    if (data->p[data->y_pos][data->x_pos - 1] != '1' && data->p[data->y_pos][data->x_pos - 1] != 'E')
    {
        data->p[data->y_pos][data->x_pos] = '0';
        data->p[data->y_pos][data->x_pos - 1] = 'P';
        imgadd(data, data->x_pos * 32 , data->y_pos * 32, data->p[data->y_pos][data->x_pos]);
        imgadd(data, (data->x_pos - 1) * 32 , data->y_pos * 32 , data->p[data->y_pos ][data->x_pos - 1]); 
        data->x_pos -= 1;
        printf("--left--\n");
        
    }
    else if(data->p[data->y_pos][data->x_pos] == 'C')
    {
        data->coin_cpt ++;
        if (data->coin_cpt == count_coins(data))
            exit(0);
    }
    if (data->p[data->y_pos][data->x_pos - 1] == 'E' )
     {
        mlx_clear_window(data->mlx, data->mlx_win);
        printf("--Game over--\n");
        exit(0);
     }
    return (0); 
}

int top_move(t_graph *data)
{
    data->coin_cpt = 0;
    if (data->p[data->y_pos - 1][data->x_pos] != '1' && data->p[data->y_pos - 1][data->x_pos] != 'E')
    {
        data->p[data->y_pos][data->x_pos] = '0';
        data->p[data->y_pos - 1][data->x_pos] = 'P';
        imgadd(data, data->x_pos * 32 , data->y_pos * 32, data->p[data->y_pos][data->x_pos]);
        imgadd(data, (data->x_pos) * 32 , (data->y_pos - 1) * 32 , data->p[data->y_pos - 1][data->x_pos]); 
        data->y_pos -= 1;
        printf("--Top--\n");
    }
    if(data->p[data->y_pos ][data->x_pos] == 'C')
    {
        data->coin_cpt ++;
        if (data->coin_cpt == count_coins(data))
            exit(0);
    }
    if (data->p[data->y_pos - 1][data->x_pos ] == 'E' )
    {
        mlx_clear_window(data->mlx, data->mlx_win);
        printf("--Game over--\n");
        exit(0);
    }
    return (0); 
}

int bottom_move(t_graph *data)
{
    data->coin_cpt = 0;
    if (data->p[data->y_pos + 1][data->x_pos] != '1' && data->p[data->y_pos + 1][data->x_pos] != 'E')
    {
        data->p[data->y_pos][data->x_pos] = '0';
        data->p[data->y_pos + 1][data->x_pos] = 'P';
        imgadd(data, data->x_pos * 32 , (data->y_pos) * 32, data->p[data->y_pos][data->x_pos]);
        imgadd(data, (data->x_pos) * 32 , (data->y_pos + 1) * 32 , data->p[data->y_pos + 1][data->x_pos]); 
        data->y_pos += 1;
        printf("--Bottom--\n");
    }
    if(data->p[data->y_pos][data->x_pos] == 'C')
    {
        data->coin_cpt ++;
        if (data->coin_cpt == count_coins(data))
            exit(0);
    }
    if (data->p[data->y_pos + 1][data->x_pos] == 'E' )
    {
        mlx_clear_window(data->mlx, data->mlx_win);
        printf("--Game over--\n");
        exit(0);
    }
       
    return (0); 
}
