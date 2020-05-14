/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacadis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:34:12 by pacadis           #+#    #+#             */
/*   Updated: 2017/05/15 14:32:22 by pacadis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_preffsize(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_preffconv(int c)
{
	if (c == 's')
		return (' ');
	else
		return ('0');
}

int			ft_join(t_format *format, char *str)
{
	int		size;
	int		prec;
	char	preff;

	size = ft_tmp(NULL, 0, S_READ);
	prec = (size > format->precision) ? size : format->precision;
	preff = (format->ZERO) ? '0' : ' ';
	format->width -= ft_preffsize(str);
	if (!format->MINUS)
	{
		if (preff == '0')
			ft_buffer(str, STR);
		ft_preff(preff, format->width - prec);
	}
	if (preff == ' ')
		ft_buffer(str, STR);
	if (prec > size && size)
		ft_preff(ft_preffconv(format->conversion), prec - size);
	ft_tmp(NULL, 0, S_PRINT);
	if (format->MINUS)
		ft_preff(' ', format->width - prec);
	return (0);
}
