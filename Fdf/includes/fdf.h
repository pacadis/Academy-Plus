/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 02:51:06 by mflorea           #+#    #+#             */
/*   Updated: 2018/02/10 02:51:07 by mflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include "../libft/libft.h"

# define WIDTH              800
# define HEIGHT             700

# define KEY_ESC            53
# define KEY_Q              12
# define KEY_LEFT_ARROW     123
# define KEY_RIGHT_ARROW    124
# define KEY_DOWN_ARROW     125
# define KEY_UP_ARROW       126
# define KEY_ZOOM_IN        69
# define KEY_ZOOM_OUT       78
# define KEY_COLOR          8
# define KEY_HEIGHT_UP      4
# define KEY_HEIGHT_DOWN    38
# define KEY_MOVE_UP        91
# define KEY_MOVE_DOWN      84
# define KEY_MOVE_RIGHT     88
# define KEY_MOVE_LEFT      86
# define KEY_HELP           122

# define WHITE              0xFFFFFF
# define RED                0xFF0000
# define YELLOW             0xFFFF00
# define BLUE               0x0000FF
# define GREEN              0x33CC33
# define PURPLE             0x9900FF
# define NAVY               0x9966FF
# define GRAY               0x808080
# define ORANGE             0xFFA500
# define GOLD               0xFFD700

# define MENU_COLOR         0xFFFFFF

typedef struct		s_point
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
}					t_point;

typedef struct		s_draw
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
}					t_draw;

typedef struct		s_coordinates
{
	int		x;
	int		y;
	int		z;
	int		color;
}					t_coordinates;

typedef struct		s_map
{
	t_coordinates	**c_sys;
	int				width;
	int				height;
}					t_map;

typedef struct		s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
	double	zoom;
	double	height;
	int		sin;
	int		cos;
	int		xm;
	int		ym;
	int		colors[10];
	int		color_index;
	int		argv_color;
	int		help;
}					t_fdf;

t_map				*ft_read_map(char *file);
void				ft_iso_projection(t_fdf *fdf);
void				ft_exit(int error);
int					ft_line_len(char *str);
void				ft_color_argv(char *str, t_fdf *fdf);
void				ft_help(t_fdf *fdf);
int					ft_key_hook(int keycode, t_fdf *fdf);

void				init_and_draw(t_fdf *fdf, int i, int j);
int					draw(t_fdf *fdf);
void				init_colors(t_fdf *fdf);
void				init(t_fdf *fdf);
void				start_mlx(t_fdf *fdf);
void				draw_line(t_point pts, t_draw draw, t_fdf *fdf);
void				init_draw_var(t_draw *draw, t_point pts);
void				height_hook(int keycode, t_fdf *fdf);
void				help_hook(t_fdf *fdf);

#endif
