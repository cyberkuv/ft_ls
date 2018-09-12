/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_chr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 10:39:20 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 10:48:55 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_c(t_print fmt, va_list lst, char str)
{
	wchar_t c;
	int		width;

	width = 0;
	if (fmt.mod != NULL && fmt.mod[0] == 'l')
		str == 'c' ? str = 'C' : 0;
	fmt.flgs != '-' ? add_width(fmt, L"1", &width) : 0;
	if (str == 'c')
		ft_putchar((char)va_arg(lst, int));
	else
		ft_putwchar((c = va_arg(lst, wchar_t)));
	fmt.flgs == '-' ? add_width(fmt, L"1", &width) : 0;
	if (str == 'C')
		width = ft_sizewchr((long)c);
	else
		width++;
	return (width);
}

static void	s_empty(t_print fmt, wchar_t **word)
{
	if (fmt.precision != NULL && (fmt.precision[0] == '.'))
	{
		if (fmt.type == 's')
			*word = (wchar_t *)"";
		else
			*word = L"";
	}
	else if (*word == NULL)
	{
		fmt.type == 's' ? (*word = (wchar_t *)"(null)") : 0;
		fmt.type == 'S' ? (*word = L"(null)") : 0;
	}
}

static char	ft_s(t_print fmt, va_list lst, wchar_t **word, int *width)
{
	if (fmt.mod != NULL && fmt.mod[0] == 'l')
		fmt.type == 's' ? fmt.type = 'S' : 0;
	if (fmt.type == 'S')
		*word = va_arg(lst, wchar_t *);
	else if (fmt.type == 's')
		*word = (wchar_t *)va_arg(lst, char *);
	s_empty(fmt, word);
	if (word != NULL)
	{
		fmt.flgs != '-' ? add_width(fmt, *word, width) : 0;
		if (fmt.precision != NULL)
		{
			if (fmt.type == 's' && fmt.precision[0] != '.')
				ft_putnstr((char *)*word, ft_atoi(fmt.precision));
			else if (fmt.type == 'S' && fmt.precision[0] != '.')
				ft_putnwstr(*word, ft_atoi(fmt.precision));
		}
		else if (fmt.type == 's')
			ft_putstr((char *)*word);
		else
			ft_putwstr(*word);
		fmt.flgs == '-' ? add_width(fmt, *word, width) : 0;
	}
	return (fmt.type);
}

int			ft_sc(t_print fmt, va_list lst, char str)
{
	wchar_t *word;
	int		width;

	width = 0;
	word = NULL;
	if (str == 'c' || str == 'C')
		return (ft_c(fmt, lst, str));
	else if (str == 'S' || str == 's')
		str = ft_s(fmt, lst, &word, &width);
	if (fmt.precision != NULL && fmt.precision[0] != '.' &&
			(str == 's' || str == 'S') && ft_atoi(fmt.precision)
			< (int)ft_strlen((char *)word))
		width = ft_atoi(fmt.precision) + width;
	else if (word != NULL && str == 's')
		width = ft_strlen((char *)word) + width;
	else if (str == 'S' && word != NULL && fmt.precision != NULL)
		width = ft_wnstrlen(word, ft_atoi(fmt.precision)) + width;
	else if (word != NULL && str == 'S')
		width = ft_wstrlen(word) + width;
	if ((str == 's' || str == 'S') && width == 0)
		width = -1;
	return (width);
}
