/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 11:19:07 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 11:11:26 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_val_wp(char *str, int *i)
{
	char	*tmp;
	int		j;
	int		len;

	j = *i;
	len = 0;
	while (str[j] >= '0' && str[j] <= '9')
	{
		len++;
		j++;
	}
	tmp = (char *)ft_memalloc(len + 1);
	ft_strncat(tmp, &str[*i], j - *i);
	*i = j;
	return (tmp);
}

static char		*ft_star(t_print *fmt, va_list lst, int *i, int b)
{
	char	*tmp;
	int		j;

	(*i)++;
	j = va_arg(lst, int);
	if (j < 0)
	{
		if (b == 1)
			return (NULL);
		j = j * (-1);
		fmt->flgs = '-';
	}
	tmp = ft_itoa(j);
	return (tmp);
}

void			ft_wp(t_print *fmt, va_list lst, char *str, int *i)
{
	char	*tmp;
	int		b;

	if (str[*i] == '.')
		b = 1;
	else
		b = 0;
	while (str[*i] == '.')
		(*i)++;
	if (str[*i] >= '0' && str[*i] <= '9')
		tmp = ft_val_wp(str, i);
	else if (str[*i] == '*')
		tmp = ft_star(fmt, lst, i, b);
	else
	{
		b == 1 ? (fmt->precision = ".") : 0;
		return ;
	}
	if (b == 1)
		fmt->precision = tmp;
	else
		fmt->width = tmp;
}
