/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:32:39 by frosu             #+#    #+#             */
/*   Updated: 2017/07/19 11:38:07 by frosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	insert_at_end(t_bundle *begin_list, char *str)
{
	t_bundle *h;
	t_bundle *new;

	new = (t_bundle*)malloc(sizeof(t_bundle*));
	new->next = NULL;
	new->prev = NULL;
	new->str = str;
	h = begin_list;
}