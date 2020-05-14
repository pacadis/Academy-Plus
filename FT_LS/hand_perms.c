/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_perms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:39:44 by mflorea           #+#    #+#             */
/*   Updated: 2018/03/31 17:39:44 by mflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		first_part_perm(t_list_ls *mode)
{
	if (mode->file_stat.st_mode & S_ISUID)
		return ((mode->file_stat.st_mode & S_IXUSR) ? 's' : 'S');
	return ((mode->file_stat.st_mode & S_IXUSR) ? 'x' : '-');
}

char		sec_part_perm(t_list_ls *mode)
{
	if (mode->file_stat.st_mode & S_ISGID)
		return ((mode->file_stat.st_mode & S_IXGRP) ? 's' : 'S');
	return ((mode->file_stat.st_mode & S_IXGRP) ? 'x' : '-');
}

char		thr_part_perm(t_list_ls *mode)
{
	if (mode->file_stat.st_mode & S_ISVTX)
		return ((mode->file_stat.st_mode & S_IXOTH) ? 't' : 'T');
	return ((mode->file_stat.st_mode & S_IXOTH) ? 'x' : '-');
}

void		permissions(char *str, int index, t_list_ls *head)
{
	str[index++] = *((head->file_stat.st_mode & S_IRUSR) ? "r" : "-");
	str[index++] = *((head->file_stat.st_mode & S_IWUSR) ? "w" : "-");
	str[index++] = first_part_perm(head);
	str[index++] = *((head->file_stat.st_mode & S_IRGRP) ? "r" : "-");
	str[index++] = *((head->file_stat.st_mode & S_IWGRP) ? "w" : "-");
	str[index++] = sec_part_perm(head);
	str[index++] = *((head->file_stat.st_mode & S_IROTH) ? "r" : "-");
	str[index++] = *((head->file_stat.st_mode & S_IWOTH) ? "w" : "-");
	str[index++] = thr_part_perm(head);
	str[index++] = '\0';
}

char		*get_perm_file_type(t_list_ls *head)
{
	char	*str;
	int		index;

	index = 0;
	str = (char*)malloc(sizeof(char) * 20);
	if (head->file_stat.st_mode & S_ISDIR(head->file_stat.st_mode)
			|| S_ISDIR(head->file_stat.st_mode))
		str[index++] = 'd';
	else	if (head->file_stat.st_mode & S_ISLNK(head->file_stat.st_mode))
		str[index++] = 'l';
	else	if ((head->file_stat.st_mode & S_IFMT) == S_IFBLK)
		str[index++] = 'b';
	else	if ((head->file_stat.st_mode & S_IFMT) == S_IFIFO)
		str[index++] = 'f';
	else	if ((head->file_stat.st_mode & S_IFMT) == S_IFCHR)
		str[index++] = 'c';
	else	if ((head->file_stat.st_mode & S_IFMT) == S_IFSOCK)
		str[index++] = 's';
	else	if (head->file_stat.st_mode)
		str[index++] = '-';
	permissions(str, index, head);
	return (str);
}
