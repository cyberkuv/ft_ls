/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 10:37:29 by eonwe             #+#    #+#             */
/*   Updated: 2018/09/08 16:59:11 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *begin_list)
{
	int		x;
	t_list	*list;

	x = 0;
	list = begin_list;
	while (list)
	{
		x++;
		list = list->next;
	}
	return (x);
}
