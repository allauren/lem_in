/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <allauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 10:18:26 by allauren          #+#    #+#             */
/*   Updated: 2018/01/30 12:07:15 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_usage(void)
{
	ft_printf("usage : ./lem_in and valid map\n");
	exit(-1);
}

void	ft_alexis(void)
{
	ft_putstr("Ceux qui vivent, ce sont ceux qui luttent ; ce sont\
	\nceux dont un dessein ferme emplit l ame et le front\
	\nCeux qui d un haut destin gravissent l apre cime\
	\nCeux qui marchent pensifs, epris d un but sublime\n");
}

void	ft_alexis_exit(void)
{
	ft_alexis();
	exit(-1);
}

void	ft_forgot_option(void)
{
	ft_printf("usage : ./lem_in -v and valid map\n");
	exit(-1);
}

void	ft_errorp(char *str, t_parse *p)
{
	static char	*keep = NULL;

	if (str)
	{
		keep = ft_strdup(str);
		p->error = 1;
	}
	else if (keep)
	{
		ft_set_values(keep, 2);
		ft_strdel(&keep);
	}
}
