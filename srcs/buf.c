/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:52:31 by allauren          #+#    #+#             */
/*   Updated: 2018/01/27 17:57:41 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*ft_realloc(char *str, int size)
{
	char	*tmp;

	tmp = str;
	if (!(str = ft_memalloc(size + 1)))
		ft_alexis_exit();
	if (tmp)
	{
		str = ft_strcat(str, tmp);
		ft_strdel(&tmp);
	}
	return (str);
}

int			ft_set_values(char *ptr, int taille)
{
	static char	*str = NULL;
	static int	i = 1;
	int			len;

	len = str ? ft_strlen(str) : 1;
	if ((!str && taille > 0) || (i * 4096 - len < 300))
		str = ft_realloc(str, ++i * 4096);
	if (taille > 0)
	{
		ft_strcat(str, ptr);
		if (!ft_strchr(ptr, '\n'))
			ft_strcat(str, "\n");
	}
	else if (taille < 0)
		ft_strdel(&str);
	else
	{
		if(str)
		ft_printf("%s", str);
		ft_strdel(&str);
	}
	return (1);
}
