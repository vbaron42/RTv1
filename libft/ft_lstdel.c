/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 21:24:06 by vbaron            #+#    #+#             */
/*   Updated: 2016/02/09 21:24:20 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*in_alst;
	t_list	*nextsave;

	in_alst = *alst;
	while (in_alst != NULL)
	{
		nextsave = in_alst->next;
		ft_lstdelone(&in_alst, del);
		in_alst = nextsave;
	}
	*alst = NULL;
}
