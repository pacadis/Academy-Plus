/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acondor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 15:37:53 by acondor           #+#    #+#             */
/*   Updated: 2017/12/18 17:44:19 by acondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		a;

	if (*s == '\0')
		return (NULL);
	a = (int)ft_strlen(s);
	while (a >= 0)
	{
		if (*(s + a) == (char)c)
			return ((char *)s + a);
		a--;
	}
	return (NULL);
}
