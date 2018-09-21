/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahlang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:31:50 by lmahlang          #+#    #+#             */
/*   Updated: 2018/06/01 18:07:33 by lmahlang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		start_and_end(char **start, char **end, char *line, int *start_end)
{
	int	error;

	error = 0;
	if (*start_end == 1)
	{
		if (*start != NULL)
			error = 1;
		*start = line;
	}
	if (*start_end == 2)
	{
		if (*end != NULL)
			error = 1;
		*end = line;
	}
	*start_end = 0;
	return (error);
}

void	empty_line(char *line, int *error)
{
	int len;

	len = ft_strlen(line);
	if (!len)
		*error = 1;
}

void	check_cord(char *x, char *y, int *error)
{
	if (x != NULL)
	{
		while (*x && *x != '#')
		{
			if (!ft_isdigit(*x))
				*error = 1;
			x++;
		}
	}
	if (y != NULL)
	{
		while (*y && *y != '#')
		{
			if (!ft_isdigit(*y))
				*error = 1;
			y++;
		}
	}
}
