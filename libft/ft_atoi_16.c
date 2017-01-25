/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_16.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 01:21:06 by vbaron            #+#    #+#             */
/*   Updated: 2016/11/15 01:27:33 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_16(const char *str)
{
	size_t	i;
	long	res;

	i = 0;
	res = 0x0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '0' || str[i + 1] != 'x')
	{
		if (str[i + 1] == '\0')
			return (0);
		i++;
	}
	if (str[i + 1] == '\0')
		return (0);
	i = i + 2;
	while ((str[i] <= 'F' && str[i] >= 'A') || (str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] <= '9')
			res = (res * 16) + str[i] - '0';
		else
			res = (res * 16) + str[i] - 'A' + 10;
		i++;
	}
	return (res);
}
