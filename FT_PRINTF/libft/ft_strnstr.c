/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacadis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:17:43 by pacadis           #+#    #+#             */
/*   Updated: 2017/01/23 11:18:07 by pacadis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[j] && j < len)
	{
		while (needle[i] && haystack[j + i] && haystack[j + i] ==
				needle[i] && j + i < len)
		{
			i++;
			if (ft_strlen(needle) == i)
				return ((char *)haystack + j);
		}
		i = 0;
		j++;
	}
	return (NULL);
}
