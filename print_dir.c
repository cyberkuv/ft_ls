/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 09:45:54 by eonwe             #+#    #+#             */
/*   Updated: 2018/09/10 12:22:46 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	traverse(t_list *x, t_list *list, t_ls *opts)
{
	while (x)
	{
		if (S_ISDIR(((t_name *)x->content)->stats.st_mode) &&
				!ft_strequ(((t_name *)x->content)->name, ".") &&
				!ft_strequ(((t_name *)x->content)->name, ".."))
			print_dir(list, x, opts);
		x = x->next;
	}
	ft_lstdel(&x, ft_lstfree);
}

void		print_dir(t_list *dir, t_list *list, t_ls *opts)
{
	t_list			*x;
	t_list			*t_x;
	unsigned int	dev[7];

	if (!(x = ft_opendir(dir, list, opts)))
		return ;
	if (opts->l)
		ft_blocks(x);
	sort_lst(x, (opts->t) ? ft_comp_lex : ft_sort_alp, opts->r);
	t_x = x;
	cmp_len_wdth(x, dev);
	while (x)
	{
		if (opts->l)
			print_l((t_name *)x->content, ((t_name *)list->content), dev);
		else
			ft_printf("\x1B[31m%s\x1B[0m\n", ((t_name *)x->content)->name);
		x = x->next;
	}
	x = t_x;
	if (opts->u_r)
		traverse(x, list, opts);
}
