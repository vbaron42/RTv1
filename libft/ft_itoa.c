/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 22:12:37 by vbaron            #+#    #+#             */
/*   Updated: 2016/02/09 21:35:37 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int n)
{
	int		l;

	l = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		l++;
	while (n != 0)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

char			*ft_itoa(int n)
{
	size_t	i;
	char	*num;

	i = ft_numlen(n);
	num = (char *)malloc((i + 1) * sizeof(char));
	if (num == NULL)
		return (NULL);
	num[i] = '\0';
	if ((-2147483647 - 1) == n)
		return (ft_strcpy(num, "-2147483648"));
	if (n < 0)
	{
		num[0] = '-';
		n = -n;
	}
	if (n == 0)
		num[0] = '0';
	while (n != 0)
	{
		num[i - 1] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (num);
}
