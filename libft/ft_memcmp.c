/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:30:22 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 10:44:45 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			e;
	unsigned char	*first;
	unsigned char	*second;

	e = 0;
	first = (unsigned char *)s1;
	second = (unsigned char *)s2;
	while (n--)
	{
		if (*first != *second)
			return (*first - *second);
		if (n)
		{
			first++;
			second++;
		}
	}
	return (0);
}
