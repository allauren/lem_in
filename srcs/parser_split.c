/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:56:39 by allauren          #+#    #+#             */
/*   Updated: 2018/01/29 17:13:19 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**ft_strsplittwo(char *str, int begin, char c)
{
	t_spit	s;

	ft_bzero(&s, sizeof(t_spit));
	s.i = -1;
	while (str[++s.i])
		if (s.count != begin)
		{
			if (str[s.i] == c)
				s.count++;
			if (s.count != begin)
				s.size1++;
		}
		else
			s.size2++;
	if (s.count != begin)
		return (NULL);
	if (!(s.ptr = ft_memalloc(sizeof(char*) * 3)))
		ft_alexis_exit();
	if (!(s.ptr[0] = ft_memalloc(sizeof(char) * (s.size1 + 1))) ||
			!(s.ptr[1] = ft_memalloc(sizeof(char) * (s.size2 + 1))))
		ft_alexis_exit();
	s.ptr[0] = ft_strncat(s.ptr[0], str, s.size1);
	s.ptr[1] = ft_strncat(s.ptr[1], &str[s.size1 + 1], s.size2);
	return (s.ptr);
}
