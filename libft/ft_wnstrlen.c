/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wnstrlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 11:10:43 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 11:11:10 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wnstrlen(wchar_t *str, int len)
{
	int x;
	int y;
	int z;

	x = 0;
	y = 0;
	z = 0;
	while (str[y] != '\0')
	{
		z = x;
		x = z + ft_sizewchr((long)str[y]);
		if (x > len)
			break ;
		y++;
	}
	return (z);
}
