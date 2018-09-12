/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 10:25:29 by eonwe             #+#    #+#             */
/*   Updated: 2018/09/10 11:33:15 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define MIN(A, B) (((A) < (B)) ? (A) : (B))
# define MAX(A, B) (((A) > (B)) ? (A) : (B))
# define ABSVAL(A) ((A) < 0 > -(A) : (A))
# define SIX_MNT_IN_SECS 15552000

# define NRM  “\x1B[0m”
# define RED  “\x1B[31m”
# define GRN  “\x1B[32m”
# define YEL  “\x1B[33m”
# define BLU  “\x1B[34m”
# define MAG  “\x1B[35m”
# define CYN  “\x1B[36m”
# define WHT  “\x1B[37m”

# include <unistd.h>
# include <dirent.h>
# include <time.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <sys/xattr.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "./libft/libft.h"

typedef struct		s_ls
{
	unsigned int	a : 1;
	unsigned int	u_r : 1;
	unsigned int	r : 1;
	unsigned int	l : 1;
	unsigned int	t : 1;
}					t_ls;

typedef enum		e_bool
{
	FALSE, TRUE
}					t_bool;

typedef struct		s_name
{
	char			*name;
	struct stat		stats;
}					t_name;

t_bool				can_access(char *name);
void				inval_opt(char x);
void				print_l(t_name *file, t_name *local, unsigned int *i);
void				sort_lst(t_list *start, int (*d)(t_name *, t_name *, int),
		int rev_cmp);
int					ft_sort_alp(t_name *dir1, t_name *dir2, int rev_cmp);
int					ft_comp_lex(t_name *dir1, t_name *dir2, int rev_cmp);
void				ft_blocks(t_list *list);
void				print_dir(t_list *dir, t_list *list, t_ls *opts);
void				pro_args(t_list *list, t_ls *opts, int len);
void				cmp_len_wdth(t_list *list, unsigned int *x);
t_list				*ft_opendir(t_list *local, t_list *list, t_ls *opts);

#endif
