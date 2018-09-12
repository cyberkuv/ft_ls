/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 09:49:46 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 11:10:06 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long	ft_dizaine(char **str, unsigned long long n)
{
	unsigned long long	nbr;
	unsigned long long	dizaine;
	int					i;

	nbr = n;
	dizaine = 1;
	i = 1;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		i++;
		dizaine = dizaine * 10;
	}
	*str = (char*)malloc(sizeof(char) * (i + 1));
	return (dizaine);
}

char						*ft_ulltoa(unsigned long long n)
{
	unsigned long long	dizaine;
	unsigned long long	s;
	char				*str;
	int					i;

	i = 0;
	str = NULL;
	dizaine = ft_dizaine(&str, n);
	if (str == NULL)
		return (NULL);
	str[i] = '0' + (n / dizaine);
	s = 0;
	while (dizaine > 9)
	{
		s = s + (str[i] - '0') * dizaine;
		dizaine = dizaine / 10;
		(i)++;
		str[i] = (n - s) / dizaine + '0';
	}
	str[i + 1] = '\0';
	return (str);
}
