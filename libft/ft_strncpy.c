/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:51:22 by vbaron            #+#    #+#             */
/*   Updated: 2015/12/15 06:45:42 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (src[i] != '\0')
			dst[i] = src[i];
		else
		{
			while (i < n)
			{
				dst[i] = '\0';
				i++;
			}
		}
		i++;
	}
	return (dst);
}
