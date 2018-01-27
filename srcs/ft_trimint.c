/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <allauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:38:03 by allauren          #+#    #+#             */
/*   Updated: 2018/01/14 14:07:50 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_is_intvalid(char **str)
{
	unsigned int	i;
	int				signe;

	signe = 0;
	i = -1;
	while ((*str)[++i])
	{
		if (!((*str)[i] >= '0' && (*str)[i] <= '9'))
		{
			if (!signe && ((*str)[i] == '+' || (*str)[i] == '-'))
				signe++;
			else
			{
				ft_strdel(&(*str));
				return (0);
			}
		}
	}
	return (1);
}

char	*ft_trim_int(const char *str)
{
	int		i;
	int		signe;
	int		len;
	char	*ret;
	int		t;

	signe = 0;
	if (((i = 0) + 1) && !str)
		return (NULL);
	if ((t = -1) && (str[i] == '-' || str[i] == '+'))
		signe = 1;
	i = signe;
	while (str[i] == '0' && str[i + 1])
		i++;
	if ((len = ft_strlen(&str[i]) > 10) || (ft_atol(&str[i]) > 2147483647
				&& !signe) || (ft_atol(&str[i]) > 2147483648 && signe))
		return (NULL);
	if (!(ret = ft_memalloc(sizeof(char*) * (len + signe + 1))))
		ft_alexis_exit();
	if (signe && ft_atoi(&str[i]))
		ret[++t] = str[0];
	while (str[i])
		ret[++t] = str[i++];
	ret[t + 1] = '\0';
	return (ft_is_intvalid(&ret) ? ret : NULL);
}
