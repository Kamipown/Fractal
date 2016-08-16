/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 16:08:35 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/04/05 16:08:39 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_pixel(char *buf, int x, int y, int color)
{
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		x *= 4;
		y *= 4;
		buf[(x++) + (y * WIDTH)] = color << 24 >> 24;
		buf[(x++) + (y * WIDTH)] = color << 16 >> 16;
		buf[(x) + (y * WIDTH)] = color >> 16;
	}
}

void		draw_img(t_env *e)
{
	char *buf;

	buf = mlx_get_data_addr(
		e->img->data,
		&e->img->bpp,
		&e->img->size,
		&e->img->endian);
	if (e->fractal == MANDELBROT)
		draw_mandelbrot(buf, e->mandelbrot);
	else if (e->fractal == JULIA)
		draw_julia(buf, e->julia);
	else if (e->fractal == MANDELBAR)
		draw_mandelbar(buf, e->mandelbar);
	mlx_put_image_to_window(e->mlx, e->win, e->img->data, 0, 0);
}
