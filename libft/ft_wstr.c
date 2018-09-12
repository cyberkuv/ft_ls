/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 08:18:46 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 11:08:38 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_sizebyte(uint64_t nbr)
{
	int size;

	size = 0;
	while (nbr != 0)
	{
		nbr = nbr >> 1;
		size++;
	}
	return (size);
}

int			ft_sizewchr(long x)
{
	int size;

	size = ft_sizebyte(x);
	if (size < 8)
		return (1);
	else if (size < 12)
		return (2);
	else if (size < 17)
		return (3);
	else if (size < 22)
		return (4);
	return (0);
}

int			ft_wstrlen(wchar_t *str)
{
	int len;
	int x;

	len = 0;
	x = 0;
	while (str[x] != '\0')
	{
		len = len + ft_sizewchr((long)str[x]);
		x++;
	}
	return (len);
}

static void	ft_write(wchar_t c, int mask, int left, int right)
{
	unsigned int nbr;

	nbr = ((unsigned int)c << left >> right) | mask;
	write(1, &nbr, 1);
}

void		ft_putwchar(wchar_t c)
{
	int size;

	size = ft_sizebyte((long)c);
	if (size < 8)
		ft_putchar(c);
	else if (size < 12)
	{
		ft_write(c, 192, 0, 6);
		ft_write(c, 128, 26, 26);
	}
	else if (size < 17)
	{
		ft_write(c, 224, 0, 12);
		ft_write(c, 128, 20, 26);
		ft_write(c, 128, 26, 26);
	}
	else if (size < 22)
	{
		ft_write(c, 240, 0, 18);
		ft_write(c, 128, 14, 26);
		ft_write(c, 128, 20, 26);
		ft_write(c, 128, 26, 26);
	}
}
