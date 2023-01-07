/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:37:38 by aankote           #+#    #+#             */
/*   Updated: 2022/12/28 22:37:57 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	right_move_p(t_graph *data)
{
	char	*p;

	data->p[data->y_pos][data->x_pos] = '0';
	data->p[data->y_pos][data->x_pos + 1] = 'R';
	mlx_clear_window(data->mlx, data->mlx_win);
	addimg(data);
	data->x_pos += 1;
	data->move_cpt++;
	p = ft_itoa(data->move_cpt);
	ft_print("Right :  ", p);
	return (free(p), 0);
}

int	left_move_p(t_graph *data)
{
	char	*p;

	data->p[data->y_pos][data->x_pos] = '0';
	data->p[data->y_pos][data->x_pos - 1] = 'L';
	mlx_clear_window(data->mlx, data->mlx_win);
	addimg(data);
	data->x_pos -= 1;
	data->move_cpt++;
	p = ft_itoa(data->move_cpt);
	ft_print("Left   : ", p);
	return (free(p), 0);
}

int	top_move_p(t_graph *data)
{
	char	*p;

	data->p[data->y_pos][data->x_pos] = '0';
	data->p[data->y_pos - 1][data->x_pos] = 'B';
	mlx_clear_window(data->mlx, data->mlx_win);
	addimg(data);
	data->y_pos -= 1;
	data->move_cpt++;
	p = ft_itoa(data->move_cpt);
	ft_print("Up    :  ", p);
	return (free(p), 0);
}

int	bottom_move_p(t_graph *data)
{
	char	*p;

	data->p[data->y_pos][data->x_pos] = '0';
	data->p[data->y_pos + 1][data->x_pos] = 'P';
	mlx_clear_window(data->mlx, data->mlx_win);
	addimg(data);
	data->y_pos += 1;
	data->move_cpt++;
	p = ft_itoa(data->move_cpt);
	ft_print("Down  :  ", p);
	return (free(p), 0);
}

int	opendor(t_graph *data)
{
	data->p[data->y_dor][data->x_dor] = 'O';
	mlx_clear_window(data->mlx, data->mlx_win);
	addimg(data);
	return (0);
}
