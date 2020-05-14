/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acondor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 19:26:32 by acondor           #+#    #+#             */
/*   Updated: 2017/12/17 19:57:26 by acondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*str;
	long long	k;
	int			s;

	s = ft_sizei(n);
	k = n;
	if (n < 0)
	{
		k = -k;
		s++;
	}
	if (!(str = ft_strnew(s)))
		return (NULL);
	str[--s] = k % 10 + '0';
	k = k / 10;
	while (k)
	{
		str[--s] = k % 10 + '0';
		k = k / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
