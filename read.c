/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 21:15:31 by vbaron            #+#    #+#             */
/*   Updated: 2017/02/20 22:44:43 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_object		*ft_obj_spacing(int fd, char *line, int l)
{
	t_object	*obj;

	if (get_next_line_safe(fd, &line) != 1)
		ft_error_l("useless empty line\n", l - 1);
	if (get_next_line_safe(fd, &line) != 1)
		ft_error_l("object without parameters\n", l + 1);
	if (ft_strncmp(line, "{", 1) != 0)
		ft_error_l("open parameters with a '{'\n", l + 1);
	if (!(obj = (t_object *)malloc(sizeof(t_object))))
		ft_error("Malloc error\n");
	return (obj);
}

int				ft_obj_type(char *line, int l)
{
	int			type;

	type = -1;
	if (ft_strncmp(ft_check_syntax(line, "	type = ", l), "sphere", 6) == 0)
		type = 0;
	if (ft_strncmp(ft_check_syntax(line, "	type = ", l), "plan", 4) == 0)
		type = 1;
	if (ft_strncmp(ft_check_syntax(line, "	type = ", l), "cylinder", 8) == 0)
		type = 2;
	if (ft_strncmp(ft_check_syntax(line, "	type = ", l), "cone", 4) == 0)
		type = 3;
	if (type == -1)
		ft_error_l("types : [sphere, plan, cylinder, cone]\n", l);
	return (type);
}

t_object		*ft_obj_rot_r_h(int fd, char *line, t_object *obj, int l)
{
	if (obj->type != 0 && get_next_line_safe(fd, &line) == 1)
	{
		l++;
		obj->rot = ft_read_coo(ft_check_syntax(line, "	rotation = (", l), l);
	}
	else if (obj->type != 0)
		ft_error_l("no rotation\n", l);
	if (obj->type != 1 && get_next_line_safe(fd, &line) == 1)
	{
		l++;
		obj->r = ft_atoi_d(ft_check_syntax(line, "	radius = ", l));
	}
	else if (obj->type != 1)
		ft_error_l("no radius\n", l);
	if (obj->type > 1 && get_next_line_safe(fd, &line) == 1)
	{
		l++;
		obj->h = ft_atoi_d(ft_check_syntax(line, "	height = ", l));
	}
	else if (obj->type > 1)
		ft_error_l("no height\n", l);
	obj->tmp = l;
	return (obj);
}

t_object		*ft_read_obj_param(int fd, char *line)
{
	t_object	*obj;
	static int	l = 4;

	obj = ft_obj_spacing(fd, line, l);
	if (get_next_line_safe(fd, &line) == 1)//que fait gnl appele apres return (0) ?
		obj->type = ft_obj_type(line, l + 2);
	else
		ft_error_l("no type\n", l + 2);
	l += 3;
	if (get_next_line_safe(fd, &line) == 1)
		obj->pos = ft_read_coo(ft_check_syntax(line, "	origin = (", l), l);
	else
		ft_error_l("no origin\n", l);
	obj = ft_obj_rot_r_h(fd, line, obj, l);
	l = obj->tmp + 1;
	if (get_next_line_safe(fd, &line) == 1)
		obj->color = ft_atoi_16(ft_check_syntax(line, "	color = ", l));
	else
		ft_error_l("no color\n", l);
	if (get_next_line_safe(fd, &line) != 1 || ft_strncmp(line, "}", 1) != 0)
		ft_error_l("close parameters with a '}'\n", l + 1);
	l += 3;
	return (obj);
}

t_object		*ft_lstadd_obj(int fd, char *line, t_object *allobj)
{
	int			type;
	t_object	*obj;
	t_object	*tmp;

	obj = ft_read_obj_param(fd, line);
	if (obj)
		obj->next = NULL;
	if (allobj == NULL)
		return (obj);
	tmp = allobj;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = obj;
	return (obj);
}
