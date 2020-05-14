/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacadis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:32:29 by pacadis           #+#    #+#             */
/*   Updated: 2017/05/15 14:32:42 by pacadis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *format_str, ...)
{
	va_list		ap;

	va_start(ap, format_str);
	while (*format_str)
	{
		if (*format_str == '%')
			format_str += ft_lexer(format_str, ap);
		else
			ft_buffer(format_str++, CHAR);
	}
	va_end(ap);
	return (ft_buffer(format_str, READ));
}

int main()
{
	int a = 10;
	ft_printf("%d ", a);
	return (0);
}
