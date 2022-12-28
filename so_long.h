/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:09:07 by aankote           #+#    #+#             */
/*   Updated: 2022/12/16 18:09:12 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <mlx.h>

char		*read_map(int fd);
char		**split_map(char *map);

typedef struct s_graph
{
	void	*mlx;
	char	*mlx_win;
	char	*map;
	char	**p;
	int		x_pos;
	int		y_pos;
	int		x_player;
	int		y_player;
	int		x_width;
	int		y_height;
	void	*open_exit;
	void	*wall;
	void	*floor;
	void	*player;
	void	*toxic;
	void	*p_left;
	void	*p_right;
	void	*p_top;
	void	*coin;
	void	*closed_exit;
	void	*dead;
	void	*img;
	char	*addr;
	int		game_over;
	int		x_dor;
	int		y_dor;
	int		move_cpt;
	int		frame;
}			t_graph;

t_graph		*check_pos(char *map, t_graph *crd);

int			event(int keyhook, t_graph *graph);
int			keyhook(int keyhook, t_graph *graph);
int			right_move(t_graph *data);
int			left_move(t_graph *data);
int			top_move(t_graph *data);
int			bottom_move(t_graph *data);
int			addimg(t_graph *data);
int			imgadd(t_graph *data, int x, int y, int base);
int			right_move_p(t_graph *data);
int			left_move_p(t_graph *data);
int			top_move_p(t_graph *data);
int			bottom_move_p(t_graph *data);
int			opendor(t_graph *data);
int			succeed(t_graph *data);
int			count_coins(t_graph *data);
int			game_over(t_graph *data);
int			close_prog(t_graph *graph);
int			check_name(char *mapname);
int			check_circumf(t_graph *data);
int			check_coin(t_graph *data);
int			check_exit(t_graph *data);
int			check_player(t_graph *data);
int			check_caract(t_graph *data);
int			check_rect(t_graph *data);
void		img_path(t_graph *data);
int			move(t_graph *data);
int			anim(t_graph *data);
int			check_map(t_graph *data);
int			check_path(t_graph *data, int base);
void		free_p(char **p);
#endif
