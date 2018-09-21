/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maping.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahlang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:36:02 by lmahlang          #+#    #+#             */
/*   Updated: 2018/06/01 18:14:38 by lmahlang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path		*move(t_queue *queue, t_room *current, char *end, t_room *rooms)
{
	t_var v;

	v.path = NULL;
	while (queue != NULL)
	{
		v.tmp = dequeue(&queue);
		current = get_room(rooms, v.tmp);
		if (strcmp(v.tmp, end) == 0)
		{
			print_path(current, &v.path);
			break ;
		}
		while (current->child)
		{
			v.child = get_room(rooms, current->child->name);
			if (!v.child->visited)
			{
				v.child->visited = 1;
				v.child->parent = current;
				enqueue(&queue, v.child->name);
			}
			current->child = current->child->next;
		}
	}
	return (v.path);
}

void		do_ants(t_var v)
{
	t_room	*current;
	t_queue *queue;
	current = NULL;
	queue = NULL;
	if (v.start && v.rooms)
	{
		current = get_room(v.rooms, v.start);
		if (current != NULL)
			current->visited = 1;
	}
	if (current != NULL)
	{
		(!v.error && v.start && v.end && v.rooms) ?
			enqueue(&queue, current->name) : 0;
		v.path = move(queue, current, v.end, v.rooms);
	}
	(v.path) ? move_ants(v.path->next, v) : ft_putendl("ERROR");
}
