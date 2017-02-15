/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 19:52:06 by vbaron            #+#    #+#             */
/*   Updated: 2017/02/08 19:06:51 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		img_put_pixel(t_env *env, int x, int y, int c)
{
	int		pxl;

	if (y < WIN_HEIGHT && x < WIN_LENGHT && y > 0 && x > 0)
	{
		pxl = y * env->img->line_size + (env->img->bpp / 8) * x;
		env->img->pxl_byt[pxl] = c;
		env->img->pxl_byt[++pxl] = c >> 8;
		env->img->pxl_byt[++pxl] = c >> 16;
	}
}

void		draw_img(t_env *env)
{
}

void		string_display(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 48, 22, 0x0, env->name);
	mlx_string_put(env->mlx, env->win, 50, 20, 0xFF6FFF, env->name);
}

t_img		*new_img(t_env *env)
{
	t_img	*img;

	if (!(img = (t_img*)malloc(sizeof(t_img))))
		ft_error("Malloc error\n");
	if (!(img->ptr = mlx_new_image(env->mlx, WIN_LENGHT, WIN_HEIGHT)))
		ft_error("mlx_new_image() error\n");
	if (!(img->pxl_byt = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->line_size, &img->endian)))
		ft_error("mlx_get_data_addr() error\n");
	return (img);
}

int			print_img(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img->ptr);
	env->img = new_img(env);
	draw_img(env);
	mlx_clear_window(env->mlx, env->win);
	mlx_put_image_to_window(env->mlx, env->win, env->img->ptr, 0, 0);
	string_display(env);
	return (1);
}
