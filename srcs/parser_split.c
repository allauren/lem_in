/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:56:39 by allauren          #+#    #+#             */
/*   Updated: 2018/01/27 13:34:31 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**ft_strsplittwo(char *str, int begin, char c)
{
	char	**ptr;
	int		size1;
	int		size2;
	int		i;
	int		count;

	i = -1;
	size1 = 0;
	size2 = 0;
	count = 0;
	while (str[++i])
		if (count != begin)
		{
			if (str[i] == c)
				count++;
			if (count != begin)
					size1++;
		}
		else
			size2++;
	if (count != begin)
		return (NULL);
	if (!(ptr = ft_memalloc(sizeof(char*) * 3)))
		ft_alexis_exit();
	if (!(ptr[0] = ft_memalloc(sizeof(char) * (size1 + 1))) ||
			!(ptr[1] = ft_memalloc(sizeof(char) * (size2 + 1))))
		ft_alexis_exit();
	ptr[0] = ft_strncat(ptr[0], str, size1);
	ptr[1] = ft_strncat(ptr[1], &str[size1 + 1], size2);
	return (ptr);
}
