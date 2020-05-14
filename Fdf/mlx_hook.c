/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 02:50:39 by mflorea           #+#    #+#             */
/*   Updated: 2018/02/10 02:50:40 by mflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline void	ft_move(t_fdf *fdf, int keycode)
{
	if (keycode == KEY_MOVE_RIGHT)
		fdf->xm += 50;
	if (keycode == KEY_MOVE_LEFT)
		fdf->xm -= 50;
	if (keycode == KEY_MOVE_UP)
		fdf->ym -= 50;
	if (keycode == KEY_MOVE_DOWN)
		fdf->ym += 50;
	draw(fdf);
}

static inline void	ft_rotate(t_fdf *fdf, int keycode)
{
	if (keycode == KEY_UP_ARROW)
		fdf->sin += 5;
	if (keycode == KEY_DOWN_ARROW)
		fdf->sin -= 5;
	if (keycode == KEY_LEFT_ARROW)
		fdf->cos -= 5;
	if (keycode == KEY_RIGHT_ARROW)
		fdf->cos += 5;
	draw(fdf);
}

static inline void	ft_zoom_color(t_fdf *fdf, int keycode)
{
	if (keycode == KEY_ZOOM_IN)
	{
		if (fdf->zoom < 3)
			fdf->zoom += 0.1;
	}
	if (keycode == KEY_ZOOM_OUT)
	{
		if (fdf->zoom > 0.1)
			fdf->zoom -= 0.1;
	}
	if (keycode == KEY_COLOR)
	{
		if (fdf->color_index == 9)
			fdf->color_index = 0;
		else
			fdf->color_index++;
		draw(fdf);
	}
	draw(fdf);
}

static inline void	ft_help_height(t_fdf *fdf, int keycode)
{
	if (keycode == KEY_HEIGHT_UP)
	{
		fdf->height += 0.025;
		draw(fdf);
	}
	if (keycode == KEY_HEIGHT_DOWN)
	{
		fdf->height -= 0.025;
		draw(fdf);
	}
	if (keycode == KEY_HELP)
	{
		if (fdf->help)
			fdf->help = 0;
		else
			fdf->help = 1;
		draw(fdf);
	}
	draw(fdf);
}

int					ft_key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		exit(EXIT_SUCCESS);
	if (keycode == KEY_UP_ARROW || keycode == KEY_DOWN_ARROW ||
			keycode == KEY_LEFT_ARROW || keycode == KEY_RIGHT_ARROW)
		ft_rotate(fdf, keycode);
	if (keycode == KEY_ZOOM_IN || keycode == KEY_ZOOM_OUT ||
			keycode == KEY_COLOR)
		ft_zoom_color(fdf, keycode);
	if (keycode == KEY_MOVE_RIGHT || keycode == KEY_MOVE_LEFT ||
			keycode == KEY_MOVE_UP || keycode == KEY_MOVE_DOWN)
		ft_move(fdf, keycode);
	if (keycode == KEY_HEIGHT_UP || keycode == KEY_HEIGHT_DOWN ||
			keycode == KEY_HELP)
		ft_help_height(fdf, keycode);
	return (0);
}
