/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 08:32:18 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 11:07:28 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	put_fmt(va_list lst, char *str, int *x, int len)
{
	int fmt;

	fmt = 0;
	(*x)++;
	fmt = ft_fmt(lst, str, x);
	fmt < 0 ? (fmt = 0) : 0;
	len = len + fmt;
	return (len);
}

int			is_flg(char c)
{
	if (c == '+' || c == '-' || c == '#' || c == ' ' || c == '0')
		return (1);
	return (0);
}

void		ft_flgs(t_print *fmt, char *str, int *x)
{
	while (str[*x] != '\0' && is_flg(str[*x]) == 1)
	{
		if (str[*x] == '+')
			fmt->sign = '+';
		else if (str[*x] == ' ' && fmt->sign != '+')
			fmt->sign = ' ';
		else if (str[*x] == '-')
			fmt->flgs = '-';
		else if (str[*x] == '0' && fmt->flgs != '-')
			fmt->flgs = '0';
		else if (str[*x] == '#')
			fmt->pre = '#';
		(*x)++;
	}
}

int			ft_fmt(va_list lst, const char *src, int *x)
{
	t_print		*fmt;
	int			len;
	char		*str;

	str = (char *)src;
	len = 0;
	fmt = format_init();
	while (src[*x] != '\0')
	{
		ft_flgs(fmt, str, x);
		ft_wp(fmt, lst, str, x);
		ft_mod(fmt, str, x);
		if ((len = ft_type(fmt, lst, str[*x])) != 0)
		{
			(*x)++;
			break ;
		}
	}
	return (len);
}

int			ft_printf(const char *fmt, ...)
{
	va_list	lst;
	int		x;
	int		len;

	x = 0;
	len = 0;
	va_start(lst, fmt);
	while (fmt[x] != '\0')
	{
		if (fmt[x] == '%')
			len = put_fmt(lst, (char *)fmt, &x, len);
		else
		{
			ft_putchar(fmt[x]);
			len++;
			x++;
		}
	}
	va_end(lst);
	return (len);
}
