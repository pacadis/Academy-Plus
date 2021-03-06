/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacadis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:09:18 by pacadis           #+#    #+#             */
/*   Updated: 2017/01/23 15:36:26 by pacadis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int nbr;
	int i;
	int neg;

	i = 0;
	neg = 0;
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (!(str[i] >= 48 && str[i] <= 57))
			return (0);
	}
	if (str[i - 1] == '-')
		neg = 1;
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		nbr = (nbr * 10) + (str[i] - 48);
		i++;
	}
	if (neg == 1)
		nbr = nbr * (-1);
	return (nbr);
}
