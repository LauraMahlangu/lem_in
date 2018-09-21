/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahlang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:13:02 by lmahlang          #+#    #+#             */
/*   Updated: 2018/06/01 18:08:05 by lmahlang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*get_room(t_room *rooms, char *name)
{
	while (rooms)
	{
		if (strcmp(name, rooms->name) == 0)
			return (rooms);
		rooms = rooms->next;
	}
	return (NULL);
}

void	connect(t_room *rooms, char *r1, char *r2, int *error)
{
	t_room *room1;
	t_room *room2;

	room1 = get_room(rooms, r1);
	room2 = get_room(rooms, r2);
	if (room1 && room2)
	{
		add_room(&room1->child, r2);
		add_room(&room2->child, r1);
	}
	else
		*error = 1;
}

void	print_path(t_room *root, t_path **path)
{
	if (root == NULL)
		return ;
	print_path(root->parent, path);
	add_path(path, root->name);
}
