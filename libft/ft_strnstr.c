/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 23:02:42 by vbaron            #+#    #+#             */
/*   Updated: 2016/02/09 21:48:06 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	l;

	i = 0;
	if (ft_strlen(s2) < n)
		l = ft_strlen(s2);
	else if (!(*s2))
		return ((char *)s1);
	else if (!(*s1))
		return (NULL);
	else
		l = n;
	if (l < ft_strlen(s2))
		return (NULL);
	n++;
	while (s1[i] != '\0' && i + l < n)
	{
		if (ft_strncmp(&s1[i], s2, l) == 0)
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
