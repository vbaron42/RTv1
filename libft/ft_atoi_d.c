/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 05:42:57 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/25 06:22:36 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double			ft_get_res(const char *str, size_t i, double res, int neg)
{
	size_t		i2;

	if (str[i] == '.')
	{
		i++;
		i2 = 1;
		while (str[i] >= '0' && str[i] <= '9')
		{
			res += (str[i] - '0') / (double)ft_pow(10, i2);
			i++;
			i2++;
		}
	}
	if (neg)
		res = -res;
	return (res);
}

double			ft_atoi_d(const char *str)
{
	double		res;
	size_t		i;
	int			neg;

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
	return (ft_get_res(str, i, res, neg));
}
