/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acondor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:41:19 by acondor           #+#    #+#             */
/*   Updated: 2017/11/25 20:21:20 by acondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *start;

	start = (unsigned char *)b;
	while (len > 0)
	{
		*start = (unsigned char)c;
		start++;
		len--;
	}
	return (b);
}
