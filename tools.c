/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 21:51:47 by vbaron            #+#    #+#             */
/*   Updated: 2017/02/20 21:53:14 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				get_next_line_safe(int fd, char **line)
{
	int			err;

	if ((err = get_next_line(fd, line)) == -1)
		ft_error("This file can't be read\n");
	return (err);
}

t_coo			ft_read_coo(char *str, int l)
{
	char		**str2;
	t_coo		coo;
	int			i;

	if (!(str2 = ft_strsplit(str, ',')))
		ft_error_l("missing coordinates\n", l);
	if ((!(str2[0])) || (!(str2[1])) || (!(str2[2])))
		ft_error_l("missing 1 or 2 coordinates\n", l);
	coo.x = ft_atoi_d(str2[0]);
	coo.y = ft_atoi_d(str2[1]);
	coo.z = ft_atoi_d(str2[2]);//malloc coo ?
	i = 0;
	while (str2[i] != NULL)
	{
		free(str2[i]);
		i++;
	}
	free(str2[i]);
	return (coo);
}

char			*ft_check_syntax(char *line, char *str, int l)
{
	if (ft_strncmp(line, str, ft_strlen(str)) != 0)
		ft_error_l("bad syntax or wrong parameter\n", l);
	return (ft_strsub(line, ft_strlen(str), ft_strlen(line)));//free ?
}
