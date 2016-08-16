/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 16:16:24 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/04/05 16:16:26 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	apply_pixel_mandelbrot(char *buf, t_mandelbrot *f)
{
	t_vector_2	v;

	v.x = f->x - f->marge.x;
	v.y = f->y - f->marge.y;
	if (f->color == 0)
		red_shades(buf, v, f->i, f->max_it);
	else if (f->color == 1)
		blue_shades(buf, v, f->i, f->max_it);
	else if (f->color == 2)
		grey_shades(buf, v, f->i, f->max_it);
	else if (f->color == 3)
		rand_shades(buf, v, f->i, f->max_it);
}

void		draw_mandelbrot(char *buf, t_mandelbrot *f)
{
	f->x = f->marge.x;
	f->y = f->marge.y;
	while (f->y < f->image.y - f->marge.y)
	{
		while (f->x < f->image.x - f->marge.x)
		{
			f->c.r = f->x / f->zoom + f->v1.x;
			f->c.i = f->y / f->zoom + f->v1.y;
			f->z.r = 0;
			f->z.i = 0;
			f->i = 0;
			while (((f->z.r * f->z.r + f->z.i * f->z.i) < 4)
				&& (f->i < f->max_it))
			{
				f->tmp = f->z.r;
				f->z.r = f->z.r * f->z.r - f->z.i * f->z.i + f->c.r;
				f->z.i = 2 * f->tmp * f->z.i + f->c.i;
				++f->i;
			}
			apply_pixel_mandelbrot(buf, f);
			++f->x;
		}
		f->x = f->marge.x;
		++f->y;
	}
}
