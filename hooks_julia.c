/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 10:23:57 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/04/05 10:23:59 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mouse_hook_julia(int button, int x, int y, t_julia *f)
{
	if (button == MOUSE_UP || button == MOUSE_LEFT)
	{
		f->zoom += 100;
		f->image.x = 2 * f->zoom;
		f->image.y = 2.4 * f->zoom;
	}
	else if (button == MOUSE_DOWN)
	{
		f->zoom -= 100;
		if (f->zoom < 100)
			f->zoom = 100;
		f->image.x = 2 * f->zoom;
		f->image.y = 2.4 * f->zoom;
	}
	f->marge.x = f->image.x / 2 - (float)WIDTH / 2;
	f->marge.y = f->image.y / 2 - (float)HEIGHT / 2;
	(void)x;
	(void)y;
}

void	motion_hook_julia(int x, int y, t_julia *f)
{
	float	new_cr;
	float	new_ci;

	new_cr = (1 / (float)WIDTH * (float)x * 4) - 2;
	new_ci = (1 / (float)HEIGHT * (float)y * 4) - 2;
	f->c.r = new_cr;
	f->c.i = new_ci;
}

void	key_hook_julia(int k, t_julia *julia)
{
	if (k == PAD_1)
	{
		++julia->color;
		if (julia->color > 3)
			julia->color = 0;
	}
}
