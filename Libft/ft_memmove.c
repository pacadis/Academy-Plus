/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acondor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 22:00:16 by acondor           #+#    #+#             */
/*   Updated: 2017/11/25 21:39:29 by acondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (src < dst)
		while (len > 0)
		{
			*(d + len - 1) = *(s + len - 1);
			len--;
		}
	else
		while (i < len)
		{
			*(d + i) = *(s + i);
			i++;
		}
	return (dst);
}
