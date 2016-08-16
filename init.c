/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:22:50 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/02/16 12:22:51 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_mandelbar(t_mandelbar *f)
{
	f->v1.x = -2.1;
	f->v2.x = 0.6;
	f->v1.y = -1.2;
	f->v2.y = 1.2;
	f->max_it = ITERATIONS;
	f->zoom = ZOOM * 100;
	f->image.x = 2.7 * f->zoom;
	f->image.y = 2.4 * f->zoom;
	f->marge.x = f->image.x / 2 - (float)WIDTH / 2;
	f->marge.y = f->image.y / 2 - (float)HEIGHT / 2;
	f->color = 0;
}

static void	init_julia(t_julia *f)
{
	f->c.r = 0.285;
	f->c.i = 0.01;
	f->v1.x = -1;
	f->v2.x = 1;
	f->v1.y = -1.2;
	f->v2.y = 1.2;
	f->max_it = ITERATIONS;
	f->zoom = ZOOM * 100;
	f->image.x = 2 * f->zoom;
	f->image.y = 2.4 * f->zoom;
	f->marge.x = f->image.x / 2 - (float)WIDTH / 2;
	f->marge.y = f->image.y / 2 - (float)HEIGHT / 2;
	f->color = 0;
}

static void	init_mandelbrot(t_mandelbrot *f)
{
	f->v1.x = -2.1;
	f->v2.x = 0.6;
	f->v1.y = -1.2;
	f->v2.y = 1.2;
	f->max_it = ITERATIONS;
	f->zoom = ZOOM * 100;
	f->image.x = 2.7 * f->zoom;
	f->image.y = 2.4 * f->zoom;
	f->marge.x = f->image.x / 2 - (float)WIDTH / 2;
	f->marge.y = f->image.y / 2 - (float)HEIGHT / 2;
	f->color = 0;
}

void		init(t_env *e, int fractal)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "FractOl");
	e->img = malloc(sizeof(t_img));
	e->img->data = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->fractal = fractal;
	e->mandelbrot = malloc(sizeof(t_mandelbrot));
	init_mandelbrot(e->mandelbrot);
	e->julia = malloc(sizeof(t_julia));
	init_julia(e->julia);
	e->mandelbar = malloc(sizeof(t_mandelbar));
	init_mandelbar(e->mandelbar);
}
