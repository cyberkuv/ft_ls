/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:12:54 by eonwe             #+#    #+#             */
/*   Updated: 2018/09/05 16:42:49 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

int		convert(int value, int base, int *store)
{
	int	i;
	int	val;

	val = value;
	i = 0;
	while (val)
	{
		store[i] = ft_abs(val % base);
		val /= base;
		i++;
	}
	if (value < 0 && base == 10)
	{
		store[i] = '-';
		i++;
	}
	return (i);
}

char	*ft_itoa_base(int value, int base)
{
	char	*base_digits;
	int		store[32];
	int		i;
	int		j;
	char	*ret;

	j = 0;
	base_digits = "0123456789abcdef";
	if (base < 2 || base > 16 || value == 0)
		return ("0");
	i = convert(value, base, store);
	ret = (char *)malloc(sizeof(char) * i + 1);
	ret[i] = '\0';
	while (i--)
	{
		if (store[i] == '-')
			ret[j] = store[i];
		else
			ret[j] = base_digits[store[i]];
		j++;
	}
	return (ret);
}
