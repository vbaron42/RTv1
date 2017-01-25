/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 03:01:51 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/24 20:08:02 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			octant_put_pixel(int cx, int cy, t_circle cir, t_env *env)
{
	int			c;

	c = color_scale(env->vision->c, env->vision->pattern);
	img_put_pixel(env, cx + cir.x, cy + cir.y, c);
	img_put_pixel(env, cx - cir.x, cy + cir.y, c);
	img_put_pixel(env, cx + cir.x, cy - cir.y, c);
	img_put_pixel(env, cx - cir.x, cy - cir.y, c);
	img_put_pixel(env, cx + cir.y, cy + cir.x, c);
	img_put_pixel(env, cx - cir.y, cy + cir.x, c);
	img_put_pixel(env, cx + cir.y, cy - cir.x, c);
	img_put_pixel(env, cx - cir.y, cy - cir.x, c);
}

t_circle		circle_roundness(t_circle cir)
{
	if (cir.d >= (2 * cir.x))
	{
		cir.d = (cir.d - (2 * cir.x) - 1);
		cir.x++;
	}
	else if (cir.d < (2 * (cir.rt - cir.y)))
	{
		cir.d = (cir.d + (2 * cir.y) - 1);
		cir.y--;
	}
	else
	{
		cir.d = (cir.d + 2 * (cir.y - cir.x - 1));
		cir.y--;
		cir.x++;
	}
	return (cir);
}

void			draw_circle(int cx, int cy, t_circle cir, t_env *env)
{
	cir.rt = cir.r - cir.thick;
	while (cir.rt++ != cir.r + cir.thick - 1)
	{
		env->vision->c += 4;
		cir.x = 0;
		cir.y = cir.rt;
		cir.d = cir.rt - 1;
		while (cir.y >= cir.x)
		{
			octant_put_pixel(cx, cy, cir, env);
			cir = circle_roundness(cir);
		}
	}
	env->vision->c -= (8 * cir.thick) - 4;
}

void			draw_square(int cx, int cy, int size, t_env *env)
{
	int			x;
	int			y;
	int			x_end;
	int			y_end;

	if (size >= 1)
	{
		size /= 2;
		y = cy - size - 1;
		x_end = cx + size;
		y_end = cy + size;
		while (y++ <= y_end)
		{
			x = cx - size - 1;
			while (x++ <= x_end)
				img_put_pixel(env, x, y, 0x0);
		}
	}
}
