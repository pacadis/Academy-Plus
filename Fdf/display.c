/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 02:50:15 by mflorea           #+#    #+#             */
/*   Updated: 2018/02/10 02:50:16 by mflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_help(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 5, MENU_COLOR, "<Help>");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 20, MENU_COLOR,
			"Exit:   ESC/Q");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 35, MENU_COLOR,
			"Help:   F1");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 50, MENU_COLOR,
			"Rotate: UP RIGHT DOWN LEFT");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 65, MENU_COLOR,
			"Move:   8    6   2   4");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 80,
			MENU_COLOR, "Zoom:   + -");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 95,
			MENU_COLOR, "Height: H J");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 110,
			MENU_COLOR, "Color:  C");
}

void	draw_line(t_point pts, t_draw draw, t_fdf *fdf)
{
	while (1)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, pts.x0, pts.y0,
				fdf->colors[fdf->color_index]);
		if (pts.x0 == pts.x1 && pts.y0 == pts.y1)
			return ;
		draw.e2 = draw.err;
		if (draw.e2 > -draw.dx)
		{
			draw.err -= draw.dy;
			pts.x0 += draw.sx;
		}
		if (draw.e2 < draw.dy)
		{
			draw.err += draw.dx;
			pts.y0 += draw.sy;
		}
	}
}

void	init_draw_var(t_draw *draw, t_point pts)
{
	draw->dx = abs(pts.x1 - pts.x0);
	draw->dy = abs(pts.y1 - pts.y0);
	if (pts.x0 < pts.x1)
		draw->sx = 1;
	else
		draw->sx = -1;
	if (pts.y0 < pts.y1)
		draw->sy = 1;
	else
		draw->sy = -1;
	if (draw->dx > draw->dy)
		draw->err = draw->dx / 2;
	else
		draw->err = -draw->dy / 2;
	draw->e2 = 0;
}
