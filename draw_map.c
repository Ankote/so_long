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

int imgadd(t_graph *data, int x, int y, int base)
{
    int w;

    data->wall =  mlx_xpm_file_to_image(data->mlx,"assets/images/wall.xpm", &w,&w);
    data->coin =  mlx_xpm_file_to_image(data->mlx,"assets/images/coin-bag.xpm", &w,&w);
    data->dor =  mlx_xpm_file_to_image(data->mlx,"assets/images/exit-closed.xpm", &w,&w);
    data->player =  mlx_xpm_file_to_image(data->mlx,"assets/images/player/front.xpm", &w,&w);
    data->floor =  mlx_xpm_file_to_image(data->mlx,"assets/images/floor.xpm", &w,&w);
    if(base == '1')
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall, x, y);
    else if (base == '0')
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, x, y);
    else if (base == 'C')
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->coin, x, y);  
    else if (base == 'P')
         mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, x, y);
    else
          mlx_put_image_to_window(data->mlx, data->mlx_win, data->dor, x, y);
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

static int x_graph(char *map)
{
    int i;
    char **p;
    int x_height;

    i = 0;
    p = split_map(map);
    x_height = ft_strlen(p[0]);
    printf("%d\n", x_height);
    free(p);
    return ( x_height * 32);
}

static int y_graph(char *map)
{
    int i;
    int y_width;
    char **p;

    i = 0;
    p = split_map(map);
    y_width = 0;
    while (p[i])
    {
        y_width++;
        i++;
    }
    free(p);
    return (y_width * 32);
}

int open_window(char *map)
{
    int x_width;
    int y_height;
    t_graph graph;
    graph = *check_player(map, &graph);
    printf("x = %d  y = %d\n", graph.x_pos,graph.y_pos);
    x_width = x_graph(map);
    y_height = y_graph(map);
    graph.p = split_map(map);
    graph.map = map;
    graph.mlx = mlx_init();
    graph.mlx_win = mlx_new_window(graph.mlx, x_width, y_height, "so_long");

    addimg(&graph);
    mlx_key_hook(graph.mlx_win,keyhook, &graph);
    mlx_loop(graph.mlx);
    return (0);
}

int main()
{
    int fd = open("maps/map4.ber",O_RDONLY);
    //t_graph crd;
  
    open_window(read_map(fd));
   // addimg(read_map(fd));
}