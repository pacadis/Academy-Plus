/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acondor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:53:03 by acondor           #+#    #+#             */
/*   Updated: 2017/12/18 19:16:05 by acondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_end(const char *s)
{
	int end;

	end = 0;
	while (s[end])
		end++;
	end--;
	while ((s[end] == ' ') || (s[end] == '\n') || (s[end] == '\t'))
		end--;
	return (end);
}

static int	ft_start(const char *s)
{
	int start;

	start = 0;
	while ((s[start] == ' ') || (s[start] == '\n') || (s[start] == '\t'))
		start++;
	return (start);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		st;
	int		end;

	if (!s)
		return (NULL);
	st = ft_start(s);
	end = ft_end(s);
	if (!s[st])
		return (ft_strnew(0));
	str = ft_strnew(end - st + 1);
	if (str == NULL)
		return (NULL);
	str = ft_strsub(s, st, (end - st + 1));
	return (str);
}
