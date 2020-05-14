/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acondor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 21:18:50 by acondor           #+#    #+#             */
/*   Updated: 2017/12/11 20:26:45 by acondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*start;

	start = (void *)s;
	while (n > 0)
	{
		if (*start == (unsigned char)c)
			return (start);
		start++;
		n--;
	}
	return (0);
}
