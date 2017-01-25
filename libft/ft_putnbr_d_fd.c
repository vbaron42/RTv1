/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_d_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 05:12:36 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/25 05:12:59 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_dec_count(int dec)
{
	if (dec == 0)
		dec = 1000000;
	else if (dec > -10000)
		dec = -dec - 1;
	else
		dec = -dec;
	return (dec);
}

void			ft_putnbr_d_fd(long double nb, int dec, int fd)
{
	char		c;
	long int	n;

	if (dec > 0)
	{
		if (dec >= 10)
			dec = 9;
		n = nb * ft_pow(10, dec);
		dec--;
	}
	else if ((n = nb) != -123453526)
		dec = ft_dec_count(dec);
	if (0 > n)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_d_fd(n / 10, -dec, fd);
	c = (n % 10) + '0';
	if (dec == 0)
		ft_putchar('.');
	write(fd, &c, 1);
}
