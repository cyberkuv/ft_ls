/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:58:17 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 10:54:21 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*e;
	const char	*m;
	size_t		a;
	size_t		elen;

	e = dst;
	m = src;
	a = dstsize;
	while (a-- > 0 && *e)
		e++;
	elen = e - dst;
	a = dstsize - elen;
	if (a == 0)
		return (elen + ft_strlen(src));
	while (*m != '\0')
	{
		if (a != 1)
		{
			*e++ = *m;
			a--;
		}
		m++;
	}
	*e = '\0';
	return (elen + (m - src));
}
