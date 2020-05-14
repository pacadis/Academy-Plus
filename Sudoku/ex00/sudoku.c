/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 10:01:40 by riosif            #+#    #+#             */
/*   Updated: 2017/08/19 22:07:00 by riosif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		**a;

int		findloc(int **a, int *l, int *c)
{
	int		i;
	int 	j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (a[i][j] == 0)
			{
				*l = i;
				*c = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		frow(int **a, int l, int n)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		if (a[l][i] == n)
			return (1);
		i++;
	}
	return (0);
}

int		fcol(int **a, int c, int n)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		if (a[i][c] == n)
			return (1);
		i++;
	}
	return (0);
}

int		box(int **a, int sl, int sc, int n)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (a[i + sl][j + sc] == n)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		is_ok(int **a, int l, int c, int n)
{
	if (frow(a, l, n) || fcol(a, c, n) || box(a, l - l % 3, c - c % 3, n))
		return (0);
	return (1);
}

int		solve_it(int **a)
{
	int		n;
	int		l;
	int		c;

	if (findloc(a, &l, &c) == 0)
		return (1);
	n = 1;
	while (n <= 9)
	{
		if (is_ok(a, l, c, n) == 1)
		{
			a[l][c] = n;
			if (solve_it(a) == 1)
				return (1);
			a[l][c] = 0;
		}
		n++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	a = (int**)malloc(sizeof(int*) * 9);
	while (i < argc)
	{
		a[i - 1] = (int*)malloc(sizeof(int) * 9);
		j = 0;
		while (j < 9)
		{
			if (argv[i][j] == '.')
				a[i - 1][j] = 0;
			else
				a[i - 1][j] = argv[i][j] - '0';
			j++;
		}
		i++;
	}
	if (solve_it(a) == 1)
	{
		i = 0;
		while (i < 9)
		{
			j = 0;
			while (j < 9)
			{
				printf("%d ", a[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}
	}
	else
		printf("Erreur\n");
	return (0);
}
