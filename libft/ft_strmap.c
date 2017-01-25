/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 02:47:47 by vbaron            #+#    #+#             */
/*   Updated: 2015/12/15 09:21:32 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len > i)
	{
		str[i] = (*f)(s[i]);
		i++;
	}
	return (str);
}
