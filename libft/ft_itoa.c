/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 10:51:59 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 11:03:14 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t		ft_iconvert(int n)
{
	size_t			e;

	e = 1;
	while (n /= 10)
		e++;
	return (e);
}

char				*ft_itoa(int n)
{
	unsigned int	lst;
	size_t			len;
	char			*str;

	len = ft_iconvert(n);
	lst = n;
	if (n < 0)
	{
		lst = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = lst % 10 + '0';
	while (lst /= 10)
		str[--len] = lst % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
