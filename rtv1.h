/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 19:55:49 by vbaron            #+#    #+#             */
/*   Updated: 2017/02/15 17:18:44 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "libft/libft.h"

# define TITLE "RTv1"
# define WIN_LENGHT 800
# define WIN_HEIGHT 600

typedef struct		s_coo
{
	double			x;
	double			y;
	double			z;
}					t_coo;

typedef struct		s_object
{
	int				type;
	t_coo			pos;
	t_coo			rot;
	int				r;
	int				h;
	int				color;
	void			*next;
}					t_object;

typedef struct		s_img
{
	void			*ptr;
	int				bpp;
	int				line_size;
	int				endian;
	char			*pxl_byt;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			*img;
	char			*name;
	t_coo			cam;
	t_object		*obj;
}					t_env;

void				img_put_pixel(t_env *env, int x, int y, int c);
//int					mouse_move(int x, int y, t_env *env);
//int					mouse_clic(int button, int x, int y, t_env *env);
int					event(int code, t_env *env);
t_img				*new_img(t_env *env);
int					print_img(t_env *env);
#endif
