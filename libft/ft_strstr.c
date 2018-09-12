/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:48:14 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 10:57:38 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *stack, const char *sub)
{
	int em;
	int ma;
	int esize;

	em = 0;
	ma = 0;
	esize = ft_strlen(sub);
	if (esize == 0)
		return ((char *)stack);
	while (stack[em] != '\0')
	{
		while (sub[ma] == stack[em + ma])
		{
			if (ma == esize - 1)
				return ((char *)stack + em);
			ma++;
		}
		ma = 0;
		em++;
	}
	return (0);
}
