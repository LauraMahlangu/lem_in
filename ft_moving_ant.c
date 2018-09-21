/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moving_ant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahlang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:16:44 by lmahlang          #+#    #+#             */
/*   Updated: 2018/06/01 18:40:43 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		print_ant(t_path *path, int x, t_var v, int iter)
{
	int print;

	print = iter - x;
	while (path && print)
	{
		if (print == 1)
		{
			ft_putstr("L");
			ft_putnbr(x + 1);
			ft_putstr("-");
			ft_putstr(path->name);
			ft_putchar(' ');
			if (x + 1 == v.n_ants && strcmp(path->name, v.end) == 0)
				return (1);
		}
		print--;
		path = path->next;
	}
	return (0);
}

void	move_ants(t_path *path, t_var v)
{
	int iter;
	int finished;
	int x;

	iter = 1;
	finished = 0;
	while (!finished)
	{
		x = -1;
		while (++x < v.n_ants)
			finished = print_ant(path, x, v, iter);
		ft_putendl("\n");
		iter++;
	}
}
