/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 08:12:53 by eonwe             #+#    #+#             */
/*   Updated: 2018/09/08 17:59:30 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_list	*ft_readdir(DIR *dir, t_list *list, t_ls *opts)
{
	struct dirent	*file;
	t_name			*x;
	t_list			*y;

	y = NULL;
	x = (t_name *)ft_memalloc(sizeof(t_name));
	file = readdir(dir);
	while (file)
	{
		if (opts->a || file->d_name[0] != '.')
		{
			x->name = ft_strdup(file->d_name);
			lstat(ft_strjoin(((t_name *)list->content)->name, file->d_name),
					&x->stats);
			ft_lstjoin(&y, ft_lstnew(x, sizeof(t_name)));
		}
		file = readdir(dir);
	}
	free(x);
	return (y);
}

static t_list	*ft_modify(t_list *dir, t_list *list)
{
	char *dir_fld;
	char *dir_name;
	char *file;

	dir_fld = NULL;
	if (dir)
		dir_name = ft_strdup(((t_name *)dir->content)->name);
	file = ft_strdup(((t_name *)list->content)->name);
	if (dir && (!ft_strequ(dir_name, file)))
	{
		dir_fld = ft_strjoin(dir_name, file);
		file = ft_strjoin(dir_fld, "/");
	}
	else
		file = ft_strjoin(file, "/");
	if (dir && !ft_strequ("./", file))
		ft_printf("\n%s:\n", file);
	free(((t_name *)list->content)->name);
	((t_name *)list->content)->name = file;
	if (dir)
		free(dir_name);
	free(dir_fld);
	return (list);
}

t_list			*ft_opendir(t_list *local, t_list *list, t_ls *opts)
{
	DIR		*dir;
	t_list	*y;
	char	*file;

	y = NULL;
	file = ft_strdup(((t_name *)list->content)->name);
	list = ft_modify(local, list);
	dir = opendir(((t_name *)list->content)->name);
	if (!dir)
	{
		ft_printf("ft_ls: %s: %s", file, strerror(errno));
		return (NULL);
	}
	free(file);
	y = ft_readdir(dir, list, opts);
	closedir(dir);
	return (y);
}
