/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 14:06:04 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 11:03:55 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wdsort(char const *s, char c)
{
	int	wdsort1;
	int	wdsort2;

	wdsort1 = 0;
	wdsort2 = 0;
	while (s[wdsort1])
	{
		if (s[wdsort1] == c)
			;
		else if (!wdsort1 || s[wdsort1 - 1] == c)
			wdsort2++;
		wdsort1++;
	}
	return (wdsort2);
}
