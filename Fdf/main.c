/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 02:50:24 by mflorea           #+#    #+#             */
/*   Updated: 2018/02/10 02:50:25 by mflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_exit(int offset)
{
	char	**msg;

	msg = (char**)malloc(sizeof(char*) * 5);
	msg[0] = "Usage: ./fdf <filename>\
			[optional: color]\nColor format: 0xFFFFFF\n";
	msg[1] = "No file opened. Exiting.\n";
	msg[2] = "Found wrong line length. Exiting\n";
	msg[3] = "No data found. Exiting.\n";
	msg[4] = "Invalid color. Exiting.\n";
	ft_putstr(msg[offset]);
	exit(EXIT_SUCCESS);
}

int		main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc < 2 || argc > 3)
		ft_exit(0);
	else
	{
		fdf.argv_color = 0;
		if (argc == 3)
			ft_color_argv(argv[2], &fdf);
		fdf.map = ft_read_map(argv[1]);
		start_mlx(&fdf);
	}
	return (0);
}
