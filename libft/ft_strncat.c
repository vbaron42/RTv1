/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 21:04:58 by vbaron            #+#    #+#             */
/*   Updated: 2015/12/18 01:07:00 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int	i;
	int	i2;

	if (n == 0)
		return (dest);
	i = ft_strlen(dest);
	i2 = 0;
	while (src[i2] != '\0' && n > 0)
	{
		dest[i + i2] = src[i2];
		i2++;
		n--;
	}
	dest[i + i2] = '\0';
	return (dest);
}
