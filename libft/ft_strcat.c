/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:25:32 by vbaron            #+#    #+#             */
/*   Updated: 2015/11/27 00:39:31 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	i2;

	i = ft_strlen(dest);
	i2 = 0;
	while (src[i2] != '\0')
	{
		dest[i] = src[i2];
		i++;
		i2++;
	}
	dest[i] = src[i2];
	return (dest);
}
