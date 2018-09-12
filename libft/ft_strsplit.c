/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 10:52:38 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 10:57:22 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		e;
	size_t	m;
	int		a;
	char	**col;

	e = 0;
	m = 0;
	if (!s || !c)
		return (NULL);
	if (!(col = (char **)malloc(sizeof(char *) * (ft_wdsort(s, c) + 1))))
		return (NULL);
	while (s[e])
	{
		if (s[e] == c)
			e++;
		else
		{
			a = e;
			while (s[e] && s[e] != c)
				e++;
			col[m++] = ft_strsub(s, a, (e - a));
		}
	}
	col[m] = 0;
	return (col);
}
