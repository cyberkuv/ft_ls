/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 08:00:05 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 11:08:17 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_width(t_print fmt, wchar_t *type, int *width)
{
	int len;
	int prc;

	if (fmt.type == 'S')
		len = ft_wstrlen(type);
	else
		len = ft_strlen((char *)type);
	if (fmt.precision != NULL && fmt.precision[0] != '.')
	{
		prc = ft_atoi(fmt.precision);
		if (fmt.type == 's' && prc < len)
			len = prc;
		else if (fmt.type == 'S' && prc < len)
			len = ft_wnstrlen(type, prc);
	}
	if (fmt.width == NULL)
		return ((char *)type);
	else if (fmt.width[0] >= '0' && fmt.width[0] <= '9')
		*width = ft_atoi(fmt.width) - len;
	else
		return ((char *)type);
	return (NULL);
}

static char	*flags_str_zero(t_print fmt, wchar_t *type, int *width)
{
	char *str;

	str = NULL;
	if (fmt.flgs == '0')
	{
		if (fmt.precision == NULL || (fmt.precision[0] == '.'
					&& is_dioux(fmt.type) != 1))
			str = fill_zero(fmt, (char *)type, *width);
		if (fmt.precision == NULL && is_str(fmt.type) == 0)
			*width = 0;
	}
	return (str);
}

char		*add_width(t_print fmt, wchar_t *type, int *width)
{
	int		x;
	char	*str;
	char	c;

	if (ft_width(fmt, type, width) != NULL)
		return ((char *)type);
	if (no_print(fmt, (char *)type) == 1)
		(*width)++;
	str = flags_str_zero(fmt, type, width);
	*width < 0 ? *width = 0 : 0;
	if (str != NULL && is_str(fmt.type) == 0)
		return (str);
	x = 0;
	if (is_str(fmt.type) > 0 && fmt.flgs == '0')
		c = '0';
	else
		c = ' ';
	while (x < *width && *width > 0)
	{
		ft_putchar(c);
		x++;
	}
	return ((char *)type);
}
