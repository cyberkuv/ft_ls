/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 08:57:15 by eonwe             #+#    #+#             */
/*   Updated: 2018/09/11 11:33:12 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		permissions(mode_t mode)
{
	ft_putchar((mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((mode & S_IWUSR) ? 'w' : '-');
	if (mode & S_ISUID)
		ft_putchar((mode & S_IXUSR) ? 's' : 'S');
	else
		ft_putchar((mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((mode & S_IWGRP) ? 'w' : '-');
	if (mode & S_ISGID)
		ft_putchar((mode & S_IXGRP) ? 's' : 'S');
	else
		ft_putchar((mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((mode & S_IROTH) ? 'r' : '-');
	ft_putchar((mode & S_IWOTH) ? 'w' : '-');
	if (mode & S_ISVTX)
		ft_putchar((mode & S_IXOTH) ? 't' : 'T');
	else
		ft_putchar((mode & S_IXOTH) ? 'x' : '-');
}

static void		file_types(mode_t mode)
{
	if ((mode & S_IFMT) == S_IFREG)
		ft_putchar('-');
	else if ((mode & S_IFMT) == S_IFSOCK)
		ft_putchar('s');
	else if ((mode & S_IFMT) == S_IFLNK)
		ft_putchar('l');
	else if ((mode & S_IFMT) == S_IFCHR)
		ft_putchar('c');
	else if ((mode & S_IFMT) == S_IFBLK)
		ft_putchar('b');
	else if ((mode & S_IFMT) == S_IFIFO)
		ft_putchar('f');
	else if ((mode & S_IFMT) == S_IFDIR)
		ft_putchar('d');
	permissions(mode);
}

static void		ft_lsl(t_name *dir, t_name *local, mode_t mode)
{
	char	*path;
	char	link_buf[1024];
	ssize_t	x;

	if ((mode & S_IFMT) == S_IFLNK)
	{
		ft_bzero(link_buf, sizeof(link_buf));
		if (local)
			path = ft_strjoin(local->name, ft_strjoin("/", dir->name));
		else
			path = ft_strdup(dir->name);
		x = readlink(path, link_buf, sizeof(link_buf));
		/*if (x < 0)
		{
			free(path);
			perror("readlink");
			exit(EXIT_FAILURE);
		}*/
		link_buf[x] = '\0';
		ft_printf("\x1B[32m%s -> %s\x1B[0m\n", dir->name, link_buf);
		free(path);
	}
	else
		ft_printf("\x1B[31m%s\x1B[0m\n", dir->name);
}

static void		ft_time(time_t mod_tm)
{
	char	*str;
	char	*s1;
	char	*s2;
	time_t	x;

	x = time(NULL);
	if ((str = ctime(&mod_tm)) == NULL)
		return ;
	s1 = str + 4;
	s2 = str + 10;
	*s2 = 0;
	ft_putstr(s1);
	ft_putchar(' ');
	s1 = (mod_tm > x || mod_tm + SIX_MNT_IN_SECS < x) ?
		str + 20 : str + 11;
	s2 = (mod_tm > x || mod_tm + SIX_MNT_IN_SECS < x) ?
		str + 24 : (s2 = str + 16);
	if (mod_tm > x || mod_tm + SIX_MNT_IN_SECS < x)
		ft_putchar(' ');
	*s2 = 0;
	ft_putstr(s1);
	ft_putchar(' ');
}

void			print_l(t_name *file, t_name *local, unsigned int *i)
{
	file_types(file->stats.st_mode);
	ft_printf(" \x1B[31m%*d\x1B[0m", i[0], file->stats.st_nlink);
	if (getpwuid(file->stats.st_uid))
		ft_printf(i[6] ? "\x1B[34m %-s\x1B[0m " : "\x1B[34m %*s \x1B[0m", i[1],
			getpwuid(file->stats.st_uid)->pw_name);
	else
		ft_printf(i[6] ? "%-*s " : "%*s ", i[1], ft_itoa(file->stats.st_uid));
	if (getgrgid(file->stats.st_gid))
		ft_printf(i[6] ? "%-*s " : " %*s ", i[2],
			getgrgid(file->stats.st_gid)->gr_name);
	else
		ft_printf(i[6] ? " %-*s " : " %*s ", i[2], ft_itoa(file->stats.st_uid));
	if (i[6])
	{
		if ((file->stats.st_mode & S_IFMT) == S_IFLNK)
			ft_printf(" %*s ", i[4]);
		else
			ft_printf("  %*d,", i[4], file->stats.st_rdev >> 24);
		ft_printf(" %*d ", i[5], file->stats.st_rdev & 0xFFFFFF);
	}
	else
		ft_printf(" \x1B[34m%*lld\x1B[0m ", i[3], file->stats.st_size);
	ft_time(file->stats.st_mtime);
	ft_lsl(file, local, file->stats.st_mode);
}
