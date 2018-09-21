
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahlang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:08:44 by lmahlang          #+#    #+#             */
/*   Updated: 2018/05/12 15:46:12 by lmahlang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_path(t_path **head, char *room)
{
	t_path	*current;

	current = *head;
	if (*head == NULL)
	{
		(*head) = malloc(sizeof(t_path));
		(*head)->name = room;
		(*head)->next = NULL;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = malloc(sizeof(t_path));
	current->next->name = room;
	current->next->next = NULL;
}

void	add_room(t_room **head, char *room)
{
	t_room	*current;

	current = *head;
	if (!*head)
	{
		(*head) = malloc(sizeof(t_room));
		(*head)->name = room;
		(*head)->next = NULL;
		(*head)->visited = 0;
		(*head)->child = NULL;
		(*head)->parent = NULL;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = malloc(sizeof(t_room));
	current->next->name = room;
	current->next->visited = 0;
	current->next->child = NULL;
	current->next->parent = NULL;
	current->next->next = NULL;
}

void	enqueue(t_queue **head, char *room)
{
	t_queue *current;

	current = *head;
	if (*head == NULL)
	{
		(*head) = malloc(sizeof(t_queue));
		(*head)->name = room;
		(*head)->next = NULL;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = malloc(sizeof(t_queue));
	current->next->name = room;
	current->next->next = NULL;
}

char	*dequeue(t_queue **head)
{
	char	*ret;
	t_queue *tmp;

	if (*head == NULL)
		return (NULL);
	tmp = *head;
	*head = tmp->next;
	ret = tmp->name;
	free(tmp);
	return (ret);
}
