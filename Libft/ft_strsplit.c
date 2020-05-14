/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acondor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 21:07:50 by acondor           #+#    #+#             */
/*   Updated: 2017/12/17 22:14:21 by acondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordlen(char const *str, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (*(str + i) == c)
		i++;
	while (*(str + i) != c && *(str + i) != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static int	ft_count(char const *str, char c)
{
	int cnt;
	int i;

	i = 0;
	cnt = 0;
	while (*(str + i))
	{
		while (*(str + i) == c)
			i++;
		if (*(str + i) != c && *(str + i) != '\0')
			cnt++;
		while (*(str + i) != c && *(str + i) != '\0')
			i++;
	}
	return (cnt);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**strc;

	if (!s || !(strc = (char **)
			malloc(sizeof(char *) * (ft_count(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_count(s, c))
	{
		k = 0;
		if (!(strc[i] = ft_strnew(wordlen(&s[j], c) + 1)))
			strc[i] = NULL;
		while (*(s + j) == c)
			j++;
		while (*(s + j) != c && *(s + j))
			strc[i][k++] = s[j++];
		strc[i++][k] = '\0';
	}
	strc[i] = 0;
	return (strc);
}
