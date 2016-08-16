/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 15:19:08 by pdelobbe          #+#    #+#             */
/*   Updated: 2015/05/22 17:29:26 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	usage(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "mandelbrot") == 0)
			return (MANDELBROT);
		else if (ft_strcmp(argv[1], "julia") == 0)
			return (JULIA);
		else if (ft_strcmp(argv[1], "mandelbar") == 0)
			return (MANDELBAR);
	}
	ft_putendl("----------------------------------------");
	ft_putstr("usage : ");
	ft_putstr(argv[0]);
	ft_putendl(" <name>");
	ft_putendl("available names : mandelbrot, julia, mandelbar");
	ft_putendl("----------------------------------------");
	return (0);
}

int			main(int argc, char *argv[])
{
	t_env	e;
	int		fractal;

	fractal = usage(argc, argv);
	if (!fractal)
		return (-1);
	init(&e, fractal);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_hook(e.win, 6, 1L << 6, motion_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
