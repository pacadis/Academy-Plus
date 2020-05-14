/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acondor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:29:58 by acondor           #+#    #+#             */
/*   Updated: 2017/12/11 20:17:30 by acondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char *start;

	start = dst;
	while (*src)
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
	return (start);
}
