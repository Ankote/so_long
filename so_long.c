/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 02:27:53 by aankote           #+#    #+#             */
/*   Updated: 2022/12/26 02:27:59 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int x_graph(char *map)
{
    int i;
    char **p;
    int x_height;

    i = 0;
    p = split_map(map);
    x_height = ft_strlen(p[0]);
    free(p);
    return (x_height * 32);
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
    t_graph data;
    data.game_over = 0;
    data = *check_player_pos(map, &data); 
    data.x_width = x_graph(map);
    data.y_height = y_graph(map);
    data.move_cpt = 0;
    data.p = split_map(map);  
    data.map = map;
    data.mlx = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx, data.x_width, data.y_height, "so_long");
    img_path(&data);
    addimg(&data); 
    mlx_hook(data.mlx_win, 2, 0,keyhook, &data);
    mlx_loop_hook(data.mlx, anim, &data);
    mlx_hook(data.mlx_win, 17, 0,close_prog, &data);
    mlx_loop(data.mlx);      
    return (0);
}

int main(int argc ,char **argv)
{ 
    int fd;
    if (argc == 2)
    {
        if (!check_name(argv[1]))
            printf("map invalid");
        else 
        {
           
            fd = open(argv[1],O_RDONLY); 
            printf("%d\n",fd);
            open_window(read_map(fd));
        }
    } 
}