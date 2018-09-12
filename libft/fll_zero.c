/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fll_zero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 10:22:04 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 11:10:49 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		after_pre(char **str, char *type, int *width, int *i)
{
	int j;

	j = 0;
	if (type[j] == '-' || type[j] == '+' || type[j] == ' ')
	{
		*str[*i] = type[j];
		(*i)++;
		(*width)++;
		j++;
	}
	else if (type[j] == '0' && (type[j + 1] == 'x' || type[j + 1] == 'X'))
	{
		type[j + 1] == 'x' ? ft_strcat(*str, "0x") : 0;
		type[j + 1] == 'X' ? ft_strcat(*str, "0X") : 0;
		j = 2;
		*i = 2;
		*width = *width + 2;
	}
	return (j);
}

char			*fill_zero(t_print fmt, char *type, int width)
{
	char	*str;
	int		i;
	int		j;

	if (type == NULL || width <= 0)
		return (NULL);
	if (is_dioux(fmt.type) == 0 && fmt.type != 'p')
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)ft_memalloc(ft_strlen(type) + width);
	j = after_pre(&str, type, &width, &i);
	while (i < width)
	{
		ft_strcat(str, "0");
		i++;
	}
	ft_strcat(str, &type[j]);
	if (type != NULL && is_dioux(fmt.type) > 0 && ft_strcmp(type, "0") != 0)
		free(type);
	return (str);
}
