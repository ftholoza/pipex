/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:06:35 by ftholoza          #+#    #+#             */
/*   Updated: 2023/12/21 14:10:36 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct t_data
{
	char	**cmd;
}	t_data;

void		ft_putstr_fd(char *s, int fd);
void		*ft_memset(void *s, int c, size_t n);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s);
void		free_tab(char **tab);
char		**get_paths(char **envp, char *cmd);
void		single_pipe(int argc, char **argv, char **envp);
void		exec(char *cmd, char **envp);
int			ft_fork(void);
void		double_pipe(int argc, char **argv, char **envp);
int			ft_open_in(char *filename);

#endif