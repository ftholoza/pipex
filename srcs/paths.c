/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:57:00 by ftholoza          #+#    #+#             */
/*   Updated: 2023/12/20 20:42:38 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	find_paths(char **envp)
{
	int	nstring;

	nstring = 0;
	while (envp[nstring] != NULL)
	{
		if (ft_strncmp("PATH=", envp[nstring], 5) == 0)
			return (nstring);
		nstring++;
	}
	return (0);
}

static char	*format_cmd(char *cmd)
{
	int		i;
	char	*res;

	i = 0;
	while (cmd[i] && cmd[i] != ' ')
		i++;
	res = ft_substr(cmd, 0, i);
	return (res);
}

static char	**add_to_paths(char **mypaths, char *formated_cmd)
{
	int		i;
	char	*new_paths;
	char	*temp;
	char	**res;

	i = 0;
	new_paths = NULL;
	while (mypaths[i] != NULL)
	{
		new_paths = ft_strjoin(new_paths, mypaths[i]);
		new_paths = ft_strjoin(new_paths, "/");
		new_paths = ft_strjoin(new_paths, formated_cmd);
		new_paths = ft_strjoin(new_paths, " ");
		i++;
	}
	free(formated_cmd);
	res = ft_split(new_paths, ' ');
	free_tab(mypaths);
	free(new_paths);
	return (res);
}

char	**get_paths(char **envp, char *cmd)
{
	char	*paths;
	char	**mypaths;
	char	*formated_cmd;
	int		line;

	line = find_paths(envp);
	paths = ft_substr(envp[line], 5, ft_strlen(envp[line]));
	mypaths = ft_split(paths, ':');
	formated_cmd = format_cmd(cmd);
	mypaths = add_to_paths(mypaths, formated_cmd);
	free(paths);
	return (mypaths);
}
