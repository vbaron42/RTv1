/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 21:25:11 by vbaron            #+#    #+#             */
/*   Updated: 2016/02/09 21:25:14 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lstnext;
	t_list	*lstnew;
	t_list	*result;

	if (lst == NULL)
		return (NULL);
	lstnew = f(lst);
	lstnext = ft_lstnew(lstnew->content, lstnew->content_size);
	result = lstnext;
	lst = lst->next;
	while (lst != NULL)
	{
		lstnew = f(lst);
		lstnew = ft_lstnew(lstnew->content, lstnew->content_size);
		lstnext->next = lstnew;
		lst = lst->next;
		lstnext = lstnext->next;
	}
	return (result);
}
