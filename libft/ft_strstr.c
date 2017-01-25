/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 22:10:34 by vbaron            #+#    #+#             */
/*   Updated: 2015/12/18 01:53:28 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(s2);
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		if (ft_strncmp(&s1[i], s2, l) == 0)
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
