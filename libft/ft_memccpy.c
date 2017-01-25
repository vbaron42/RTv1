/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:50:28 by vbaron            #+#    #+#             */
/*   Updated: 2016/02/09 21:41:19 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	while (n--)
	{
		*ptr1 = *ptr2;
		if (*ptr2 == (unsigned char)c)
			return ((void *)(ptr1 + 1));
		ptr1++;
		ptr2++;
	}
	return (NULL);
}
