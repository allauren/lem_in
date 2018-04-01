/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <allauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 11:42:56 by allauren          #+#    #+#             */
/*   Updated: 2018/04/01 18:42:40 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*first_room(char *str, t_list *list, t_parse *p)
{
	t_room *value;

	if (!list)
	{
		p->error = 1;
		return (NULL);
	}
	value = (t_room*)(list->content);
	return (ft_strequ(str, value->name) ? value
			: first_room(str, list->next, p));
}

t_room		*double_room(char *str, t_list *list)
{
	t_room *value;

	if (!list)
		return (NULL);
	value = *(t_room**)(list->content);
	return (ft_strequ(str, value->name) ? value
			: double_room(str, list->next));
}

void		ft_setlink(t_room *r1, t_room *r2, t_parse *p, t_options *s)
{
	t_list	*tmp;

	if (!(double_room(r2->name, r1->neighbour)))
	{
		if (!(tmp = ft_lstnew(&r2, sizeof(t_room*))))
			ft_alexis_exit();
		ft_lstadd(&(r1->neighbour), tmp);
		if (!(tmp = ft_lstnew(&r1, sizeof(t_room*))))
			ft_alexis_exit();
		ft_lstadd(&(r2->neighbour), tmp);
		s->path = 1;
	}
	(void)p;
}
