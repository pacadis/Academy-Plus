/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:39:51 by mflorea           #+#    #+#             */
/*   Updated: 2018/03/31 17:39:52 by mflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		printing_func(t_list_ls *head, t_arg *arg, t_count_art cou)
{
	struct group	*get_id;
	struct passwd	*pwd;

	if (!arg->l)
	{
		ft_putstr(head->cont_p->d_name);
		ft_putchar('\n');
	}
	else
	{
		if ((get_id = getgrgid(head->file_stat.st_gid)) == NULL ||
				((pwd = getpwuid(head->file_stat.st_uid)) == NULL))
			return ;
		ft_putstr(get_perm_file_type(head));
		hand_user_size_hlnk(head, get_id, pwd, cou);
		hand_print_time(head);
		hand_print_lnk(head);
	}
}

void		print_unsig(unsigned int var)
{
	char	*str;
	int		index;

	index = 0;
	if (!var)
	{
		ft_putchar('0');
		return ;
	}
	str = (char*)malloc(sizeof(char) * 50);
	index = get_dig(var);
	str[index--] = '\0';
	while (var)
	{
		str[index--] = var % 10 + '0';
		var /= 10;
	}
	ft_putstr(str);
	free(str);
}

void		space_before(int var)
{
	char	*s;
	int		index;

	s = (char*)malloc(sizeof(char) * 100);
	index = 0;
	while (var-- > -1)
		s[index++] = ' ';
	s[index] = '\0';
	ft_putstr(s);
	free(s);
}

void		hand_print_time(t_list_ls *head)
{
	time_t				curtime;
	unsigned long long	a;
	char				*s;
	unsigned int		i;

	i = 3;
	a = time(&curtime);
	s = ft_strdup(ctime(&(head->file_stat.st_mtime)));
	if (a - head->file_stat.st_mtime >= 15778500)
	{
		while (i < ft_strlen(s) - 15)
			ft_putchar(s[i++]);
		ft_putchar(' ');
		i = ft_strlen(s) - 6;
		while (i < ft_strlen(s) - 1)
			ft_putchar(s[i++]);
	}
	else
		while ((i < ft_strlen(s) - 9) && s[i] != '\n')
			ft_putchar(s[i++]);
}
