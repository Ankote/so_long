/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:52:05 by aankote           #+#    #+#             */
/*   Updated: 2022/12/16 22:52:06 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void img_path(t_graph *data)
{
    int w;

    data->wall =  mlx_xpm_file_to_image(data->mlx,"assets/images/wall.xpm", &w,&w);
    data->coin =  mlx_xpm_file_to_image(data->mlx,"assets/images/coin-bag.xpm", &w,&w);
    data->closed_exit =  mlx_xpm_file_to_image(data->mlx,"assets/images/exit-closed.xpm", &w,&w);
    data->open_exit =  mlx_xpm_file_to_image(data->mlx,"assets/images/open-exit.xpm", &w,&w);
    data->player =  mlx_xpm_file_to_image(data->mlx,"assets/images/player/front.xpm", &w,&w);
    data->floor =  mlx_xpm_file_to_image(data->mlx,"assets/images/floor.xpm", &w,&w);
    data->toxic =  mlx_xpm_file_to_image(data->mlx,"assets/images/toxic-river.xpm", &w,&w);
    data->p_left =  mlx_xpm_file_to_image(data->mlx,"assets/images/player/left.xpm", &w,&w);
    data->p_right =  mlx_xpm_file_to_image(data->mlx,"assets/images/player/right.xpm", &w,&w);
    data->p_top =  mlx_xpm_file_to_image(data->mlx,"assets/images/player/back.xpm", &w,&w);
    data->dead =  mlx_xpm_file_to_image(data->mlx,"assets/images/game-over.xpm", &w,&w);
}

int imgadd(t_graph *data, int x, int y, int base)
{
    
    if(base == '1')
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall, x, y);
    else if (base == '0')
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, x, y);
    else if (base == 'C')
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->coin, x, y);  
    else if (base == 'E')
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->closed_exit, x, y);
    else if (base == 'O')
          mlx_put_image_to_window(data->mlx, data->mlx_win, data->open_exit, x, y); 
    else if (base == 'T')
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->toxic, x, y);
    else if (base == 'P')
         mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, x, y);
    else if (base == 'L')
         mlx_put_image_to_window(data->mlx, data->mlx_win, data->p_left, x, y);
    else if (base == 'R')
         mlx_put_image_to_window(data->mlx, data->mlx_win, data->p_right, x, y);
    else if (base == 'B')
         mlx_put_image_to_window(data->mlx, data->mlx_win, data->p_top, x, y);
    else if (base == 'D')
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->dead, x, y);
    return (0);
}

int addimg(t_graph *data)
{
    int i;
    int j;
    int x;
    int y;

    i = 0;
    y = 0;
    mlx_clear_window(data->mlx, data->mlx_win);
    while (data->p[i])
    {
        j = 0;
        x = 0;
        while (data->p[i][j])
        {
            imgadd(data, x, y, data->p[i][j]);
            x += 32;
            j++;
        }
        y += 32;
        i++;
    }
    return (0);
}
