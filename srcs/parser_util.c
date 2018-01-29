/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <allauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:23:00 by allauren          #+#    #+#             */
/*   Updated: 2018/01/29 18:26:19 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_is_first(char *str, t_options *f, t_parse *p)
{
	char		*ptr;

	if (!(ptr = ft_trim_int(str)))
	{
		ft_strdel(&str);
		ft_strdel(&ptr);
		ft_errorp("Invalid number of ants\n", p);
	}
	else if (ft_atoi(ptr) > 0)
	{
		f->ants = ft_atoi(ptr);
		ft_set_values(str, 1);
		ft_strdel(&ptr);
		ft_strdel(&str);
	}
	else
		ft_errorp("Invalid number of ants\n", p);
}

void	ft_room(char *str, t_parse *p, t_options *s)
{
	t_room	*value;
	char	**ptr;

	if (!(ptr = ft_strsplit(str, ' ')))
		ft_alexis_exit();
	if (!(value = malloc(sizeof(t_room))))
		ft_alexis_exit();
	ft_bzero(value, sizeof(t_room));
	value->type = p->type;
	if (p->type == 1)
		value->ant = s->ants;
	value->depth = 0;
	ft_fill_room(ptr, s, p, value);
	p->type = 0;
	ft_memdel((void**)&ptr);
	ft_memdel((void**)&value);
}

void	ft_comment(char *str, t_parse *p, t_options *s)
{
	if (ft_strequ(str, "##start"))
	{
		if (s->start)
			ft_errorp("2 starts included\n", p);
		else if (p->type == 2)
			ft_errorp("Start included just after end\n", p);
		else
		{
			p->type = 1;
			s->start = 1;
		}
	}
	else if (ft_strequ(str, "##end"))
	{
		if (s->end)
			ft_errorp("2 ends included\n", p);
		else if (p->type == 1)
			ft_errorp("End included just after start\n", p);
		else
		{
			p->type = 2;
			s->end = 1;
		}
	}
}

void	ft_link(char *str, t_parse *p, t_options *s)
{
	t_norm	n;

	n.z = 0;
	while (++n.z && (n.ptr = ft_strsplittwo(str, n.z, '-')))
	{
		p->error = 0;
		n.i = -1;
		while (n.ptr[++n.i] && (s->path = 1))
		{
			if (n.i == 0 && !p->error)
				n.r1 = first_room(n.ptr[n.i], p->list, p);
			else if (n.i == 1 && !p->error)
				n.r2 = first_room(n.ptr[n.i], p->list, p);
			ft_strdel(&n.ptr[n.i]);
		}
		ft_memdel((void**)&n.ptr);
		if (n.i == 2 && !p->error && !ft_strequ(n.r1->name, n.r2->name))
		{
			ft_setlink(n.r1, n.r2, p);
			if (!p->error)
				break ;
		}
	}
	if (p->error)
		ft_errorp("Invalid path\n", p);
}

void	ft_error(char *str, t_parse *p, t_options *s)
{
	ft_errorp("Invalid line\n", p);
	(void)str;
	(void)s;
}
