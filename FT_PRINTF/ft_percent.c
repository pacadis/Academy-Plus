/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacadis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:34:19 by pacadis           #+#    #+#             */
/*   Updated: 2017/05/15 14:32:09 by pacadis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent(va_list ap)
{
	t_format	*format;
	char		preff;

	(void)ap;
	format = ft_format(SET_FORMAT);
	if (format->ZERO)
		preff = '0';
	else
		preff = ' ';
	if (!format->MINUS)
		ft_preff(preff, format->width - 1);
	ft_buffer("%", STR);
	if (format->MINUS)
		ft_preff(' ', format->width - 1);
	return (0);
}
