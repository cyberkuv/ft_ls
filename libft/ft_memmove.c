/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:29:40 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 10:45:16 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			e;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	e = 0;
	if (s2 < s1)
	{
		e = len;
		while (e > 0)
		{
			e--;
			(s1[e]) = (s2[e]);
		}
	}
	else
	{
		while (e < len)
		{
			(s1[e]) = (s2[e]);
			e++;
		}
	}
	return (s1);
}
