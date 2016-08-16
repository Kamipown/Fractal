/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 14:47:49 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/02/15 14:47:53 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_env *e)
{
	draw_img(e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (e->fractal == MANDELBROT)
		mouse_hook_mandelbrot(button, x, y, e->mandelbrot);
	if (e->fractal == JULIA)
		mouse_hook_julia(button, x, y, e->julia);
	if (e->fractal == MANDELBAR)
		mouse_hook_mandelbar(button, x, y, e->mandelbar);
	expose_hook(e);
	return (0);
}

int		motion_hook(int x, int y, t_env *e)
{
	if (e->fractal == MANDELBROT)
		motion_hook_mandelbrot(x, y, e->mandelbrot);
	if (e->fractal == JULIA)
		motion_hook_julia(x, y, e->julia);
	if (e->fractal == MANDELBAR)
		motion_hook_mandelbar(x, y, e->mandelbar);
	expose_hook(e);
	return (0);
}

int		key_hook(int k, t_env *e)
{
	if (k == PAD_0)
	{
		++e->fractal;
		if (e->fractal > MANDELBAR)
			e->fractal = MANDELBROT;
		expose_hook(e);
	}
	else if (k == PAD_1)
	{
		if (e->fractal == MANDELBROT)
			key_hook_mandelbrot(k, e->mandelbrot);
		else if (e->fractal == JULIA)
			key_hook_julia(k, e->julia);
		else if (e->fractal == MANDELBAR)
			key_hook_mandelbar(k, e->mandelbar);
		expose_hook(e);
	}
	else if (k == ESCAPE)
		exit(0);
	return (0);
}
