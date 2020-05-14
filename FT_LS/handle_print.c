/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:39:57 by mflorea           #+#    #+#             */
/*   Updated: 2018/03/31 17:39:58 by mflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		hand_print_lnk(t_list_ls *head)
{
	int		len;
	int		i;
	char	buf[1024];

	ft_strcpy(buf, "");
	len = 0;
	i = 0;
	if (head->file_stat.st_mode & S_ISLNK(head->file_stat.st_mode))
	{
		print_three(" ", head->cont_p->d_name, "");
		len = readlink(head->str, buf, sizeof(buf));
		if (len != -1)
		{
			ft_putstr(" -> ");
			while (buf[i] && i < len)
				ft_putchar(buf[i++]);
			ft_putchar('\n');
		}
	}
	else
		print_three(" ", head->cont_p->d_name, "\n");
}

void		symbolic_links_ish(t_list_ls *head, struct group *get_id,
		struct passwd *pwd, t_count_art cou)
{
	if ((!(head->file_stat.st_mode & S_ISLNK(head->file_stat.st_mode))
				&& listxattr(head->str, NULL, 0, 0) > 0) ||
				((head->file_stat.st_mode & S_ISLNK(head->file_stat.st_mode))
				&& listxattr(head->str, NULL, 0, XATTR_NOFOLLOW) > 0))
		ft_putchar('@');
	else
		ft_putchar(' ');
	errno = 0;
	space_before(cou.nlink - get_dig(head->file_stat.st_nlink) - 1);
	ft_putchar(' ');
	ft_putnbr(head->file_stat.st_nlink);
	ft_putchar(' ');
	ft_putstr(pwd->pw_name);
	space_before(cou.pwd - ft_strlen(pwd->pw_name));
	ft_putchar(' ');
	ft_putstr(get_id->gr_name);
}

void		hand_user_size_hlnk(t_list_ls *head, struct group *get_id,
		struct passwd *pwd, t_count_art cou)
{
	symbolic_links_ish(head, get_id, pwd, cou);
	space_before(cou.get_id - ft_strlen(get_id->gr_name));
	if (((head->file_stat.st_mode & S_IFMT) == S_IFCHR) ||
			((head->file_stat.st_mode & S_IFMT) == S_IFBLK))
	{
		space_before(cou.major_nr -
				get_dig(major(head->file_stat.st_rdev)) + 1);
		ft_putnbr(major(head->file_stat.st_rdev));
		ft_putchar(',');
		space_before(cou.minor_nr - get_dig(minor(head->file_stat.st_rdev)));
		ft_putnbr((minor(head->file_stat.st_rdev)));
	}
	else
	{
		if (cou.minor_nr && cou.major_nr)
			space_before(cou.minor_nr + cou.major_nr -
					get_dig(head->file_stat.st_size) + 3);
		else
			space_before(cou.size - get_dig(head->file_stat.st_size));
		ft_putnbrs(head->file_stat.st_size);
	}
}

void		print_list(t_list_ls *head, t_arg *arg)
{
	t_list_ls		*temp;
	t_count_art		*cou;
	t_list_ls		*a;

	a = head;
	temp = head;
	cou = (t_count_art*)malloc(sizeof(t_count_art));
	cou->size = 0;
	cou->nlink = 0;
	if (temp && (((temp->file_stat.st_mode & S_IFMT) == S_IFCHR) ||
				((temp->file_stat.st_mode & S_IFMT) == S_IFBLK)))
		cou->block = 'b';
	get_the_biggest(head, arg, cou);
	while (temp)
	{
		if (arg->a)
			printing_func(temp, arg, *cou);
		else	if (temp->cont_p->d_name[0] != '.')
			printing_func(temp, arg, *cou);
		temp = temp->next;
	}
	free(cou);
}
