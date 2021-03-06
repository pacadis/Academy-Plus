/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacadis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:11:48 by pacadis           #+#    #+#             */
/*   Updated: 2017/01/23 11:11:49 by pacadis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(int a[], int n)
{
	int i;
	int max;

	i = 0;
	max = a[0];
	while (i < n)
	{
		if (a[i] > max)
			max = a[i];
		i++;
	}
	return (max);
}
