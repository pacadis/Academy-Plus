/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:39:22 by mflorea           #+#    #+#             */
/*   Updated: 2018/03/31 17:39:23 by mflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	error_message(int error, char *av)
{
	char *s;

	s = strerror(error);
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(av, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
}

void	hand_bck_input_manage(t_list_ls *head, t_count_art *cou)
{
	if (((head->file_stat.st_mode & S_IFMT) == S_IFCHR) ||
		((head->file_stat.st_mode & S_IFMT) == S_IFBLK))
	{
		if ((int)cou->minor_nr < get_dig(minor(head->file_stat.st_rdev)))
			cou->minor_nr = get_dig(minor(head->file_stat.st_rdev));
		if ((int)cou->major_nr < get_dig(major(head->file_stat.st_rdev)))
			cou->major_nr = get_dig(major(head->file_stat.st_rdev));
	}
}

void	init_count(t_list_ls *head, t_list_ls *t, t_count_art *temp)
{
	temp->nlink = 0;
	temp->size = 0;
	temp->get_id = 0;
	temp->pwd = 0;
	temp->major_nr = 0;
	temp->minor_nr = 0;
	temp->ext_atr = 1;
	t = head;
}

void	get_the_biggest(t_list_ls *head, t_arg *arg, t_count_art *cou)
{
	t_list_ls		*t;
	struct group	*get_id;
	struct passwd	*pwd;

	t = head;
	init_count(head, t, cou);
	while (t)
	{
		if (arg->a || (!arg->a && t->cont_p->d_name[0] != '.'))
		{
			if ((get_id = getgrgid(t->file_stat.st_gid)) == NULL ||
				((pwd = getpwuid(t->file_stat.st_uid)) == NULL))
				return ;
			if (get_nr_dig(t->file_stat.st_size) > cou->size)
				cou->size = get_dig(t->file_stat.st_size);
			if (get_nr_dig(t->file_stat.st_nlink) > cou->nlink)
				cou->nlink = get_nr_dig(t->file_stat.st_nlink);
			if ((int)ft_strlen(pwd->pw_name) > cou->pwd)
				cou->pwd = ft_strlen(pwd->pw_name);
			if ((int)ft_strlen(get_id->gr_name) > cou->get_id)
				cou->get_id = ft_strlen(get_id->gr_name);
			hand_bck_input_manage(t, cou);
		}
		t = t->next;
	}
}

void	reading_dir(t_list_ls *head, DIR *dir, t_arg *arg, char *src)
{
	recursive_reading(dir, head, src, arg);
}
