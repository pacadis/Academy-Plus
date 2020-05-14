/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:40:21 by mflorea           #+#    #+#             */
/*   Updated: 2018/03/31 17:40:21 by mflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	handle_av_ish(char *av[], int *i, int *j, t_arg *arg)
{
	if (!ft_strchr("lRartdgfd1", av[*i][1]))
	{
		ft_putstr_fd("ls: invalid option -- \'", 2);
		ft_putchar(av[*i][1]);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("usage: ft_ls [-Ralrt] [file ...]\n", 2);
		exit(1);
	}
	arg->l += (av[*i][*j] == 'l') ? 1 : 0;
	arg->rec += (av[*i][*j] == 'R') ? 1 : 0;
	arg->a += (av[*i][*j] == 'a') ? 1 : 0;
	arg->r += (av[*i][*j] == 'r') ? 1 : 0;
	arg->t += (av[*i][*j] == 't') ? 1 : 0;
	arg->u += (av[*i][*j] == 'd') ? 1 : 0;
	arg->f += (av[*i][*j] == 'g') ? 1 : 0;
	arg->f += (av[*i][*j] == 'f') ? 1 : 0;
	arg->d += (av[*i][*j] == 'd') ? 1 : 0;
	*j = *j + 1;
}

void	handle_av(int *ac, char *av[], t_arg *arg)
{
	int i;
	int j;

	i = 1;
	while (i < *ac)
	{
		if (av[i][0] == '-' && av[i][1])
		{
			j = 1;
			while (av[i][j])
				handle_av_ish(av, &i, &j, arg);
		}
		else
		{
			*ac = i;
			return ;
		}
		i++;
	}
	if (*ac)
		*ac = 0;
}

void	init(t_arg *arg)
{
	arg->l = 0;
	arg->rec = 0;
	arg->a = 0;
	arg->r = 0;
	arg->t = 0;
	arg->u = 0;
	arg->f = 0;
	arg->g = 0;
	arg->d = 0;
}
