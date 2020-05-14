/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_flags_conv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacadis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:34:40 by pacadis           #+#    #+#             */
/*   Updated: 2017/05/15 14:33:25 by pacadis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_setflag(int off, t_format *format)
{
	format->flag[off] = 1;
	format->set = 1;
	return (1);
}

static int	ft_isflag(int c, t_format *format)
{
	if (c == '#')
		return (ft_setflag(0, format));
	if (c == '-')
		return (ft_setflag(1, format));
	if (c == '+')
		return (ft_setflag(2, format));
	if (c == ' ')
		return (ft_setflag(3, format));
	if (c == '0')
		return (ft_setflag(4, format));
	return (0);
}

int			ft_read_flags(char *arg, t_format *format)
{
	int	i;

	i = 0;
	while (ft_isflag(arg[i], format))
		i++;
	return (i);
}

int			ft_read_conversion(char *arg, t_format *format)
{
	if (!*arg)
		return (0);
	format->conversion = *arg;
	return (1);
}
