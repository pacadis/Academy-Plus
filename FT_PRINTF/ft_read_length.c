/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacadis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:35:52 by pacadis           #+#    #+#             */
/*   Updated: 2017/05/15 14:33:36 by pacadis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_search_short(char c, t_format *format)
{
	if (!(format->length == 'h' || format->length == 'H'
				|| format->length == '0') && (c == 'h' || c == 'H'))
		return (format->length);
	else
		return (c);
}

static int	ft_setlen(char c, t_format *format)
{
	format->length = ft_search_short(c, format);
	format->set = 1;
	if (c == 'L' || c == 'H')
		return (2);
	else
		return (1);
}

int			ft_read_length(char *arg, t_format *format)
{
	if (arg[0] == 'l' || arg[0] == 'h')
	{
		if (arg[1] == 'l' && arg[0] == 'l')
			return (ft_setlen('L', format));
		if (arg[1] == 'h' && arg[0] == 'h')
			return (ft_setlen('H', format));
		return (ft_setlen(arg[0], format));
	}
	else if (arg[0] == 'j' || arg[0] == 'z')
		return (ft_setlen(arg[0], format));
	else
		return (0);
}
