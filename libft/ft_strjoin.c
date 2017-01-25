/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:16:06 by vbaron            #+#    #+#             */
/*   Updated: 2016/11/06 16:12:55 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((ret = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	ft_strcpy(ret, s1);
	*(ret + ft_strlen(s1)) = '\0';
	ft_strcat(ret, s2);
	*(ret + len) = '\0';
	return (ret);
}
