/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacadis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:12:06 by pacadis           #+#    #+#             */
/*   Updated: 2017/01/23 11:12:06 by pacadis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	counter;

	if (!(str = (char *)s))
		return (NULL);
	counter = 0;
	while (counter < n)
	{
		if ((char)c == str[0])
			return ((void*)str);
		str++;
		counter++;
	}
	return (NULL);
}
