/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahlang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 04:52:00 by lmahlang          #+#    #+#             */
/*   Updated: 2017/09/29 04:52:10 by lmahlang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		min_int(int sign, int fd)
{
	if (sign)
		ft_putstr_fd("-2147483648", fd);
	else
		ft_putstr_fd("2147483647", fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		return (min_int(1, fd));
	else if (n == 214783647)
		return (min_int(0, fd));
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		n = n + 48;
		write(fd, &n, 1);
	}
}
