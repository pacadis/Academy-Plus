/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acondor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 21:45:31 by acondor           #+#    #+#             */
/*   Updated: 2017/12/14 17:33:26 by acondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*sou;
	unsigned char	*des;

	i = 0;
	des = (unsigned char *)dst;
	sou = (unsigned char *)src;
	while (i < n)
	{
		*des = *sou;
		if (*des == (unsigned char)c)
			return (&dst[i + 1]);
		des++;
		sou++;
		i++;
	}
	return (NULL);
}
