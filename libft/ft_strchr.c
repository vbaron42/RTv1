/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 21:28:24 by vbaron            #+#    #+#             */
/*   Updated: 2016/11/06 16:10:29 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	if (*(src + ft_strlen(src)) == (char)c)
		return ((char*)src + ft_strlen(src));
	return ((char*)ft_memchr(src, c, ft_strlen(src)));
}
