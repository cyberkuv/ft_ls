/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoao.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 09:50:42 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 11:09:43 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	val_oct(unsigned long long *nbr)
{
	int octal;

	octal = 0;
	if (*nbr & (long long)1)
		octal = 1;
	if (*nbr & (long long)2)
		octal = octal + 2;
	if (*nbr & (long long)4)
		octal = octal + 4;
	*nbr = *nbr >> 3;
	return (octal);
}

char		*ft_lltoao(unsigned long long nbr)
{
	return (ft_base(nbr, val_oct));
}
