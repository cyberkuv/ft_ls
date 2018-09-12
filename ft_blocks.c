/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blocks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 09:49:44 by eonwe             #+#    #+#             */
/*   Updated: 2018/09/10 11:40:03 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_blocks(t_list *list)
{
	blkcnt_t	blks;
	int			len;

	blks = 0;
	if (list)
		len = ((t_name *)list->content)->stats.st_blksize / 1024;
	while (list)
	{
		blks += ((t_name *)list->content)->stats.st_blocks;
		list = list->next;
	}
	ft_printf("\033[33;1mTotal %u\033[33;0m\n", blks, len);
}
