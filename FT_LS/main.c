/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:40:16 by mflorea           #+#    #+#             */
/*   Updated: 2018/03/31 17:40:17 by mflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	after_rec_read(t_list_ls *head, t_arg *arg, t_list_ls *q)
{
	if ((!head->d && S_ISDIR(head->file_stat.st_mode)) ||
			(arg->rec && head->d && S_ISDIR(head->file_stat.st_mode) &&
			(arg->a || (!arg->a && head->cont_p->d_name[0] != '.'))
			&& (ft_strcmp(head->cont_p->d_name, ".") &&
			ft_strcmp(head->cont_p->d_name, ".."))))
	{
		q = NULL;
		print_three("\n", head->str, "\n");
		if (head->d)
			recursive_reading(head->d, q, head->str, arg);
	}
	else	if (errno == EACCES)
	{
		error_message(errno, head->cont_p->d_name);
	}
	if (head->d)
	{
		closedir(head->d);
		free(head->cont_p);
		free(head->str);
	}
}

char	*concat_three_str(char *str, const char *s2, char *src)
{
	char *temp;

	temp = ft_strjoin("/", s2);
	str = ft_strjoin(src, temp);
	free(temp);
	return (str);
}

void	recursive_reading(DIR *dir, t_list_ls *head, char *src, t_arg *arg)
{
	struct dirent	*p;
	struct stat		file_stat;
	char			*s;
	t_list_ls		*q;
	int				a;

	p = readdir(dir);
	a = errno;
	q = NULL;
	s = NULL;
	if (!p)
	{
		sum(head, arg);
		return ;
	}
	s = concat_three_str(s, p->d_name, src);
	if (lstat(s, &file_stat) < 0)
		return ;
	if (a == EACCES && S_ISDIR(head->file_stat.st_mode))
		error_message(a, head->cont_p->d_name);
	errno = 0;
	head = insert(head, p, opendir(s), file_stat);
	head->str = s;
	recursive_reading(dir, head, src, arg);
	after_rec_read(head, arg, q);
}

int		main(int ac, char **av)
{
	DIR				*dir;
	t_list_ls		*head;
	t_arg			*arg;

	head = NULL;
	arg = (t_arg*)malloc(sizeof(t_arg));
	init(arg);
	handle_av(&ac, av, arg);
	if (ac == 0)
		dir = opendir(".");
	else
		dir = opendir(av[ac]);
	if (dir == NULL)
		error_message(errno, av[ac]);
	else
	{
		if (ac == 0)
			reading_dir(head, dir, arg, ".");
		else
			reading_dir(head, dir, arg, av[ac]);
	}
	return (0);
}
