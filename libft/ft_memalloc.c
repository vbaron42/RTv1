/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:55:17 by vbaron            #+#    #+#             */
/*   Updated: 2016/02/09 21:36:07 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*mem;

	mem = (void *)malloc(size * sizeof(void));
	if (mem == NULL)
		return ((void *)mem);
	i = 0;
	while (i < size)
	{
		mem[i] = 0;
		i++;
	}
	return ((void *)mem);
}
