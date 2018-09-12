/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:39:25 by eonwe             #+#    #+#             */
/*   Updated: 2018/08/25 11:05:43 by eonwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *nlst;

	if (lst && f)
	{
		nlst = f(lst);
		if (nlst && lst->next)
			nlst->next = ft_lstmap(lst->next, f);
		return (nlst);
	}
	return (NULL);
}
