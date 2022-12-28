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

int	right_move_p(t_graph *data)
{
	char *s;
	char *p;

	p = ft_itoa(data->move_cpt);
	s = ft_strjoin("Move : ", p);
	data->p[data->y_pos][data->x_pos] = '0';
	data->p[data->y_pos][data->x_pos + 1] = 'R';
	mlx_clear_window(data->mlx, data->mlx_win);
	addimg(data);
	data->x_pos += 1;
	data->move_cpt++;
	mlx_string_put(data->mlx, data->mlx_win, 5, 5, 0xFF0000,s);
	ft_putstr_fd("Move : right\n", 1);
	return (free(p), free(s), 0);
}

int	left_move_p(t_graph *data)
{
	char *s;
	char *p;

	p = ft_itoa(data->move_cpt);
	s = ft_strjoin("Move : ", p);
	data->p[data->y_pos][data->x_pos] = '0';
	data->p[data->y_pos][data->x_pos - 1] = 'L';
	mlx_clear_window(data->mlx, data->mlx_win);
	addimg(data);
	data->x_pos -= 1;
	data->move_cpt++;
	mlx_string_put(data->mlx, data->mlx_win, 5, 5, 0xFF0000,
		p);
	ft_putstr_fd("Move : left\n", 1);
	return (free(p), free(s), 0);
}

int	top_move_p(t_graph *data)
{
	char *s;
	char *p;

	p = ft_itoa(data->move_cpt);
	s = ft_strjoin("Move : ", p);
	data->p[data->y_pos][data->x_pos] = '0';
	data->p[data->y_pos - 1][data->x_pos] = 'B';
	mlx_clear_window(data->mlx, data->mlx_win);
	addimg(data);
	data->y_pos -= 1;
	data->move_cpt++;
	mlx_string_put(data->mlx, data->mlx_win, 5, 5, 0xFF0000, p);
	ft_putstr_fd("Move : up\n", 1);
	return (free(p), free(s), 0);
}

int	bottom_move_p(t_graph *data)
{
	char *s;
	char *p;

	p = ft_itoa(data->move_cpt);
	s = ft_strjoin("Move : ", p);
	data->p[data->y_pos][data->x_pos] = '0';
	data->p[data->y_pos + 1][data->x_pos] = 'P';
	mlx_clear_window(data->mlx, data->mlx_win);
	addimg(data);
	data->y_pos += 1;
	data->move_cpt++;
	mlx_string_put(data->mlx, data->mlx_win, 5, 5, 0xFF0000,p);
	ft_putstr_fd("Move : down\n", 1);
	return (free(p), free(s), 0);
}

int	opendor(t_graph *data)
{
	imgadd(data, data->x_dor * 32, data->y_dor * 32, 'O');
	data->p[data->y_dor][data->x_dor] = 'O';
	return (0);
}
