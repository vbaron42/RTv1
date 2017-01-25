/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 03:25:00 by vbaron            #+#    #+#             */
/*   Updated: 2015/12/15 08:43:24 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	size_t		end;
	size_t		start;

	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	end = ft_strlen(s);
	while (s[end - 1] == ' ' || s[end - 1] == '\n' || s[end - 1] == '\t')
	{
		if (end == 1)
			return (ft_strsub(s, 0, 0));
		end--;
	}
	if (start == 0 && end == 0)
		return ((char *)s);
	return (ft_strsub(s, start, end - start));
}
