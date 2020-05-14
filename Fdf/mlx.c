/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 02:50:32 by mflorea           #+#    #+#             */
/*   Updated: 2018/02/10 02:50:33 by mflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_and_draw(t_fdf *fdf, int i, int j)
{
	t_point		pts;
	t_draw		draw;

	if (j < fdf->map->width - 1)
	{
		pts.x0 = fdf->map->c_sys[i][j].x;
		pts.y0 = fdf->map->c_sys[i][j].y;
		pts.x1 = fdf->map->c_sys[i][j + 1].x;
		pts.y1 = fdf->map->c_sys[i][j + 1].y;
		init_draw_var(&draw, pts);
		draw_line(pts, draw, fdf);
	}
	if (i < fdf->map->height - 1)
	{
		pts.x0 = fdf->map->c_sys[i][j].x;
		pts.y0 = fdf->map->c_sys[i][j].y;
		pts.x1 = fdf->map->c_sys[i + 1][j].x;
		pts.y1 = fdf->map->c_sys[i + 1][j].y;
		init_draw_var(&draw, pts);
		draw_line(pts, draw, fdf);
	}
}

int		draw(t_fdf *fdf)
{
	int			i;
	int			j;

	i = 0;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	ft_iso_projection(fdf);
	while (i < fdf->map->height)
	{
		j = 0;
		while (j < fdf->map->width)
		{
			init_and_draw(fdf, i, j);
			j++;
		}
		i++;
	}
	if (fdf->help)
		ft_help(fdf);
	return (0);
}

void	init_colors(t_fdf *fdf)
{
	if (fdf->argv_color)
		fdf->colors[0] = fdf->argv_color;
	else
		fdf->colors[0] = WHITE;
	fdf->colors[1] = RED;
	fdf->colors[2] = YELLOW;
	fdf->colors[3] = BLUE;
	fdf->colors[4] = GREEN;
	fdf->colors[5] = PURPLE;
	fdf->colors[6] = NAVY;
	fdf->colors[7] = GRAY;
	fdf->colors[8] = ORANGE;
	fdf->colors[9] = GOLD;
}

void	init(t_fdf *fdf)
{
	fdf->zoom = 0.75;
	fdf->height = 0.12;
	fdf->sin = 40;
	fdf->cos = 30;
	fdf->xm = 0;
	fdf->ym = 0;
	fdf->color_index = 0;
	fdf->help = 1;
	init_colors(fdf);
}

void	start_mlx(t_fdf *fdf)
{
	init(fdf);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "42 fdf");
	mlx_expose_hook(fdf->win_ptr, draw, fdf);
	mlx_key_hook(fdf->win_ptr, ft_key_hook, fdf);
	mlx_loop(fdf->mlx_ptr);
}
