/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_more_opt.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 23:24:30 by vbaron            #+#    #+#             */
/*   Updated: 2016/11/16 23:51:52 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_substr_len(const char *str, char d, char e, char f)
{
	int		count;

	count = 0;
	while (*str != d && *str != e && *str != f && *str++ != '\0')
		count++;
	return (count);
}

static int		ft_get_nb_lines(const char *str, char d, char e, char f)
{
	int		count;
	int		is_word;

	count = 0;
	is_word = 0;
	while (*str != '\0')
	{
		if (is_word && (*str == d || *str == e || *str == f))
			is_word = 0;
		if (!is_word && *str != d && *str != e && *str != f)
		{
			is_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

char			**ft_strsplit_mo(const char *s, char d, char e, char f)
{
	char	**wtab;
	int		i;
	int		nb_lines;

	if (!s)
		return (NULL);
	i = 0;
	nb_lines = ft_get_nb_lines(s, d, e, f);
	if (!(wtab = (char**)malloc(sizeof(char*) * (nb_lines + 1))))
		return (NULL);
	while (i < nb_lines)
	{
		while (*s == d || *s == e || *s == f)
			s++;
		if (!(wtab[i] = ft_strsub(s, 0, ft_substr_len(s, d, e, f))))
			return (NULL);
		s += ft_substr_len(s, d, e, f);
		i++;
	}
	wtab[i] = NULL;
	return (wtab);
}
