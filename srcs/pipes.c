/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:06:08 by ftholoza          #+#    #+#             */
/*   Updated: 2024/01/19 15:32:29 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open_in(char *filename)
{
	int	infd;

	infd = open(filename, O_RDWR);
	if (infd == -1)
	{
		write(2, "file_error\n", 11);
		exit(EXIT_FAILURE);
	}
	return (infd);
}

/*void	single_pipe(int argc, char **argv, char **envp)
{
	int	infd;
	int	outfd;
	int	pfd[2];
	int	pid;

	infd = ft_open_in(argv[1]);
	outfd = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	dup2(infd, 0);
	dup2(outfd, 1);
	exec(argv[2], envp);
	close(infd);
	close(outfd);
}*/

pid_t	first(char **envp, char **argv, int *pfd)
{
	int	infd;
	int	pid;

	pid = fork ();
	if (pid == 0)
	{
		infd = ft_open_in(argv[1]);
		dup2(infd, 0);
		close(infd);
		close(pfd[0]);
		dup2(pfd[1], 1);
		close(pfd[1]);
		exec(argv[2], envp);
	}
	return (pid);
}

pid_t	second(char **envp, char **argv, int *pfd)
{
	int	pid;
	int	outfd;

	pid = fork();
	if (pid == 0)
	{
		//outfd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0666);
		if (outfd == -1)
		{
			write(2, "fd error\n", 9);
			exit(EXIT_FAILURE);
		}
		close(pfd[1]);
		dup2(pfd[0], 0);
		close(pfd[0]);
		//dup2(outfd, 1);
		//close(outfd);
		exec(argv[3], envp);
	}
	return (pid);
}

void	double_pipe(int argc, char **argv, char **envp)
{
	int	infd;
	int	outfd;
	int	pfd[2];
	int	pid[2];

	pipe(pfd);
	pid[0] = first(envp, argv, pfd);
	pid[1] = second(envp, argv, pfd);
	close(pfd[1]);
	close(pfd[0]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
}

/*void	pipe_line(int argc, char **argv, char **envp)
{
	int	outfd;
	int	infd;
	int	i;

	i = 1;
	infd = open(argv[1], O_RDWR);
	dup2(infd, 0);
	while (i < argc - 2)
	{
		ft_pipe(argv[i], envp);
		i++;
	}
	//outfd = open(argv[argc -1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	//dup2(outfd, 1);
	close(outfd);
	close(infd);
	exec(argv[i], envp);
}*/
