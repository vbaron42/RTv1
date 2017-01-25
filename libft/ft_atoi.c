/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 23:47:09 by vbaron            #+#    #+#             */
/*   Updated: 2016/02/09 21:34:11 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	i;
	int		neg;
	long	res;

	i = 0;
	neg = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	if (neg)
		res = -res;
	return (res);
}
