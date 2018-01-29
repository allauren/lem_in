/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:50:17 by allauren          #+#    #+#             */
/*   Updated: 2018/01/29 18:26:45 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_is_redundant(t_room *value, t_list *list)
{
	t_room *r;

	r = NULL;
	while (list)
	{
		r = (t_room*)list->content;
		if (value->name == r->name)
			return (0);
		if (value->x == r->x && value->y == r->y)
			return (0);
		list = list->next;
	}
	return (1);
}

void	ft_fill_room(char **ptr, t_options *s, t_parse *p, t_room *value)
{
	int		i;
	t_list	*tmp;

	i = -1;
	while (ptr[++i] && !p->error)
	{
		if (i == 0)
			ft_set_name(ptr[i], s, p, &value);
		else if (i == 1)
			ft_set_xcoord(ptr[i], p, &value);
		else if (i == 2)
			ft_set_ycoord(ptr[i], p, &value);
		ft_strdel(&ptr[i]);
	}
	if (i == 3 && !s->path && ft_is_redundant(value, p->list))
	{
		if (!(tmp = ft_lstnew(value, sizeof(t_room))))
			ft_alexis_exit();
		p->type == 1 ? ft_lstadd(&p->list, tmp) :
			ft_lstaddend(&p->list, tmp);
	}
	else
		ft_errorp("Invalid room\n", p);
}

void	ft_set_name(char *ptr, t_options *s, t_parse *p, t_room **value)
{
	if (ptr[0] == 'L' || s->path)
		ft_errorp("Invalid room\n", p);
	else
		(*value)->name = ft_strdup(ptr);
}

void	ft_set_xcoord(char *ptr, t_parse *p, t_room **value)
{
	char	*inte;

	if (!(inte = ft_trim_int(ptr)))
		ft_errorp("Invalid xcoord", p);
	else
		(*value)->x = ft_atoi(inte);
	ft_strdel(&inte);
}

void	ft_set_ycoord(char *ptr, t_parse *p, t_room **value)
{
	char	*inte;

	if (!(inte = ft_trim_int(ptr)))
		ft_errorp("Invalid xcoord", p);
	else
		(*value)->y = ft_atoi(inte);
	ft_strdel(&inte);
}
