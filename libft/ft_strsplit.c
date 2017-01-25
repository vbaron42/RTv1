/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:16:58 by vbaron            #+#    #+#             */
/*   Updated: 2016/11/08 18:36:25 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_substr_len(const char *str, char delim)
{
	int		count;

	count = 0;
	while (*str != delim && *str++ != '\0')
		count++;
	return (count);
}

static int		ft_get_nb_lines(const char *str, char delim)
{
	int		count;
	int		is_word;

	count = 0;
	is_word = 0;
	while (*str != '\0')
	{
		if (is_word && *str == delim)
			is_word = 0;
		if (!is_word && *str != delim)
		{
			is_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

char			**ft_strsplit(const char *s, char d)
{
	char	**wtab;
	int		i;
	int		nb_lines;

	if (!s)
		return (NULL);
	i = 0;
	nb_lines = ft_get_nb_lines(s, d);
	if (!(wtab = (char**)malloc(sizeof(char*) * (nb_lines + 1))))
		return (NULL);
	while (i < nb_lines)
	{
		while (*s == d)
			s++;
		if (!(wtab[i] = ft_strsub(s, 0, ft_substr_len(s, d))))
			return (NULL);
		s += ft_substr_len(s, d);
		i++;
	}
	wtab[i] = NULL;
	return (wtab);
}
