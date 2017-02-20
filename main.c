/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 20:07:31 by vbaron            #+#    #+#             */
/*   Updated: 2017/02/20 21:54:05 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
/*
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

t_object		*ft_lstadd_obj(int fd, char *line, t_object *allobj)
{
	static int	l = 4;
	int			type;
	t_object	*obj;
	t_object	*tmp;

	
	if (get_next_line_safe(fd, &line) != 1)
		ft_error_l("useless empty line\n", l - 1);
	if (get_next_line_safe(fd, &line) != 1)
		ft_error_l("object without parameters\n", l + 1);
	if (ft_strncmp(line, "{", 1) != 0)
		ft_error_l("open parameters with a '{'\n", l + 1);
	if (!(obj = (t_object *)malloc(sizeof(t_object))))
		ft_error("Malloc error\n");
	if (get_next_line_safe(fd, &line) == 1)//que fait gnl lorsqu il est reappele apres avoir return (0) ?
	{
		l += 2;
		obj->type = -1;
		if (ft_strncmp(ft_check_syntax(line, "	type = ", l), "sphere", 6) == 0)
			obj->type = 0;
		if (ft_strncmp(ft_check_syntax(line, "	type = ", l), "plan", 4) == 0)
			obj->type = 1;
		if (ft_strncmp(ft_check_syntax(line, "	type = ", l), "cylinder", 8) == 0)
			obj->type = 2;
		if (ft_strncmp(ft_check_syntax(line, "	type = ", l), "cone", 4) == 0)
			obj->type = 3;
		if (obj->type == -1)
			ft_error_l("types : [sphere, plan, cylinder, cone]\n", l);
	}
	else
		ft_error_l("no type\n", l);
	l++;
	if (get_next_line_safe(fd, &line) == 1)
		obj->pos = ft_read_coo(ft_check_syntax(line, "	origin = (", l), l);
	else
		ft_error_l("no origin\n", l);
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
	l++;
	if (get_next_line_safe(fd, &line) == 1)
		obj->color = ft_atoi_16(ft_check_syntax(line, "	color = ", l));
	else
		ft_error_l("no color\n", l);
	l++;
	if (get_next_line_safe(fd, &line) != 1 || ft_strncmp(line, "}", 1) != 0)
		ft_error_l("close parameters with a '}'\n", l);
	l += 2;
	//
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
*/
t_object		*get_scene(char *file, t_env *env)
{
	int			fd;
	int			err;
	char		*line;
	t_object	*obj;

	if (!(line = ft_strnew(1)))
		ft_error("Malloc error\n");
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error("This file can't be open\n");
	if (get_next_line_safe(fd, &line) == 1)
		env->name = ft_check_syntax(line, "scene_name = ", 1);
	if (get_next_line_safe(fd, &line) == 1)
		env->cam = ft_read_coo(ft_check_syntax(line, "camera_origin = (", 2), 2);
	else
		ft_error_l("missing camera_origin", 2);
	obj = NULL;
	while (get_next_line_safe(fd, &line) == 1)
		obj = ft_lstadd_obj(fd, line, obj);
	ft_putstr(line);
	close(fd);
	free(line);
	return (obj);
}

void			init_all(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		ft_error("mlx_init() error\n");
	if (!(env->win = mlx_new_window(env->mlx, WIN_LENGHT, WIN_HEIGHT, TITLE)))
		ft_error("mlx_new_window() error\n");
//	control_display();
	env->img = new_img(env);
}

int				main(int argc, char **argv)
{
	t_env		*env;
	double		i;

	if (WIN_LENGHT > 2500 || WIN_HEIGHT > 1500
			|| WIN_LENGHT < 200 || WIN_HEIGHT < 200)
		ft_error("Choose a correct window's size\n");
	if (argc != 2)
		ft_error("Usage : ./rtv1 file\n");
	if (!(env = (t_env*)malloc(sizeof(t_env))))
		ft_error("Malloc error\n");
	env->obj = get_scene(argv[1], env);
	i = 100 / (double)3;
	init_all(env);
	mlx_key_hook(env->win, event, env);
//	mlx_mouse_hook(env->win, mouse_clic, env);
//	mlx_hook(env->win, 6, (1L << 6), &mouse_move, env);
	mlx_expose_hook(env->win, print_img, env);
	mlx_loop(env->mlx);
	return (0);
}
