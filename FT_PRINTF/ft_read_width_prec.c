/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_width_prec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacadis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:34:46 by pacadis           #+#    #+#             */
/*   Updated: 2017/05/15 14:33:50 by pacadis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_read_width(char *arg, va_list ap, t_format *format)
{
	char	*tmp;
	int		nbr;

	tmp = arg;
	if (*tmp == '*' || (*tmp >= '0' && *tmp <= '9'))
	{
		if (*tmp == '*' && arg++)
		{
			nbr = va_arg(ap, int);
			if (nbr < 0)
			{
				nbr = -nbr;
				format->MINUS = 1;
			}
			format->width = nbr;
		}
		else
			format->width = ft_atoi(&arg);
		if (format->width)
			format->set = 1;
	}
	return (arg - tmp);
}

int	ft_read_precision(char *arg, va_list ap, t_format *format)
{
	char	*tmp;
	int		nb;

	tmp = arg;
	if (*arg == '.')
	{
		arg++;
		if (*arg == '*' && arg++)
		{
			nb = va_arg(ap, int);
			if (nb > 0)
				format->set = 1;
			if (nb < 0)
				nb = format->precision;
			format->precision = nb;
		}
		else
		{
			format->precision = ft_atoi(&arg);
			format->set = 1;
		}
	}
	return (arg - tmp);
}
