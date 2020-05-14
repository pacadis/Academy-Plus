/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acondor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:49:31 by acondor           #+#    #+#             */
/*   Updated: 2017/11/26 22:01:46 by acondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*sou;
	char	*des;

	i = 0;
	des = (char *)dst;
	sou = (char *)src;
	while (i < n)
	{
		*(des + i) = *(sou + i);
		i++;
	}
	return (dst);
}
