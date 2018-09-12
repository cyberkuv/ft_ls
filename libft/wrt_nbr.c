/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrt_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 09:17:56 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 11:08:58 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*add_precision(t_print fmt, char *type, int *prcsn)
{
	char *str;

	str = NULL;
	if (fmt.precision == NULL)
		return (type);
	else if (fmt.precision[0] >= '0' && fmt.precision[0] <= '9')
		*prcsn = ft_atoi(fmt.precision) - ft_strlen(type);
	else
		return (type);
	if (type != NULL && (type[0] == '-' || type[0] == '+'))
		(*prcsn)++;
	str = fill_zero(fmt, type, *prcsn);
	if (str != NULL)
		return (str);
	return (type);
}

static char	*add_prenbr(t_print fmt, char *nbr)
{
	char *pre;
	char *str;

	pre = NULL;
	if (fmt.pre == '#' && ft_strcmp(nbr, "0") != 0)
	{
		fmt.type == 'x' ? (pre = "0x") : 0;
		fmt.type == 'X' ? (pre = "0X") : 0;
	}
	if (fmt.pre == '#' && (fmt.type == 'o' || fmt.type == 'O'))
		nbr[0] != '0' ? (pre = "0") : 0;
	if (fmt.sign == ' ' && nbr[0] != '-' && is_unsigned(fmt.type) == 0)
		pre = " ";
	else if (fmt.type == 'd' || fmt.type == 'D' || fmt.type == 'i')
	{
		if (fmt.sign == '+' && nbr[0] != '-')
			pre = "+";
	}
	if (pre != NULL)
	{
		str = nbr;
		nbr = ft_strjoin(pre, str);
		free(str);
	}
	return (nbr);
}

static char	*fill_word(char type, long long nbr)
{
	char *word;

	word = NULL;
	if (type == 'd' || type == 'D' || type == 'i')
		word = ft_lltoa(nbr);
	else if (type == 'u' || type == 'U')
		word = ft_ulltoa((unsigned long long)nbr);
	else if (type == 'x' || type == 'p')
		word = ft_lltoah(nbr, 1);
	else if (type == 'X')
		word = ft_lltoah(nbr, 2);
	else if (type == 'o' || type == 'O')
		word = ft_lltoao(nbr);
	return (word);
}

static char	*p_precision(t_print fmt, char *word, int *width, int *b)
{
	char *tmp;

	if (fmt.type == 'p' && ft_strcmp(word, "0") == 0 && *b == 1)
	{
		tmp = word;
		word = ft_strjoin(tmp, "x");
		tmp != NULL ? free(tmp) : 0;
		*b = 0;
	}
	word = add_precision(fmt, word, width);
	if (fmt.type == 'p' && ft_strcmp(word, "0x") != 0)
	{
		tmp = word;
		word = ft_strjoin("0x", tmp);
		tmp != NULL ? free(tmp) : 0;
	}
	return (word);
}

int			write_nbr(t_print fmt, long long nbr)
{
	char	*word;
	int		width;
	int		b;

	width = 0;
	b = 0;
	word = fill_word(fmt.type, nbr);
	b = no_print(fmt, word);
	if (fmt.type == 'p')
		word = p_precision(fmt, word, &width, &b);
	else
		word = add_precision(fmt, word, &width);
	width = 0;
	word = add_prenbr(fmt, word);
	if (fmt.flgs != '-')
		word = add_width(fmt, (wchar_t *)word, &width);
	b == 0 ? ft_putstr(word) : 0;
	fmt.flgs == '-' ? add_width(fmt, (wchar_t *)word, &width) : 0;
	b == 0 ? (width = width + ft_strlen(word)) : 0;
	if (b == 1 && width == 0)
		width = -1;
	word == NULL ? width = 0 : 0;
	word != NULL ? free(word) : 0;
	return (width);
}
