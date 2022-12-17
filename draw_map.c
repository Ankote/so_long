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

int imgadd(void *mlx, void *win, int x, int y, int base)
{
    t_data data;
    int w;
    if(base == '1')
        data.img = mlx_xpm_file_to_image(mlx,"assets/images/wall.xpm", &w,&w);
    else if (base == '0')
        data.img = mlx_xpm_file_to_image(mlx,"assets/images/floor.xpm", &w,&w);
    else if (base == 'C')
    {
        data.img = mlx_xpm_file_to_image(mlx,"assets/images/floor.xpm", &w,&w);
        data.img = mlx_xpm_file_to_image(mlx,"assets/images/coin-bag.xpm", &w,&w);
    }   
    else if (base == 'P')
    {
        data.img = mlx_xpm_file_to_image(mlx,"assets/images/floor.xpm", &w,&w);
        data.img = mlx_xpm_file_to_image(mlx,"assets/images/player/front.xpm", &w,&w);
    }
    else
         data.img = mlx_xpm_file_to_image(mlx,"assets/images/exit-closed.xpm", &w,&w);
        
    
    mlx_put_image_to_window(mlx, win, data.img, x, y);
    return (0);
}

int addimg(char *map, void *mlx, void* win)
{
    int i;
    int j;
    int x;
    int y;
    char **p;

    p = split_map(map);
    i = 0;
    y = 0;

    while (p[i])
    {
        j = 0;
        x = 0;
        while (p[i][j])
        {
            imgadd(mlx, win, x, y , p[i][j]);
            x += 32;
            j++;
        }
        y += 32;
        i++;
    }
    return (0);
}

static int x_graph(char *map)
{
    int i;
    char **p;
    t_graph graph;

    i = 0;
    p = split_map(map);
    graph.x = 0;
    while (p[0][i])
    {
        graph.x++;
        i++;
    }
    return (graph.x * 32);
}

static int y_graph(char *map)
{
    int i;
    t_graph graph;
    char **p;

    i = 0;
    p = split_map(map);
    graph.y = 0;
    while (p[i])
    {
        graph.y++;
        i++;
    }
    return (graph.y * 32);
}

int open_window(char *map)
{
    int x_width;
    int y_height;
    t_graph graph;
    x_width = x_graph(map);
    y_height = y_graph(map);
    graph.mlx = mlx_init();
    graph.mlx_win = mlx_new_window(graph.mlx, x_width, y_height, "so_long");
    addimg(map, graph.mlx, graph.mlx_win);
    mlx_loop(graph.mlx);
    return (0);
}

int main()
{
    int fd = open("assets/maps/valid/map8.ber",O_RDONLY);
    open_window(read_map(fd));
    
   // addimg(read_map(fd));
}