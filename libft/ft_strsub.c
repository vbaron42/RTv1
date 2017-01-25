/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 03:15:31 by vbaron            #+#    #+#             */
/*   Updated: 2016/11/06 16:14:19 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (!s)
		return (NULL);
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (start--)
		s++;
	ret = (char*)ft_memcpy(ret, s, len);
	*(ret + len) = '\0';
	return (ret);
}
