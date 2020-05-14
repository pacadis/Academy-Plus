/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acondor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:03:17 by acondor           #+#    #+#             */
/*   Updated: 2017/12/21 21:18:39 by acondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdelc(const char *s, char c)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s) - 1;
	while (s[i] == c)
		i++;
	while (s[j] == c)
		j--;
	str = ft_strnew(j - i + 1);
	while (i < j)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}
