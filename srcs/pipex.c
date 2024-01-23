/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:55:05 by ftholoza          #+#    #+#             */
/*   Updated: 2024/01/02 19:08:04 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *cmd, char **envp)
{
	char	**args;
	char	**paths;
	int		i;
	int		control;

	i = 0;
	control = 0;
	paths = get_paths(envp, cmd);
	args = ft_split(cmd, ' ');
	while (paths[i] != NULL)
	{
		if (execve(paths[i], args, envp) == 1)
			control = 1;
		i++;
	}
	free_tab(args);
	free_tab(paths);
	if (control == 0)
	{
		write(2, "command not found\n", 18);
		exit(EXIT_FAILURE);
	}
}

int	ft_fork(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		write(2, "fork_error", 10);
		exit(EXIT_FAILURE);
	}
	return (pid);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
	{
		ft_putstr_fd("infile.txt cmd1 ... outfile.txt\n", 2);
		exit(EXIT_FAILURE);
	}
	if (argc == 5)
		double_pipe(argc, argv, envp);
	if (argc > 5)
		ft_putstr_fd("pipeline not possible\n", 2);
	exit(EXIT_SUCCESS);
}
