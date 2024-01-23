/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:24:28 by ftholoza          #+#    #+#             */
/*   Updated: 2023/11/19 16:06:26 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static void	ft_free_all(char **res, int nstring)
{
	while (nstring != 0)
	{
		free(res[nstring]);
		nstring--;
	}
	free(res);
}

static void	ft_malloc_c(unsigned char *s, int cw, char c, char **res)
{
	int				nstring;
	int				i;
	int				charc;

	charc = 0;
	nstring = 0;
	i = 0;
	while (nstring < cw)
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			charc++;
			i++;
		}
		res[nstring] = malloc(sizeof(char) * (charc + 1));
		if (!res)
			ft_free_all(res, nstring);
		res[nstring][charc] = '\0';
		charc = 0;
		nstring++;
	}
}

static void	ft_fill_tab(char **res, unsigned char *s, char c, int cw)
{
	int	nstring;
	int	indextab;
	int	i;

	nstring = 0;
	indextab = 0;
	i = 0;
	while (nstring < cw)
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			res[nstring][indextab] = s[i];
			i++;
			indextab++;
		}
		nstring++;
		indextab = 0;
	}
	(res[nstring]) = NULL;
}

char	**ft_split(char const *s, char c)
{
	int				i;
	int				cw;
	char			**res;
	unsigned char	*ptr;

	i = 0;
	cw = 0;
	if (!s)
		return (NULL);
	ptr = (unsigned char *) s;
	while (ptr[i])
	{
		while (ptr[i] == c)
			i++;
		if (ptr[i] != c && ptr[i])
			cw++;
		while (ptr[i] != c && ptr[i])
			i++;
	}
	res = malloc(sizeof(char *) * (cw + 1));
	if (!res)
		return (NULL);
	ft_malloc_c(ptr, cw, c, res);
	ft_fill_tab(res, ptr, c, cw);
	return (res);
}

/*#include <stdio.h>

int	main(int argc, char **argv)
{
	int	nstring;
	int	i;
	int	cw;
	char	**res;
	char	*ptr;

	nstring = 0;
	i = 0;
	cw = 0;
	const char *test = argv[1];
	ptr = (char *) test;
	char c = ' ';
	res = ft_split(test, c);
	while (ptr[i])
	{
		while (ptr[i] == c && ptr[i])
			i++;
		if (ptr[i] != c && ptr[i])
			cw++;
		while (ptr[i] != c && ptr[i])
			i++;
	}
	printf("%d\n", cw);*/
	/*while (nstring <  5)
	{
		printf("%s\n", res[nstring]);
		nstring++;
	}
	ft_free_all(res, nstring);
}*/
