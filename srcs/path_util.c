/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:55:36 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/01 10:04:02 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		path_print(t_list *lst)
{
	if (lst)
	{
		ft_printf("%s%c",
			(*(t_room **)(lst->content))->name, lst->next ? '-' : '\n');
		path_print(lst->next);
	}
}

void		path_printall(t_path *lst, t_options *s)
{
	if (lst && s->option == 2)
	{
		ft_printf("len: %-3d ant: %-3d used: %-3d path : ", ft_lstlen(lst->path)
			, lst->ant, lst->used);
		path_print(lst->path);
		path_printall(lst->next, s);
	}
	else if (lst && s->option == 1)
	{
		path_print(lst->path);
		path_printall(lst->next, s);
	}
}

void		path_addend(t_path **path, t_list *new_path)
{
	if (!path || !new_path)
		return ;
	if (*path)
		path_addend(&((*path)->next), new_path);
	else
	{
		if (!(*path = (t_path *)malloc(sizeof(t_path))))
			ft_perror("malloc error");
		(*path)->next = NULL;
		(*path)->path = new_path;
		(*path)->ant = 0;
		(*path)->used = 0;
	}
}

t_bool		room_lstin(t_list *lst, t_room *room)
{
	if (!lst)
		return (FALSE);
	if (ft_strequ((*(t_room **)(lst->content))->name, room->name))
		return (TRUE);
	return (room_lstin(lst->next, room));
}

t_bool		room_lstinpath(t_path *lst, t_room *room)
{
	if (!lst)
		return (FALSE);
	if (room_lstin(lst->path, room))
		return (TRUE);
	return (room_lstinpath(lst->next, room));
}
