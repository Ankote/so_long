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
        
        data->p[data->y_pos][data->x_pos] = '0';
        data->p[data->y_pos][data->x_pos + 1] = 'R';
        // imgadd(data, data->x_pos * 32 , data->y_pos * 32, data->p[data->y_pos][data->x_pos]);
        // imgadd(data, (data->x_pos + 1) * 32 , data->y_pos * 32 , 'R'); 
        mlx_clear_window(data->mlx, data->mlx_win);
        addimg(data);
        data->x_pos += 1;
        data->move_cpt ++;
        mlx_string_put(data->mlx,data->mlx_win, 5, 5,0xFF0000, ft_strjoin("Move : ", ft_itoa(data->move_cpt)));
        printf("Move : right\n" );
        
        return (0);
}

int left_move_p(t_graph *data)
{
        char *nb;
        nb = ft_itoa(data->move_cpt);
        data->p[data->y_pos][data->x_pos] = '0';
        data->p[data->y_pos][data->x_pos - 1] = 'L';
        // imgadd(data, data->x_pos * 32 , data->y_pos * 32, data->p[data->y_pos][data->x_pos]);
        // imgadd(data, (data->x_pos - 1) * 32 , data->y_pos * 32 , 'L'); 
                mlx_clear_window(data->mlx, data->mlx_win);
        addimg(data);
        data->x_pos -= 1;
        data->move_cpt ++;
        mlx_string_put(data->mlx,data->mlx_win, 5, 5,0xFF0000, ft_strjoin("Move : ", ft_itoa(data->move_cpt)));
        printf("Move : left\n" );
        return (0);
}

int top_move_p(t_graph *data)
{
        char *nb;

        nb = ft_itoa(data->move_cpt);
        data->p[data->y_pos][data->x_pos] = '0';
        data->p[data->y_pos - 1][data->x_pos] = 'B';
        // imgadd(data, data->x_pos * 32 , data->y_pos * 32, data->p[data->y_pos][data->x_pos]);
        // imgadd(data, (data->x_pos) * 32 , (data->y_pos - 1) * 32 , 'B'); 
        mlx_clear_window(data->mlx, data->mlx_win);
        addimg(data);
        data->y_pos -= 1;
        data->move_cpt ++;
                mlx_string_put(data->mlx,data->mlx_win, 5, 5,0xFF0000, ft_strjoin("Move : ", ft_itoa(data->move_cpt)));
                printf("Move : up\n" );
        return (0);
}

int bottom_move_p(t_graph *data)
{
        char *nb;

        nb = ft_itoa(data->move_cpt);
        data->p[data->y_pos][data->x_pos] = '0';
        data->p[data->y_pos + 1][data->x_pos] = 'P';
        // imgadd(data, data->x_pos * 32 , (data->y_pos) * 32, data->p[data->y_pos][data->x_pos]);
        // imgadd(data, (data->x_pos) * 32 , (data->y_pos + 1) * 32 , 'P'); 
         mlx_clear_window(data->mlx, data->mlx_win);
        addimg(data);
        data->y_pos += 1;
        data->move_cpt ++;
        mlx_string_put(data->mlx,data->mlx_win, 5, 5,0xFF0000, ft_strjoin("Move : ", ft_itoa(data->move_cpt)));
        printf("Move : down\n" );
        return (1);
        return (0);
}

int opendor(t_graph *data)
{
    imgadd(data, data->x_dor * 32 , data->y_dor * 32, 'O');
    data->p[data->y_dor][data->x_dor] = 'O';
    return (0);
}