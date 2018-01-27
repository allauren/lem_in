/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <allauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:23:00 by allauren          #+#    #+#             */
/*   Updated: 2018/01/27 18:02:49 by allauren         ###   ########.fr       */
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
		ft_errorp("invalid number of ants\n", p);
	}
	else
	{
		f->ants = ft_atoi(ptr);
		ft_set_values(str, 1);
		ft_strdel(&ptr);
		ft_strdel(&str);
	}
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
			ft_errorp("start included just after end\n", p);
		else
		{
			p->type = 1;
			s->start = 1;
		}
	}
	else if (ft_strequ(str, "##end"))
	{
		if (s->end)
			ft_errorp("2 end included\n", p);
		else if (p->type == 1)
			ft_errorp("end included just after start\n", p);
		else
		{
			p->type = 2;
			s->end = 1;
		}
	}
}

void	ft_link(char *str, t_parse *p, t_options *s)
{
	char	**ptr;
	int		i;
	t_room	*r1;
	t_room	*r2;
	int		z;

	(void)s;
	z = 1;
	while((ptr = ft_strsplittwo(str, z, '-')))
	{
		p->error = 0;
		i = -1;
		while (ptr[++i])
		{
			if (i == 0 && !p->error)
				r1 = first_room(ptr[i], p->list, p);
			else if (i == 1 && !p->error)
				r2 = first_room(ptr[i], p->list, p);
			ft_strdel(&ptr[i]);
		}
		ft_memdel((void**)&ptr);
		if (i == 2 && !p->error && !ft_strequ(r1->name, r2->name))
		{
			ft_setlink(r1, r2, p);
			if (!p->error)
				break;
		}
		z++;
	}
	if (p->error)
		ft_errorp("invalid path\n", p);
}

void	ft_error(char *str, t_parse *p, t_options *s)
{
	ft_errorp("invalid line\n", p);
	(void)str;
	(void)s;
}
