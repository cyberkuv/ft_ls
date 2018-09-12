/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 09:11:53 by eonwe             #+#    #+#             */
/*   Updated: 2018/09/08 09:45:18 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define NRM  “\x1B[0m”
# define RED  “\x1B[31m”
# define GRN  “\x1B[32m”
# define YEL  “\x1B[33m”
# define BLU  “\x1B[34m”
# define MAG  “\x1B[35m”
# define CYN  “\x1B[36m”
# define WHT  “\x1B[37m”

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_print
{
	char			sign;
	char			*mod;
	char			pre;
	char			flgs;
	char			type;
	char			*width;
	char			*precision;
}					t_print;

int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isupper(int c);
int					ft_toupper(int c);
char				*ft_strupper(char *str);
int					ft_tolower(int c);
char				*ft_strlower(char *str);
int					ft_islower(int c);
int					ft_atoi(const char *str);
size_t				ft_strlen(const char *s);
size_t				ft_nbrlen(int nbr);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strdup(const char *s1);
char				*ft_strrev(char *str);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *stack, const char *sub);
char				*ft_strnstr(const char *stack, const char *sub, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				ft_bzero(void *s, size_t n);
void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
int					ft_wdsort(char const *s, char c);
char				*ft_itoa(int n);
void				ft_lstswap(t_list *l1, t_list *l2);
t_list				*ft_lstnew(void const *content, size_t content_size);
int					ft_lstsize(t_list *begin_list);
void				ft_lstfree(void *list, size_t lst_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstjoin(t_list **list, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_strnlen(const char *s, size_t maxlen);
char				*ft_itoa_base(int value, int base);

int					ft_printf(const char *format, ...);
void				ft_mod(t_print *fmt, char *str, int *x);
int					is_unsigned(char str);
int					is_dioux(char type);
int					is_str(char type);
int					is_flg(char c);
int					ft_fmt(va_list lst, const char *src, int *x);
int					ft_type(t_print *fmt, va_list lst, char str);
char				*add_width(t_print fmt, wchar_t *type, int *width);
int					ft_wstrlen(wchar_t *str);
int					write_nbr(t_print fmt, long long nbr);
char				*ft_lltoa(long long n);
char				*ft_ulltoa(unsigned long long n);
char				*ft_lltoah(unsigned long long nbr, int size);
char				*ft_lltoao(unsigned long long nbr);
char				*ft_base(uint64_t nbr, int (*val)(uint64_t *nbr));
int					no_print(t_print fmt, char *word);
char				*fill_zero(t_print fmt, char *type, int width);
int					ft_sizewchr(long x);
int					ft_wstrlen(wchar_t *str);
void				ft_putwchar(wchar_t c);
int					ft_sizebyte(uint64_t nbr);
void				ft_putnstr(char *str, int len);
int					ft_wnstrlen(wchar_t *str, int len);
void				ft_wp(t_print *fmt, va_list lst, char *str, int *i);
t_print				*format_init(void);
void				free_format(t_print *fmt);
int					ft_sc(t_print fmt, va_list lst, char str);
void				ft_putnwstr(wchar_t *str, int len);
void				ft_putwstr(wchar_t *str);

#endif
