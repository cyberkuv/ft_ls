/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pro_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 09:36:53 by eonwe             #+#    #+#             */
/*   Updated: 2018/09/10 14:05:00 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		pro_args(t_list *list, t_ls *opts, int len)
{
	t_list			*prev;
	unsigned int	dev[7];

	prev = NULL;
	cmp_len_wdth(list, dev);
	while (list)
	{
		len = 0;
		if (S_ISDIR(((t_name *)list->content)->stats.st_mode))
			print_dir(NULL, list, opts);
		prev = list;
		list = list->next;
	}
}
