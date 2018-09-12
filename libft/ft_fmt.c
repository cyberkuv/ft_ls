/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:42:16 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 11:11:42 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			is_print(int c)
{
	if (c >= 32 && c <= 127)
		return (1);
	return (0);
}

t_print		*format_init(void)
{
	t_print *fmt;

	fmt = (t_print *)malloc(sizeof(t_print));
	fmt->flgs = '\0';
	fmt->sign = '\0';
	fmt->pre = '\0';
	fmt->width = NULL;
	fmt->precision = NULL;
	fmt->mod = NULL;
	fmt->type = '\0';
	return (fmt);
}

void		free_format(t_print *fmt)
{
	if (fmt->precision != NULL)
	{
		if (fmt->precision[0] >= '0' && fmt->precision[0] <= 9)
			free(fmt->precision);
	}
	if (fmt->width != NULL)
	{
		if (fmt->width[0] >= '0' && fmt->width[0] <= '9')
			free(fmt->width);
	}
	free(fmt);
}
