/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mandelbar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 12:35:27 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/04/05 12:35:29 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mouse_hook_mandelbar(int button, int x, int y, t_mandelbar *f)
{
	if (button == MOUSE_UP || button == MOUSE_LEFT)
	{
		f->zoom += 100;
		f->image.x = 2.7 * f->zoom;
		f->image.y = 2.4 * f->zoom;
	}
	else if (button == MOUSE_DOWN)
	{
		f->zoom -= 100;
		if (f->zoom < 100)
			f->zoom = 100;
		f->image.x = 2.7 * f->zoom;
		f->image.y = 2.4 * f->zoom;
	}
	f->marge.x = f->image.x / 2 - (float)WIDTH / 2;
	f->marge.y = f->image.y / 2 - (float)HEIGHT / 2;
	(void)x;
	(void)y;
}

void	motion_hook_mandelbar(int x, int y, t_mandelbar *f)
{
	float	new_iteration;

	new_iteration = 1 / (float)WIDTH * (float)x * ITERATIONS;
	if (new_iteration > ITERATIONS)
		new_iteration = ITERATIONS;
	else if (new_iteration < 0)
		new_iteration = 0;
	f->max_it = new_iteration;
	(void)y;
}

void	key_hook_mandelbar(int k, t_mandelbar *mandelbar)
{
	if (k == PAD_1)
	{
		++mandelbar->color;
		if (mandelbar->color > 3)
			mandelbar->color = 0;
	}
}
