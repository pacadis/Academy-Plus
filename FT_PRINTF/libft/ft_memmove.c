/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacadis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:12:34 by pacadis           #+#    #+#             */
/*   Updated: 2017/01/23 11:12:35 by pacadis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *s;

	s = (unsigned char*)malloc(sizeof(s) * len);
	if (s == NULL)
		return (dst);
	ft_memcpy(s, src, len);
	ft_memcpy(dst, s, len);
	free(s);
	return (dst);
}
