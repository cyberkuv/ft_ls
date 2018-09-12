/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 10:19:13 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 10:58:12 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int begin;
	int len;

	begin = 0;
	if (!s)
		return (NULL);
	while (s[begin] == ' ' || s[begin] == '\t' || s[begin] == '\n')
		begin++;
	if (s[begin] == '\0')
		return (ft_strdup(s + begin));
	len = ft_strlen(s) - 1;
	while ((s[len] == ' ' || s[len] == '\t' || s[len] == '\n') && len > 0)
		len--;
	return (ft_strsub(s, begin, len - begin + 1));
}
