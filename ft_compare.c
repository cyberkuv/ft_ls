/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 08:44:55 by eonwe             #+#    #+#             */
/*   Updated: 2018/09/11 08:37:28 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_sort_alp(t_name *dir1, t_name *dir2, int rev_cmp)
{
	int res;

	res = (ft_strcmp(dir1->name, dir2->name));
	if (rev_cmp)
		return (res < 0 ? 1 : 0);
	else
		return (res > 0 ? 1 : 0);
}

int		ft_comp_lex(t_name *dir1, t_name *dir2, int rev_cmp)
{
	if (dir1->stats.st_mtimespec.tv_sec == dir2->stats.st_mtimespec.tv_sec)
	{
		if (dir1->stats.st_mtimespec.tv_nsec ==
				dir2->stats.st_mtimespec.tv_nsec)
			return (ft_sort_alp(dir1, dir2, rev_cmp));
		if (rev_cmp)
			return (dir1->stats.st_mtimespec.tv_nsec >
					dir2->stats.st_mtimespec.tv_nsec);
		else
			return (dir1->stats.st_mtimespec.tv_nsec <
					dir2->stats.st_mtimespec.tv_nsec);
	}
	if (rev_cmp)
		return (dir1->stats.st_mtimespec.tv_sec >
				dir2->stats.st_mtimespec.tv_sec);
	else
		return (dir1->stats.st_mtimespec.tv_sec <
				dir2->stats.st_mtimespec.tv_sec);
}

void	sort_lst(t_list *start, int (*d)(t_name *, t_name *, int), int rev_cmp)
{
	int		swap;
	t_list	*x;

	if (start == NULL)
		return ;
	swap = 1;
	while (swap)
	{
		swap = 0;
		x = start;
		while (x->next != NULL)
		{
			if (d(x->content, x->next->content, rev_cmp))
			{
				ft_lstswap(x, x->next);
				swap = 1;
			}
			x = x->next;
		}
	}
}

void	cmp_len_wdth(t_list *list, unsigned int *x)
{
	t_name	*tmp;

	ft_bzero(x, sizeof(int) * 7);
	while (list)
	{
		tmp = (t_name *)list->content;
		x[0] = MAX(ft_nbrlen(tmp->stats.st_nlink), x[0]);
		if (getpwuid(tmp->stats.st_uid))
			x[1] = MAX(ft_strlen(getpwuid(tmp->stats.st_uid)->pw_name), x[1]);
		else
			x[1] = MAX(ft_strlen(ft_itoa(tmp->stats.st_uid)), x[1]);
		if (getgrgid(tmp->stats.st_gid))
			x[2] = MAX(ft_strlen(getgrgid(tmp->stats.st_gid)->gr_name), x[2]);
		else
			x[2] = MAX(ft_strlen(ft_itoa(tmp->stats.st_gid)), x[2]);
		x[3] = MAX(ft_nbrlen(tmp->stats.st_size), x[3]);
		x[4] = MAX(ft_nbrlen(tmp->stats.st_rdev >> 24), x[4]);
		x[5] = MAX(ft_nbrlen(tmp->stats.st_rdev & 0xFFFFFF), x[5]);
		x[6] = (((tmp->stats.st_mode & S_IFMT) == S_IFBLK) ||
				((tmp->stats.st_mode & S_IFMT) == S_IFCHR) ? 1 : 0);
		list = list->next;
	}
	x[0]++;
}
