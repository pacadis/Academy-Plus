/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sum_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:40:12 by mflorea           #+#    #+#             */
/*   Updated: 2018/03/31 17:40:12 by mflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_nr_dig(int a)
{
	int i;

	i = 0;
	if (!a)
		return (1);
	while (a)
	{
		i++;
		a /= 10;
	}
	return (i);
}

void	jezzz(t_arg *arg, long long s, int a)
{
	if ((a != 0 && arg->l) || (a == 0 && arg->a))
	{
		ft_putstr("total ");
		ft_putnbrs(s);
		ft_putchar('\n');
	}
}

void	sum(t_list_ls *head, t_arg *arg)
{
	long long	s;
	int			a;
	t_list_ls	*t;

	s = 0;
	a = 0;
	t = head;
	while (t)
	{
		if (arg->a)
			s += t->file_stat.st_blocks;
		else	if (t->cont_p->d_name[0] != '.')
			s += t->file_stat.st_blocks;
		a += (t->cont_p->d_name[0] != '.') ? 1 : 0;
		t = t->next;
	}
	jezzz(arg, s, a);
	sort_list(head, arg);
	print_list(head, arg);
}

void	free_struct(t_list_ls *head)
{
	free(head->cont_p);
	free(head->str);
	free(head->d);
}

void	delete_if_a(t_list_ls *head, t_arg *arg)
{
	t_list_ls *t;

	if (arg->a)
		return ;
	if (!head->next && head->cont_p->d_name[0] == '.')
		free_node(head);
	t = head;
	while (t->next)
	{
		if (t->next->cont_p->d_name[0] == '.')
		{
			free_struct(t->next);
			if (t->next->next)
				t->next = t->next->next;
			else
				t->next = NULL;
		}
		t = t->next;
	}
}
