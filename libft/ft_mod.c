/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 13:36:01 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 11:07:45 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			is_str(char type)
{
	if (type == 's' || type == 'S')
		return (1);
	else if (type == 'c' || type == 'C')
		return (2);
	return (0);
}

int			is_dioux(char type)
{
	if (type == 'd' || type == 'i' || type == 'o')
		return (1);
	if (type == 'u' || type == 'x' || type == 'X')
		return (1);
	if (type == 'D' || type == 'O' || type == 'U')
		return (2);
	return (0);
}

int			is_unsigned(char str)
{
	if (str == 'u' || str == 'U' || str == 'x' || str == 'X')
		return (1);
	else if (str == 'o' || str == 'O' || str == 'p')
		return (2);
	return (0);
}

static int	is_mod(char *str)
{
	if (str == NULL)
		return (0);
	else if (ft_strncmp(str, "ll", 2) == 0 || str[0] == 'z')
		return (5);
	else if (str[0] == 'l')
		return (4);
	else if (str[0] == 'j')
		return (3);
	else if (ft_strncmp(str, "hh", 2) == 0)
		return (1);
	else if (str[0] == 'h')
		return (2);
	return (0);
}

void		ft_mod(t_print *fmt, char *str, int *x)
{
	while (str[*x] != '\0' && is_mod(&str[*x]) > 0)
	{
		if (is_mod(&str[*x]) == 1 && is_mod(fmt->mod) <= 1)
		{
			fmt->mod = "hh";
			(*x)++;
		}
		else if (str[*x] == 'h' && is_mod(fmt->mod) <= 2)
			fmt->mod = "h";
		else if (str[*x] == 'l' && str[*x + 1] == 'l')
		{
			fmt->mod = "ll";
			(*x)++;
		}
		else if (str[*x] == 'l' && is_mod(fmt->mod) != 5)
			fmt->mod = "l";
		else if (str[*x] == 'j' && is_mod(fmt->mod) <= 3)
			fmt->mod = "j";
		else if (str[*x] == 'z')
			fmt->mod = "z";
		(*x)++;
	}
}
