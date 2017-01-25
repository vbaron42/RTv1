/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 06:04:57 by vbaron            #+#    #+#             */
/*   Updated: 2016/11/22 22:00:08 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*first_call(char *str, int fd)
{
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				read_ret;

	str = ft_strnew(1);
	while ((read_ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[read_ret] = '\0';
		tmp = str;
		if (!(str = ft_strjoin(str, buff)))
			return (NULL);
		ft_strdel(&tmp);
	}
	if (read_ret == -1)
		return (NULL);
	return (str);
}

int					get_next_line(int const fd, char **line)
{
	static char		*str[MAXFILE];
	int				i;

	i = 0;
	if (fd < 0 || fd > MAXFILE || line == NULL || BUFF_SIZE < 0
	|| BUFF_SIZE > BUFF_MAX)
		return (-1);
	if (str[fd] == NULL)
	{
		if ((str[fd] = first_call(str[fd], fd)) == NULL)
			return (-1);
	}
	if (str[fd][0] == '\0')
		return (0);
	while (str[fd][i] != '\0' && str[fd][i] != '\n')
		i++;
	*line = ft_strsub(str[fd], 0, i);
	if ((str[fd] = ft_strchr(str[fd], '\n')) == NULL)
		return (1);
	if (str[fd][0] != '\0')
		str[fd] = ft_strsub(str[fd], 1, ft_strlen(str[fd]));
	return (1);
}
