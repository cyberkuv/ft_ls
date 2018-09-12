/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:57:39 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 11:00:59 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int e;

	e = n;
	if (e < 0)
	{
		e = e * (-1);
		ft_putchar_fd('-', fd);
	}
	if (e > 9)
	{
		ft_putnbr_fd(e / 10, fd);
		ft_putnbr_fd(e % 10, fd);
	}
	else
		ft_putchar_fd(e + '0', fd);
}
