/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acondor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:07:47 by acondor           #+#    #+#             */
/*   Updated: 2017/12/17 21:40:15 by acondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*lstbeg;
	t_list	*list;

	list = f(lst);
	lstbeg = list;
	lst = lst->next;
	if (!lst || !(*f))
		return (NULL);
	while (lst != NULL)
	{
		list->next = f(lst);
		list = list->next;
		lst = lst->next;
	}
	list->next = NULL;
	if (lstbeg == NULL)
		return (NULL);
	return (lstbeg);
}
