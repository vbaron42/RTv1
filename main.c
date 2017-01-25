/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 20:07:31 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/25 06:22:44 by vbaron           ###   ########.fr       */
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

	if (!(str2 = ft_strsplit(str, ',')))
			ft_error_l("missing coordinates", l);
	coo.x = ft_atoi_d(str2[0]);//tester si il manque des coordonnes
	coo.y = ft_atoi_d(str2[1]);
	coo.z = ft_atoi_d(str2[2]);//free str2 + malloc coo ?
	return (coo);
}

char			*ft_check_syntax(char *line, char *str, int l)
{
	return (line);
}

t_object		*ft_lstadd_obj(int fd, char *line)
{
	static int	l_count = 3;;

}

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
		env->cam = ft_read_coo(ft_check_syntax(line, "camera_origin = ("), 2);
	while (get_next_line_safe(fd, &line) == 1)
	{
		obj = ft_lstadd_obj(fd, line);
	}
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
//	env->obj = get_scene(argv[1], env);
	i = 100 / (double)3;
	ft_putnbr_d(ft_atoi_d("12345.67890"), 3);
	init_all(env);
	mlx_key_hook(env->win, event, env);
//	mlx_mouse_hook(env->win, mouse_clic, env);
//	mlx_hook(env->win, 6, (1L << 6), &mouse_move, env);
	mlx_expose_hook(env->win, print_img, env);
	mlx_loop(env->mlx);
	return (0);
}
