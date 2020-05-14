/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacadis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:11:53 by pacadis           #+#    #+#             */
/*   Updated: 2017/01/23 11:11:54 by pacadis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	if ((mem = (void*)malloc(size)) && size)
	{
		ft_bzero(mem, size);
		return (mem);
	}
	return (NULL);
}
