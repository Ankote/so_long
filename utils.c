/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:22:56 by aankote           #+#    #+#             */
/*   Updated: 2022/12/22 19:22:59 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int succeed(t_graph *data)
{
    mlx_clear_window(data->mlx, data->mlx_win);
    printf("--Game over--\n");
    exit(0);
    return (0);
}


int game_over(t_graph *data)
{
    imgadd(data, data->x_width/2 - 65  , data->y_height/2 - 39, 'D');
    data->game_over = 1;
    return (0);
}
