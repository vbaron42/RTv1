/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 21:25:29 by vbaron            #+#    #+#             */
/*   Updated: 2016/02/09 21:38:43 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlst;

	newlst = (t_list *)malloc(sizeof(t_list));
	if (newlst == NULL)
		return (NULL);
	newlst->next = NULL;
	if (content == NULL)
	{
		newlst->content = NULL;
		newlst->content_size = 0;
		return (newlst);
	}
	newlst->content = (void *)malloc(content_size);
	if (newlst->content == NULL)
	{
		free(newlst);
		return (NULL);
	}
	ft_memcpy(newlst->content, content, content_size);
	newlst->content_size = content_size;
	return (newlst);
}
