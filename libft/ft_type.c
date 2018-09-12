/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:37:27 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 11:08:02 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	write_type(t_print fmt, char str, int len)
{
	fmt.type = 's';
	fmt.flgs != '-' ? add_width(fmt, L"%", &len) : 0;
	ft_putchar(str);
	fmt.flgs == '-' ? add_width(fmt, L"%", &len) : 0;
	len++;
	return (len);
}

static int	add_umod(t_print fmt, va_list lst)
{
	int len;

	len = 0;
	if (fmt.mod == NULL)
		return (0);
	if (ft_strcmp(fmt.mod, "hh") == 0)
		len = write_nbr(fmt, (long long)(unsigned char)va_arg(lst, int));
	else if (fmt.mod[0] == 'h')
		len = write_nbr(fmt, (long long)(unsigned short)va_arg(lst, int));
	else if (fmt.mod[0] == 'l')
		len = write_nbr(fmt, (long long)va_arg(lst, unsigned long));
	else if (ft_strcmp(fmt.mod, "ll") == 0)
		len = write_nbr(fmt, va_arg(lst, unsigned long long));
	else if (fmt.mod[0] == 'j')
		len = write_nbr(fmt, (long long)va_arg(lst, uintmax_t));
	else if (fmt.mod[0] == 'z')
		len = write_nbr(fmt, (long long)va_arg(lst, size_t));
	return (len);
}

static int	add_mod(t_print fmt, va_list lst)
{
	int len;

	len = 0;
	if (fmt.mod == NULL)
		return (0);
	if (fmt.type == 'u' || fmt.type == 'o' ||
			fmt.type == 'x' || fmt.type == 'X')
		len = add_umod(fmt, lst);
	else if (ft_strcmp(fmt.mod, "hh") == 0)
		len = write_nbr(fmt, (long long)(char)va_arg(lst, int));
	else if (fmt.mod[0] == 'h')
		len = write_nbr(fmt, (long long)(short)va_arg(lst, int));
	else if (fmt.mod[0] == 'l')
		len = write_nbr(fmt, (long long)va_arg(lst, long));
	else if (ft_strcmp(fmt.mod, "ll") == 0)
		len = write_nbr(fmt, va_arg(lst, long long));
	else if (fmt.mod[0] == 'j')
		len = write_nbr(fmt, (long long)va_arg(lst, intmax_t));
	else if (fmt.mod[0] == 'z')
		len = write_nbr(fmt, (long long)va_arg(lst, size_t));
	return (len);
}

static int	ft_dioux(t_print fmt, va_list lst, char str)
{
	int len;

	len = 0;
	if (str == 'd' || str == 'i')
		len = write_nbr(fmt, (long long)va_arg(lst, int));
	else if (str == 'D')
		len = write_nbr(fmt, (long long)va_arg(lst, long int));
	else if (str == 'u' || str == 'x' || str == 'X' || str == 'o' || str == 'b')
		len = write_nbr(fmt, (long long)va_arg(lst, unsigned int));
	else if (str == 'U' || str == 'O' || str == 'p')
		len = write_nbr(fmt, (long long)va_arg(lst, unsigned long));
	else
		return (-1);
	return (len);
}

int			ft_type(t_print *fmt, va_list lst, char str)
{
	int len;

	len = 0;
	if (is_dioux(str) > 0 || str == 'p' || str == 'b')
	{
		fmt->type = str;
		if (fmt->mod != NULL && is_dioux(str) == 1)
			len = add_mod(*fmt, lst);
		else
			len = ft_dioux(*fmt, lst, str);
	}
	else if (str == '%')
		return (write_type(*fmt, str, len));
	else if (is_str(str) > 0)
	{
		fmt->type = str;
		len = ft_sc(*fmt, lst, str);
	}
	else if (is_dioux(str) == 0 && is_str(str) == 0 && str != 'p' && str != 'b'
			&& is_flg(str) == 0 && ft_isprint(str) == 1 && str != '.')
		len = write_type(*fmt, str, len);
	return (len);
}
