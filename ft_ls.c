/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 11:18:51 by eonwe             #+#    #+#             */
/*   Updated: 2018/09/11 08:39:41 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_ls		*options(int ac, char **av)
{
	int		x;
	int		y;
	t_ls	*opts;

	opts = ft_memalloc(sizeof(t_ls));
	x = 0;
	while (++x < ac)
	{
		y = 0;
		while (av[x][0] == '-' && av[x][y++] != '\0')
		{
			if (!ft_strchr("alRrt", av[x][y]))
				inval_opt(av[x][y]);
			opts->a = (av[x][y] == 'a' ? 1 : opts->a);
			opts->u_r = (av[x][y] == 'R' ? 1 : opts->u_r);
			opts->l = (av[x][y] == 'l' ? 1 : opts->l);
			opts->t = (av[x][y] == 't' ? 1 : opts->t);
			opts->r = (av[x][y] == 'r' ? 1 : opts->r);
		}
	}
	return (opts);
}

static t_list	*valid_opts(int ac, char **av, int *valid)
{
	int		x;
	t_list	*list;
	t_name	*tmp;

	x = 0;
	list = NULL;
	tmp = (t_name *)ft_memalloc(sizeof(t_name));
	while (++x < ac)
	{
		if (av[x][0] != '-' && !can_access(av[x]))
		{
			ft_printf("ft_ls: \x1B[31m%s: %s\x1B[0m\n", av[x], strerror(errno));
			(*valid)++;
		}
		else if (ft_strchr(&av[x][0], '-') == 0 && !ft_strequ(av[x], "./ft_ls"))
		{
			tmp->name = ft_strdup(av[x]);
			lstat(tmp->name, &(tmp->stats));
			ft_lstjoin(&list, ft_lstnew(tmp, sizeof(t_name)));
			(*valid)++;
		}
	}
	free(tmp);
	return (list);
}

static t_list	*initialise_list(int ac, char **av, t_ls *opts)
{
	t_list	*list;
	t_name	*tmp;
	int		valid;

	valid = 0;
	tmp = (t_name *)ft_memalloc(sizeof(t_name));
	list = valid_opts(ac, av, &valid);
	if (valid == 0 && !ft_lstsize(list))
	{
		tmp->name = ft_strdup(".");
		lstat(tmp->name, &(tmp->stats));
		ft_lstjoin(&list, ft_lstnew(tmp, sizeof(t_name)));
	}
	else
		sort_lst(list, (opts->t ? &ft_comp_lex : &ft_sort_alp), opts->r);
	free(tmp);
	return (list);
}

int				main(int argc, char **argv)
{
	t_ls		*opts;
	t_list		*list;
	int			length;

	opts = options(argc, argv);
	list = initialise_list(argc, argv, opts);
	length = ft_lstsize(list);
	pro_args(list, opts, length);
	ft_lstdel(&list, &ft_lstfree);
	free(opts);
	return (0);
}
