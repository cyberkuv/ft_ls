/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 09:41:07 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 11:10:32 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		no_print(t_print fmt, char *word)
{
	if (fmt.precision == NULL)
		return (0);
	if (fmt.precision[0] == '0' || fmt.precision[0] == '.')
	{
		if (fmt.pre == '#' && (fmt.type == 'o' || fmt.type == 'O'))
			return (0);
		if (ft_strcmp(word, "0") == 0)
			return (1);
	}
	return (0);
}
