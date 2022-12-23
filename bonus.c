/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:48:40 by aankote           #+#    #+#             */
/*   Updated: 2022/12/22 17:48:43 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int right_move_p(t_graph *data)
{
        char *nb;

        nb = ft_itoa(data->move_cpt);
        if (data->p[data->y_pos][data->x_pos] == 'P')
        {
                data->p[data->y_pos][data->x_pos] = '0';
                data->p[data->y_pos][data->x_pos + 1] = 'P';
                imgadd(data, data->x_pos * 32 , data->y_pos * 32, data->p[data->y_pos][data->x_pos]);
                imgadd(data, (data->x_pos + 1) * 32 , data->y_pos * 32 , 'R'); 
                data->x_pos += 1;
                data->move_cpt ++;
                mlx_string_put(data->mlx,data->mlx_win, 5, 5,0xFF0000,nb);
                printf("Move : right\n" );
        }
        return (0);
}

int left_move_p(t_graph *data)
{
        char *nb;

        nb = ft_itoa(data->move_cpt);
        if (data->p[data->y_pos][data->x_pos] == 'P')
        {
                data->p[data->y_pos][data->x_pos] = '0';
                data->p[data->y_pos][data->x_pos - 1] = 'P';
                imgadd(data, data->x_pos * 32 , data->y_pos * 32, data->p[data->y_pos][data->x_pos]);
                imgadd(data, (data->x_pos - 1) * 32 , data->y_pos * 32 , 'L'); 
                data->x_pos -= 1;
                data->move_cpt ++;
                mlx_string_put(data->mlx,data->mlx_win, 5, 5,0xFF0000,nb);
                printf("Move : left\n" );
        }
        return (0);
}

int top_move_p(t_graph *data)
{
        char *nb;

        nb = ft_itoa(data->move_cpt);
        if (data->p[data->y_pos][data->x_pos] == 'P')
        {
                data->p[data->y_pos][data->x_pos] = '0';
                data->p[data->y_pos - 1][data->x_pos] = 'P';
                imgadd(data, data->x_pos * 32 , data->y_pos * 32, data->p[data->y_pos][data->x_pos]);
                imgadd(data, (data->x_pos) * 32 , (data->y_pos - 1) * 32 , 'B'); 
                data->y_pos -= 1;
                data->move_cpt ++;
                 mlx_string_put(data->mlx,data->mlx_win, 5, 5,0xFF0000,nb);
                 printf("Move : up\n" );
        }
        return (0);
}

int bottom_move_p(t_graph *data)
{
        char *nb;

        nb = ft_itoa(data->move_cpt);
        if (data->p[data->y_pos][data->x_pos] == 'P')
        {
                data->p[data->y_pos][data->x_pos] = '0';
                data->p[data->y_pos + 1][data->x_pos] = 'P';
                imgadd(data, data->x_pos * 32 , (data->y_pos) * 32, data->p[data->y_pos][data->x_pos]);
                imgadd(data, (data->x_pos) * 32 , (data->y_pos + 1) * 32 , 'P'); 
                data->y_pos += 1;
                data->move_cpt ++;
                 mlx_string_put(data->mlx,data->mlx_win, 5, 5,0xFF0000,nb);
                 printf("Move : down\n" );
                return (1);
        }
        return (0);
}

int opendor(t_graph *data)
{
    imgadd(data, data->x_dor * 32 , data->y_dor * 32, 'O');
    data->p[data->y_dor][data->x_dor] = 'O';
    return (0);
}