/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:39:12 by aankote           #+#    #+#             */
/*   Updated: 2022/12/28 22:39:27 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	succeed(t_graph *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	ft_putstr_fd("--YOU WIN--\n", 1);
	exit(0);
	return (0);
}

int	game_over(t_graph *data)
{
	imgadd(data, data->x_width / 2 - 65, data->y_height / 2 - 39, 'D');
	ft_putstr_fd("𝙂𝘼𝙈𝙀 𝙊𝙑𝙀𝙍\n", 1);
	data->game_over = 1;
	return (0);
}

void	free_p(char **p)
{
	int	i;

	i = 0;
	while (p[i])
		free(p[i++]);
	free(p);
}

void	ft_print(char *str1, char *str2)
{
	ft_putstr_fd(str1, 1);
	ft_putendl_fd(str2, 1);
}
