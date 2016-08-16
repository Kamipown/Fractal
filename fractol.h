/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 15:19:51 by pdelobbe          #+#    #+#             */
/*   Updated: 2015/05/06 18:05:41 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>

# include "libft/includes/libft.h"

# define WIDTH 1080
# define HEIGHT 960

# define ESCAPE 53

# define PAD_0 82
# define PAD_1 83
# define PAD_2 84
# define PAD_3 85
# define PAD_4 86
# define PAD_5 87
# define PAD_6 88
# define PAD_7 89
# define PAD_8 91
# define PAD_9 92

# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define MOUSE_DOWN 4
# define MOUSE_UP 5

# define MANDELBROT 1
# define JULIA 2
# define MANDELBAR 3

# define ITERATIONS 50
# define ZOOM 3

typedef struct		s_complex
{
	float			r;
	float			i;
}					t_complex;

typedef struct		s_vector_2
{
	float			x;
	float			y;
}					t_vector_2;

typedef struct		s_mandelbar
{
	t_vector_2		v1;
	t_vector_2		v2;
	t_vector_2		image;
	t_vector_2		marge;
	float			max_it;
	float			zoom;
	int				color;
	t_complex		c;
	t_complex		z;
	float			x;
	float			y;
	float			tmp;
	float			i;
}					t_mandelbar;

typedef struct		s_julia
{
	t_complex		c;
	t_complex		z;
	t_vector_2		v1;
	t_vector_2		v2;
	t_vector_2		image;
	t_vector_2		marge;
	float			max_it;
	float			zoom;
	int				color;
	float			x;
	float			y;
	float			tmp;
	float			i;
}					t_julia;

typedef struct		s_mandelbrot
{
	t_vector_2		v1;
	t_vector_2		v2;
	t_vector_2		image;
	t_vector_2		marge;
	float			max_it;
	float			zoom;
	int				color;
	t_complex		c;
	t_complex		z;
	float			x;
	float			y;
	float			tmp;
	float			i;
}					t_mandelbrot;

typedef struct		s_img
{
	void			*data;
	int				bpp;
	int				size;
	int				endian;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_mandelbrot	*mandelbrot;
	t_julia			*julia;
	t_mandelbar		*mandelbar;
	int				fractal;
}					t_env;

void				init(t_env *e, int fractal);

int					expose_hook(t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);
int					motion_hook(int x, int y, t_env *e);
int					key_hook(int k, t_env *e);

void				mouse_hook_mandelbrot(int button, int x, int y,
											t_mandelbrot *f);
void				mouse_hook_julia(int button, int x, int y, t_julia *f);
void				mouse_hook_mandelbar(int button, int x, int y,
											t_mandelbar *f);

void				motion_hook_mandelbrot(int x, int y, t_mandelbrot *f);
void				motion_hook_julia(int x, int y, t_julia *f);
void				motion_hook_mandelbar(int x, int y, t_mandelbar *f);

void				key_hook_mandelbrot(int k, t_mandelbrot *mandelbrot);
void				key_hook_julia(int k, t_julia *julia);
void				key_hook_mandelbar(int k, t_mandelbar *mandelbar);

void				draw_pixel(char *buf, int x, int y, int color);
void				draw_img(t_env *e);

void				draw_mandelbrot(char *buf, t_mandelbrot *f);
void				draw_julia(char *buf, t_julia *f);
void				draw_mandelbar(char *buf, t_mandelbar *f);

void				apply_pixel(char *buf, t_env *e);
void				red_shades(char *buf, t_vector_2 v, float i,
								float max_it);
void				blue_shades(char *buf, t_vector_2 v, float i,
								float max_it);
void				grey_shades(char *buf, t_vector_2 v, float i,
								float max_it);
void				rand_shades(char *buf, t_vector_2 v, float i,
								float max_it);

#endif
