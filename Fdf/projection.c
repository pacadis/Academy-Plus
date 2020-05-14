/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 02:50:52 by mflorea           #+#    #+#             */
/*   Updated: 2018/02/10 02:50:53 by mflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_iso_projection(t_fdf *fdf)
{
	double		sin_angle;
	double		cos_angle;
	double		spacing;
	int			i;
	int			j;

	sin_angle = sin(fdf->sin * M_PI / 180);
	cos_angle = cos(fdf->cos * M_PI / 180);
	spacing = fdf->zoom * (WIDTH / (fdf->map->height * 0.5 +
				fdf->map->width * 0.86));
	i = -1;
	while (++i < fdf->map->height)
	{
		j = -1;
		while (++j < fdf->map->width)
		{
			fdf->map->c_sys[i][j].x = (i - fdf->map->height / 2) * spacing
				* -cos_angle + (j - fdf->map->width / 2) * spacing
				* cos_angle + WIDTH / 2 + fdf->xm;
			fdf->map->c_sys[i][j].y = (i - fdf->map->height / 2) * spacing *
				sin_angle - (j - fdf->map->width / 2) * spacing * -sin_angle -
				fdf->map->c_sys[i][j].z * fdf->height * spacing +
				HEIGHT / 2 + fdf->ym;
		}
	}
}
