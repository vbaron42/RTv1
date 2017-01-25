/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:52:33 by vbaron            #+#    #+#             */
/*   Updated: 2016/02/09 21:41:39 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)malloc(sizeof(unsigned char *) * len);
	ft_memcpy(str, src, len);
	ft_memcpy(dest, str, len);
	free(str);
	return (void *)(dest);
}
