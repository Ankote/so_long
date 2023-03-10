/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:22:56 by aankote           #+#    #+#             */
/*   Updated: 2022/12/22 19:22:59 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	succeed(t_graph *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	ft_putstr_fd("--YOU WIN--\n", 1);
	exit(0);
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
