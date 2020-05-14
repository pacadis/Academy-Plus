/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:39:30 by mflorea           #+#    #+#             */
/*   Updated: 2018/03/31 17:39:31 by mflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "./libft/libft.h"
# include <sys/types.h>
# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <sys/xattr.h>

typedef struct			s_count_art
{
	int					nlink;
	int					size;
	int					get_id;
	int					pwd;
	int					block;
	int					ext_atr;
	unsigned int		minor_nr;
	unsigned int		major_nr;
}						t_count_art;

typedef struct			s_list_ls
{
	struct dirent		*cont_p;
	struct stat			file_stat;
	struct s_list_ls	*next;
	char				*str;
	int					access;
	DIR					*d;
}						t_list_ls;

typedef struct			s_arg
{
	int					l;
	int					rec;
	int					a;
	int					r;
	int					t;
	int					u;
	int					f;
	int					g;
	int					d;
}						t_arg;

void					ft_putnbrs(long long n);
void					print_three(char *s1, char *s2, char *s3);
void					hand_print_lnk(t_list_ls *head);
void					hand_user_size_hlnk(t_list_ls *head,
		struct group *get_id, struct passwd *pwd, t_count_art cou);
void					space_before(int var);
void					hand_print_time(t_list_ls *head);
void					space_before(int var);
void					print_unsig(unsigned int var);
void					printing_func(t_list_ls *head, t_arg *arg,
	t_count_art cou);
void					permissions(char *str, int index, t_list_ls *head);
void					free_struct(t_list_ls *head);
void					delete_if_a(t_list_ls *head, t_arg *arg);
char					*get_perm_file_type(t_list_ls *head);
char					thr_part_perm(t_list_ls *mode);
char					sec_part_perm(t_list_ls *mode);
char					first_part_perm(t_list_ls *mode);
int						get_nr_dig(int a);
int						get_dig(unsigned int var);
void					sort_list(t_list_ls *head, t_arg *arg);
void					print_list(t_list_ls *head, t_arg *arg);
void					error_message(int error, char *av);
void					handle_av(int *ac, char *av[], t_arg *arg);
void					recursive_reading(DIR *dir, t_list_ls *head,
	char *src, t_arg *arg);
void					sum(t_list_ls *head, t_arg *arg);
void					cmp_func(t_list_ls *s1, t_list_ls *s2, t_arg *arg);
void					swap_every_fucking_thing(t_list_ls *s1,
		t_list_ls *aux, t_list_ls *s2);
void					reading_dir(t_list_ls *head, DIR *dir,
	t_arg *arg, char *src);
void					init(t_arg *arg);
void					get_the_biggest(t_list_ls *head,
	t_arg *arg, t_count_art *cou);
t_list_ls				*free_node(t_list_ls *head);
t_list_ls				*insert(t_list_ls *head,
		struct dirent *cont_p, DIR *dir, struct stat file_stat);
t_list_ls				*insert_ordered(t_list_ls *head, t_list_ls *from);
t_list_ls				*insert_list(t_list_ls *head);

#endif
