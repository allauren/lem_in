/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:52:31 by allauren          #+#    #+#             */
/*   Updated: 2018/02/01 17:26:37 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <unistd.h>

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

void		ft_set_values(char *ptr, int taille)
{
	static char	*str = NULL;
	static int	i = 0;
	int			len;
	char		*sptr;

	len = str ? ft_strlen(str) : 1;
	while ((!str && taille > 0) || (i * 4096 - len < 500))
		str = ft_realloc(str, ++i * 4096);
	if (taille > 0)
	{
		if (taille == 2 && ft_strcat(str, "ERROR line ")
				&& ft_strcat(str, (sptr = ft_itoa(i))) && ft_strcat(str, " : "))
			ft_strdel(&sptr);
		ft_strcat(str, ptr);
		if (++i && !ft_strchr(ptr, '\n'))
			ft_strcat(str, "\n");
	}
	else
	{
		if (str && taille == 0)
			ft_printf("%s", str);
		ft_strdel(&str);
	}
}
