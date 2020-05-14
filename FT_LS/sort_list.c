/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:40:25 by mflorea           #+#    #+#             */
/*   Updated: 2018/03/31 17:45:40 by mflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list_ls	*insert(t_list_ls *head, struct dirent *cont_p, DIR *dir,
	struct stat file_stat)
{
	t_list_ls		*temp;
	DIR				*p_d;
	struct dirent	*p;

	temp = (t_list_ls *)malloc(sizeof(t_list_ls));
	if (!temp)
		return (NULL);
	p_d = (DIR*)malloc(sizeof(DIR*));
	p = (struct dirent*)malloc(sizeof(struct dirent));
	ft_memcpy(p, cont_p, sizeof(struct dirent));
	p_d = dir;
	temp->d = p_d;
	temp->cont_p = p;
	temp->file_stat = file_stat;
	if (head == NULL)
	{
		temp->next = NULL;
		return (temp);
	}
	else
	{
		temp->next = head;
		head = temp;
	}
	return (head);
}

void		cmp_func(t_list_ls *s1, t_list_ls *s2, t_arg *arg)
{
	t_list_ls *aux;

	if (!arg->t)
	{
		if (ft_strcmp(s1->cont_p->d_name, s2->cont_p->d_name) > 0)
		{
			aux = s1;
			s1 = s2;
			s2 = aux;
		}
	}
}

void		swaps(t_list_ls *s1, t_list_ls *aux, t_list_ls *s2)
{
	aux->cont_p = s1->cont_p;
	aux->str = s1->str;
	aux->file_stat = s1->file_stat;
	aux->d = s1->d;
	s1->str = s2->str;
	s1->cont_p = s2->cont_p;
	s1->file_stat = s2->file_stat;
	s1->d = s2->d;
	s2->str = aux->str;
	s2->cont_p = aux->cont_p;
	s2->file_stat = aux->file_stat;
	s2->d = aux->d;
}

void		sort_list_help(t_list_ls *s1, t_list_ls *s2,
	t_list_ls *aux, t_arg *arg)
{
	if (!arg->t && !arg->r &&
		ft_strcmp(s1->cont_p->d_name, s2->cont_p->d_name) < 0)
		swaps(s1, aux, s2);
	else	if (!arg->t && arg->r &&
		ft_strcmp(s1->cont_p->d_name, s2->cont_p->d_name) > 0)
		swaps(s1, aux, s2);
	else	if (arg->t)
	{
		if (arg->r)
		{
			if (s1->file_stat.st_mtime < s2->file_stat.st_mtime)
				swaps(s1, aux, s2);
			else	if (s1->file_stat.st_mtime == s2->file_stat.st_mtime
				&& (ft_strcmp(s1->cont_p->d_name, s2->cont_p->d_name) >= 0))
				swaps(s1, aux, s2);
		}
		else
		{
			if (s1->file_stat.st_mtime > s2->file_stat.st_mtime)
				swaps(s1, aux, s2);
			else	if (s1->file_stat.st_mtime == s2->file_stat.st_mtime
				&& (ft_strcmp(s1->cont_p->d_name, s2->cont_p->d_name) <= 0))
				swaps(s1, aux, s2);
		}
	}
}

void		sort_list(t_list_ls *head, t_arg *arg)
{
	t_list_ls *aux;
	t_list_ls *s1;
	t_list_ls *s2;

	aux = (t_list_ls*)malloc(sizeof(t_list_ls));
	s1 = head;
	s2 = head;
	while (s1)
	{
		while (s2)
		{
			sort_list_help(s1, s2, aux, arg);
			s2 = s2->next;
		}
		s2 = head;
		s1 = s1->next;
	}
	free(aux);
}
