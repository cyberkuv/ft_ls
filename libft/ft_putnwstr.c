/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:46:03 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 11:01:36 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbroctet(wchar_t c)
{
	int nb;

	nb = ft_sizebyte(c);
	if (nb < 8)
		return (1);
	else if (nb < 12)
		return (2);
	else if (nb < 17)
		return (3);
	else if (nb < 22)
		return (4);
	return (-1);
}

void		ft_putnwstr(wchar_t *str, int len)
{
	int i;

	i = 0;
	while (1)
	{
		len = len - ft_nbroctet(str[i]);
		if (len < 0 || str[i] == '\0')
			break ;
		ft_putwchar(str[i]);
		i++;
	}
}
