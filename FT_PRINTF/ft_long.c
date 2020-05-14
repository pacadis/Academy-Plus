/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacadis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:35:30 by pacadis           #+#    #+#             */
/*   Updated: 2017/05/15 14:29:50 by pacadis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_long(va_list ap)
{
	t_format	*format;

	format = ft_format(SET_FORMAT);
	format->length = 'l';
	format->set = 1;
	format->conversion = format->conversion + 32;
	return (ft_convertor(ap, format));
}
