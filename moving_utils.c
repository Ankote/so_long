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
	char	*nb;

	data->p[data->y_pos][data->x_pos] = '0';
	data->p[data->y_pos][data->x_pos + 1] = 'R';
	mlx_clear_window(data->mlx, data->mlx_win);
	addimg(data);
	data->x_pos += 1;
	data->move_cpt++;
	nb = ft_itoa(data->move_cpt);
	ft_print("Right  : ", nb);
	return (free(nb), 0);
}

int	left_move_p(t_graph *data)
{
	char	*nb;

	data->p[data->y_pos][data->x_pos] = '0';
	data->p[data->y_pos][data->x_pos - 1] = 'L';
	mlx_clear_window(data->mlx, data->mlx_win);
	addimg(data);
	data->x_pos -= 1;
	data->move_cpt++;
	nb = ft_itoa(data->move_cpt);
	ft_print("Left  : ", nb);
	return (free(nb), 0);
}

int	top_move_p(t_graph *data)
{
	char	*nb;

	data->p[data->y_pos][data->x_pos] = '0';
	data->p[data->y_pos - 1][data->x_pos] = 'B';
	mlx_clear_window(data->mlx, data->mlx_win);
	addimg(data);
	data->y_pos -= 1;
	data->move_cpt++;
	nb = ft_itoa(data->move_cpt);
	ft_print("Up  : ", nb);
	return (free(nb), 0);
}

int	bottom_move_p(t_graph *data)
{
	char	*nb;

	data->p[data->y_pos][data->x_pos] = '0';
	data->p[data->y_pos + 1][data->x_pos] = 'P';
	mlx_clear_window(data->mlx, data->mlx_win);
	addimg(data);
	data->y_pos += 1;
	data->move_cpt++;
	nb = ft_itoa(data->move_cpt);
	ft_print("Down  : ", nb);
	return (free(nb), 0);
}

int	opendor(t_graph *data)
{
	data->p[data->y_dor][data->x_dor] = 'O';
	mlx_clear_window(data->mlx, data->mlx_win);
	addimg(data);
	return (0);
}
