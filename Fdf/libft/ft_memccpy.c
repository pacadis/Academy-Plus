/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacadis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:12:00 by pacadis           #+#    #+#             */
/*   Updated: 2017/01/23 11:12:01 by pacadis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	counter;
	char	*str_dst;
	char	*str_src;

	if (!dst || !src)
		return (NULL);
	counter = 0;
	str_dst = (char *)dst;
	str_src = (char *)src;
	while (counter < n)
	{
		str_dst[counter] = str_src[counter];
		if ((char)c == str_dst[counter])
			return ((void*)&str_dst[counter + 1]);
		counter++;
	}
	return (NULL);
}
