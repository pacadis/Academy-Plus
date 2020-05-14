/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:40:04 by mflorea           #+#    #+#             */
/*   Updated: 2018/03/31 17:40:05 by mflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list_ls	*free_node(t_list_ls *head)
{
	t_list_ls *temp;

	if (!head->next)
	{
		free(head);
		return (NULL);
	}
	temp = NULL;
	if (head->next)
	{
		temp = head->next;
		free(head->cont_p);
		free(head->str);
		free(head->d);
		head->next = NULL;
		head->cont_p = NULL;
		head->str = NULL;
	}
	free(head);
	if (temp)
		return (temp);
	return (head);
}

t_list_ls	*insert_ordered(t_list_ls *head, t_list_ls *from)
{
	t_list_ls *new_node;
	t_list_ls *travers;

	new_node = (t_list_ls*)malloc(sizeof(t_list_ls));
	travers = head;
	if (!new_node)
		return (NULL);
	new_node->cont_p = from->cont_p;
	new_node->file_stat = from->file_stat;
	if (!head)
	{
		new_node->next = NULL;
		return (new_node);
	}
	if (ft_strcmp(from->cont_p->d_name, head->cont_p->d_name) < 0)
	{
		new_node->next = head;
		return (new_node);
	}
	while (travers->next != NULL && (ft_strcmp(travers->next->cont_p->d_name,
					from->cont_p->d_name) < 0))
		travers = travers->next;
	new_node->next = travers->next;
	travers->next = new_node;
	return (head);
}

t_list_ls	*insert_list(t_list_ls *head)
{
	t_list_ls *t;

	t = (t_list_ls*)malloc(sizeof(t_list_ls));
	t->next = NULL;
	t->cont_p = head->cont_p;
	t->file_stat = head->file_stat;
	return (t);
}
