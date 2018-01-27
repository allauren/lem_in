/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <allauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:46:35 by allauren          #+#    #+#             */
/*   Updated: 2018/01/18 15:06:56 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_print_n(t_list *elem)
{
	ft_printf("\t%s adresse neighbour %p\n",
			((t_room*)(*((t_room**)(elem->content))))->name
			, ((t_room*)(*((t_room**)(elem->content)))));
}

void		ft_print_room(t_list *l)
{
	t_room *r;

	if (l)
	{
		r = (t_room*)l->content;
		ft_printf("dans print %p\n", r);
		ft_printf("{\nNAME :%s\n xcoord :%d et y coord:%d\ntype %d\n}\n"
				, r->name, r->x, r->y, r->type);
		if (r->neighbour)
			ft_putendl("neighbour:");
		ft_lstiter(r->neighbour, &ft_print_n);
		ft_print_room(l->next);
	}
}

void		ft_print_link(t_list *l)
{
	t_room **r;

	if (l)
	{
		r = (t_room**)l->content;
		ft_printf("dans path %p\n", (*r));
		ft_printf("{\nNAME :%s\n xcoord :%d et y coord:%d \
				et neighbour %p\ntype%d\n}\n"
				, (*r)->name, (*r)->x, (*r)->y, (*r)->type);
		ft_print_room(l->next);
	}
}

void		ft_del_neighbour(t_list *list)
{
	if (!list)
		return ;
	ft_del_neighbour(list->next);
	ft_memdel((void**)&list->content);
	ft_memdel((void**)&list);
}

void		ft_room_del(t_list *list)
{
	t_list	*tmp;

	while ((tmp = list))
	{
		list = list->next;
		ft_del_neighbour(((t_room*)tmp->content)->neighbour);
		ft_memdel((void**)&((t_room *)(tmp->content))->name);
		ft_memdel((void**)&tmp->content);
		ft_memdel((void**)&tmp);
	}
}
