/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacadis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:35:44 by pacadis           #+#    #+#             */
/*   Updated: 2017/05/15 14:33:12 by pacadis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbprint(unsigned long long nbr)
{
	t_format	*format;

	format = ft_format(SET_FORMAT);
	if (format->precision == 0)
	{
		if (format->HASH && format->conversion == 'o')
			return (ft_tmp("0", -1, S_JOIN));
		else
			return (nbr);
	}
	else
		return (ft_tmp("0", -1, S_JOIN));
}

int			ft_putnbr(unsigned long long nbr, int base, int c)
{
	char	str[NBR_SIZE + 1];
	int		len;

	str[NBR_SIZE] = '\0';
	len = NBR_SIZE - 1;
	if (nbr == 0)
		return (ft_nbprint(nbr));
	while (nbr)
	{
		if (c == 'X')
			str[len--] = "0123456789ABCDEF"[nbr % base];
		else
			str[len--] = "0123456789abcdef"[nbr % base];
		nbr /= base;
	}
	ft_tmp(str + len + 1, -1, S_JOIN);
	return (len);
}
