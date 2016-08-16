/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 14:24:05 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/04/05 14:24:07 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	red_shades(char *buf, t_vector_2 v, float i, float max_it)
{
	if (i == max_it)
		draw_pixel(buf, v.x, v.y, 0x0F0000);
	else if (i > max_it * 0.9)
		draw_pixel(buf, v.x, v.y, 0x210303);
	else if (i > max_it * 0.8)
		draw_pixel(buf, v.x, v.y, 0x300808);
	else if (i > max_it * 0.7)
		draw_pixel(buf, v.x, v.y, 0x3F0B0B);
	else if (i > max_it * 0.6)
		draw_pixel(buf, v.x, v.y, 0x511414);
	else if (i > max_it * 0.5)
		draw_pixel(buf, v.x, v.y, 0x601F1F);
	else if (i > max_it * 0.4)
		draw_pixel(buf, v.x, v.y, 0x702B2B);
	else if (i > max_it * 0.3)
		draw_pixel(buf, v.x, v.y, 0x823B3B);
	else if (i > max_it * 0.2)
		draw_pixel(buf, v.x, v.y, 0x914D4D);
	else if (i > max_it * 0.1)
		draw_pixel(buf, v.x, v.y, 0xA35D5D);
	else
		draw_pixel(buf, v.x, v.y, 0xB27070);
}

void	blue_shades(char *buf, t_vector_2 v, float i, float max_it)
{
	if (i == max_it)
		draw_pixel(buf, v.x, v.y, 0x000A0F);
	else if (i > max_it * 0.9)
		draw_pixel(buf, v.x, v.y, 0x031721);
	else if (i > max_it * 0.8)
		draw_pixel(buf, v.x, v.y, 0x082330);
	else if (i > max_it * 0.7)
		draw_pixel(buf, v.x, v.y, 0x0B2E3F);
	else if (i > max_it * 0.6)
		draw_pixel(buf, v.x, v.y, 0x143D51);
	else if (i > max_it * 0.5)
		draw_pixel(buf, v.x, v.y, 0x1F4B60);
	else if (i > max_it * 0.4)
		draw_pixel(buf, v.x, v.y, 0x2B5970);
	else if (i > max_it * 0.3)
		draw_pixel(buf, v.x, v.y, 0x3B6A82);
	else if (i > max_it * 0.2)
		draw_pixel(buf, v.x, v.y, 0x4D7A91);
	else if (i > max_it * 0.1)
		draw_pixel(buf, v.x, v.y, 0x5D8BA3);
	else
		draw_pixel(buf, v.x, v.y, 0x709CB2);
}

void	grey_shades(char *buf, t_vector_2 v, float i, float max_it)
{
	if (i == max_it)
		draw_pixel(buf, v.x, v.y, 0x000000);
	else if (i > max_it * 0.9)
		draw_pixel(buf, v.x, v.y, 0x111111);
	else if (i > max_it * 0.8)
		draw_pixel(buf, v.x, v.y, 0x222222);
	else if (i > max_it * 0.7)
		draw_pixel(buf, v.x, v.y, 0x333333);
	else if (i > max_it * 0.6)
		draw_pixel(buf, v.x, v.y, 0x444444);
	else if (i > max_it * 0.5)
		draw_pixel(buf, v.x, v.y, 0x555555);
	else if (i > max_it * 0.4)
		draw_pixel(buf, v.x, v.y, 0x666666);
	else if (i > max_it * 0.3)
		draw_pixel(buf, v.x, v.y, 0x777777);
	else if (i > max_it * 0.2)
		draw_pixel(buf, v.x, v.y, 0x888888);
	else if (i > max_it * 0.1)
		draw_pixel(buf, v.x, v.y, 0x999999);
	else
		draw_pixel(buf, v.x, v.y, 0xAAAAAA);
}

void	rand_shades(char *buf, t_vector_2 v, float i, float max_it)
{
	if (i == max_it)
		draw_pixel(buf, v.x, v.y, 0x052C49);
	else if (i > max_it * 0.9)
		draw_pixel(buf, v.x, v.y, 0x03663E);
	else if (i > max_it * 0.8)
		draw_pixel(buf, v.x, v.y, 0x248406);
	else if (i > max_it * 0.7)
		draw_pixel(buf, v.x, v.y, 0xA0960C);
	else if (i > max_it * 0.6)
		draw_pixel(buf, v.x, v.y, 0xBC2210);
	else if (i > max_it * 0.5)
		draw_pixel(buf, v.x, v.y, 0xDBA718);
	else if (i > max_it * 0.4)
		draw_pixel(buf, v.x, v.y, 0x7DF720);
	else if (i > max_it * 0.3)
		draw_pixel(buf, v.x, v.y, 0x37FC86);
	else if (i > max_it * 0.2)
		draw_pixel(buf, v.x, v.y, 0x54D7FF);
	else if (i > max_it * 0.1)
		draw_pixel(buf, v.x, v.y, 0x7E75FF);
	else
		draw_pixel(buf, v.x, v.y, 0xF493FF);
}
