/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 09:51:29 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 10:37:15 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_zero(void)
{
	char *bin;

	bin = (char *)ft_memalloc(2);
	bin[0] = '0';
	return (bin);
}

char		*ft_base(uint64_t nbr, int (*val)(uint64_t *nbr))
{
	char	tab[sizeof(nbr) * 8];
	char	*bin;
	int		i;
	int		j;

	if (nbr == 0)
		return (ft_zero());
	i = 0;
	while (nbr != 0)
	{
		tab[i] = '0' + val(&nbr);
		i++;
	}
	tab[i] = '\0';
	bin = (char *)ft_memalloc(i + 1);
	j = 0;
	i--;
	while (i >= 0)
	{
		bin[j] = tab[i];
		j++;
		i--;
	}
	return (bin);
}
