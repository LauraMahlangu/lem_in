/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahlang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:39:47 by lmahlang          #+#    #+#             */
/*   Updated: 2018/06/01 18:21:56 by lmahlang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	t_var	init(void)
{
	t_var v;

	v.rooms = NULL;
	v.path = NULL;
	v.start = NULL;
	v.end = NULL;
	v.line = NULL;
	v.n_ants = 0;
	v.start_end = 0;
	v.error = 0;
	return (v);
}

static	t_var	line_manip(t_var v)
{
	v.ptr = ft_strsplit(v.line, ' ');
	v.ptr2 = ft_strsplit(v.line, '-');
	(v.ptr) ? start_and_end(&v.start, &v.end, v.ptr[0],
			&v.start_end) : 0;
	(strcmp(v.line, "##start") == 0) ? (v.start_end = 1) : 0;
	(strcmp(v.line, "##end") == 0) ? (v.start_end = 2) : 0;
	if (v.ptr[0] && v.ptr[1] && v.ptr[2] && !v.ptr[3])
	{
		check_cord(v.ptr[1], v.ptr[2], &v.error);
		(v.ptr[0][0] == 'L') ? (v.error = 1) : 0;
		(v.ptr[0][0] == '#') ? 0 : add_room(&v.rooms, v.ptr[0]);
	}
	return (v);
}

int				main(void)
{
	t_var v;

	v = init();
	while (get_next_line(0, &v.line))
	{
		ft_putendl(v.line);
		v.line = ft_strtrim(v.line);
		empty_line(v.line, &v.error);
		if (v.n_ants == 0)
		{
			check_cord(v.line, NULL, &v.error);
			v.n_ants = ft_atoi(v.line);
		}
		v = line_manip(v);
		if (v.ptr2[0] && v.ptr2[1] && !v.ptr2[2])
			connect(v.rooms, v.ptr2[0], v.ptr2[1], &v.error);
	}
	ft_putchar('\n');
	do_ants(v);
	return (0);
}

