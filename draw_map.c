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
t_graph *img_path(t_graph *data)
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
    return (data);
}

int imgadd(t_graph *data, int x, int y, int base)
{
    data = img_path(data);
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
    addimg(&data); 
   // floodFill(data.p, y, x, 'E');
    mlx_hook(data.mlx_win, 2, 0,keyhook, &data);
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
            open_window(read_map(fd));
        }
    } 
}