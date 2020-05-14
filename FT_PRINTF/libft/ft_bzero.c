/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacadis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:09:25 by pacadis           #+#    #+#             */
/*   Updated: 2017/01/23 11:09:27 by pacadis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_char;

	if (s == NULL || n <= 0)
		return ;
	s_char = (unsigned char *)s;
	while (n--)
		*s_char++ = 0;
}
