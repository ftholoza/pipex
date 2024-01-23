/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:56:25 by ftholoza          #+#    #+#             */
/*   Updated: 2023/12/19 20:51:59 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr1;
	unsigned char		*ptr2;
	int					i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	ptr1 = (unsigned char *) dest;
	ptr2 = (unsigned char *) src;
	while (n > 0)
	{
		ptr1[i] = ptr2[i];
		i++;
		n--;
	}
	return (dest);
}

char	*ft_strjoin(char *rest, char *boeuf)
{
	int		restsize;
	int		boeufsize;
	char	*res;

	if (!rest)
		restsize = 0;
	else
		restsize = ft_strlen(rest);
	boeufsize = ft_strlen(boeuf);
	res = malloc(sizeof (char) * restsize + boeufsize + 1);
	if (!res)
		return (res);
	res[restsize + boeufsize] = '\0';
	ft_memcpy(res, rest, restsize);
	ft_memcpy(res + restsize, boeuf, boeufsize);
	free(rest);
	return (res);
}
