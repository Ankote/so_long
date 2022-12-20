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

int right_move(t_graph *data)
{
    if (data->p[data->y_pos][data->x_pos + 1] != '1' && data->p[data->y_pos][data->x_pos + 1] != 'E')
    {
        data->p[data->y_pos][data->x_pos] = '0';
        data->p[data->y_pos][data->x_pos + 1] = 'P';
        imgadd(data, data->x_pos * 32 , data->y_pos * 32, data->p[data->y_pos][data->x_pos]);
        imgadd(data, (data->x_pos + 1) * 32 , data->y_pos * 32 , data->p[data->y_pos ][data->x_pos + 1]); 
        data->x_pos += 1;
        printf("--Right--\n");
    }
    if (data->p[data->y_pos][data->x_pos + 1] == 'E' )
     {
         mlx_destroy_image(data->mlx, data->img);
        mlx_clear_window(data->mlx, data->mlx_win);
        printf("--Game over--\n");
        exit(0);
     }
    return (0); 
}

int left_move(t_graph *data)
{
   
    if (data->p[data->y_pos][data->x_pos - 1] != '1' && data->p[data->y_pos][data->x_pos - 1] != 'E')
    {
        data->p[data->y_pos][data->x_pos] = '0';
        data->p[data->y_pos][data->x_pos - 1] = 'P';
        imgadd(data, data->x_pos * 32 , data->y_pos * 32, data->p[data->y_pos][data->x_pos]);
        imgadd(data, (data->x_pos - 1) * 32 , data->y_pos * 32 , data->p[data->y_pos ][data->x_pos - 1]); 
        data->x_pos -= 1;
        printf("--left--\n");
        
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
    if (data->p[data->y_pos - 1][data->x_pos] != '1' && data->p[data->y_pos - 1][data->x_pos] != 'E')
    {
        data->p[data->y_pos][data->x_pos] = '0';
        data->p[data->y_pos - 1][data->x_pos] = 'P';
        imgadd(data, data->x_pos * 32 , data->y_pos * 32, data->p[data->y_pos][data->x_pos]);
        imgadd(data, (data->x_pos) * 32 , (data->y_pos - 1) * 32 , data->p[data->y_pos - 1][data->x_pos]); 
        data->y_pos -= 1;
        printf("--Top--\n");
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
    if (data->p[data->y_pos + 1][data->x_pos] != '1' && data->p[data->y_pos + 1][data->x_pos] != 'E')
    {
        data->p[data->y_pos][data->x_pos] = '0';
        data->p[data->y_pos + 1][data->x_pos] = 'P';
        imgadd(data, data->x_pos * 32 , (data->y_pos) * 32, data->p[data->y_pos][data->x_pos]);
        imgadd(data, (data->x_pos) * 32 , (data->y_pos + 1) * 32 , data->p[data->y_pos + 1][data->x_pos]); 
        data->y_pos += 1;
        printf("--Bottom--\n");
    }
    if (data->p[data->y_pos + 1][data->x_pos] == 'E' )
    {
        mlx_clear_window(data->mlx, data->mlx_win);
        printf("--Game over--\n");
        exit(0);
    }
       
    return (0); 
}
