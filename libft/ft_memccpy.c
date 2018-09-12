/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:29:18 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 10:44:31 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				e;
	unsigned char		*s1;
	const unsigned char	*s2;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	e = 0;
	while (e < n)
	{
		s1[e] = s2[e];
		if (s2[e] == (unsigned char)c)
			return (s1 + e + 1);
		e++;
	}
	return (NULL);
}
