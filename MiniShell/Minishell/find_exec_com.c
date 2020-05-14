/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_exec_com.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:32:24 by frosu             #+#    #+#             */
/*   Updated: 2017/07/19 11:32:25 by frosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*fuck(char *s, char *com, int from, int to)
{
	char	*str;
	char	*fin;
	int		i;

	i = 0;
	str = (char*)malloc(sizeof(char*) * (to - from + 2));
	while (from < to && s[from] != ':')
	{
		str[i] = s[from];
		from++;
		i++;
	}
	str[i] = '\0';
	fin = ft_strjoin(str, "/");
	free(str);
	str = ft_strjoin(fin, com);
	free(fin);
	return (str);
}

void	no_space(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			ft_strcpy(s + i, s + i + 1);
		else
			i++;
	}
}

int		try_exec(char **cunt, char **envp, char *str)
{
	int error;

	error = 0;
	no_space(str);
	execve(str, cunt, envp);
	error = errno;
	free(str);
	str = NULL;
	return (error);
}

void	execve_path(char **cunt, char **envp, char *com)
{
	int i;
	int j;
	int pos;
	char *s;

	pos = get_pos(envp, "PATH");
	i = 5;
	preliminary_tests(envp);
	while (envp[pos][i] && envp[pos][i] != '\n')
	{
		j = i;
		while (envp[pos][j] && envp[pos][j] != ':' && envp[pos][j] != '\n')
			j++;
		j++;
		s = fuck(envp[pos], com, i, j);
		if (try_exec(cunt, envp, s) == 0)
			return ;
		// free(s);
		i = j;
	}
	if (execve(com, cunt, envp))
	{
		ft_putstr("zhs: command not found: ");
		ft_putstr(com);
		ft_putchar('\n');
		return ;
	}
}

void	free_the_matrix(char **av)
{
	int i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

int is_null_cmd(char *s)
{
	int i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	return ((s[i] == '\0') ? 1 : 0);
}

void	trim_and_change_tabs(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\t')
			s[i] = ' ';
		i++;
	}
	ft_trim(s);
}

void	find_exec_com(char **envp, char *command)
{
	char **cunt;
	// char *str;
	char *exec;

	trim_and_change_tabs(command);
	cunt = ft_strsplit(command, ' ');
	// str = ft_strjoin("/bin/", cunt[0]);
	if (is_null_cmd(command))
		return ;
	if (!ft_strcmp(command, "env"))
		envp_print(envp);
	else if (!ft_strncmp("cd", command, 2))
		ft_cd(envp, command, cunt);
	else if (!ft_strncmp("setenv", command, 6))
		set_env(envp, command);
	else if (!ft_strncmp("unsetenv", command, 8))
		unset_env(envp, command);
	else if (!ft_strncmp("echo", command, 4))
		hand_echo(envp, command);
	else if (ft_strncmp("echo", command, 4))
	{
		exec = gimme_comish(command);
		execve_path(cunt, envp, exec);
		free(exec);
	}
	free_the_matrix(cunt);
}