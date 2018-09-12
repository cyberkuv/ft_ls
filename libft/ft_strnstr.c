/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 16:04:24 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 10:56:30 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *stack, const char *sub, size_t len)
{
	size_t e;
	size_t m;

	e = 0;
	while (e < len && stack[e] != '\0')
	{
		m = 0;
		while (e + m < len && stack[e + m] == sub[m] && sub[m] != '\0')
			m++;
		if (sub[m] == '\0')
			return ((char *)(stack + e));
		e++;
	}
	return (NULL);
}
