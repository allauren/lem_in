/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:44:02 by gsmith            #+#    #+#             */
/*   Updated: 2018/01/30 16:06:00 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

void		path_setdepth(t_room *start, int d)
{
	t_list		*neighbour;

	if (start->type != END && (start->depth > d || !(start->depth)))
	{
		start->depth = start->type == DEFAULT ? d : 0;
		neighbour = start->neighbour;
		while (neighbour)
		{
			path_setdepth(*(t_room **)(neighbour->content), d + 1);
			neighbour = neighbour->next;
		}
	}
}

int			path_claim(t_room *end, t_list **path, t_path **avoid)
{
	t_list		*neighbour;
	t_room		*tmp;
	t_room		*next;
	int			res;

	if (!(*path = ft_lstnew(&end, sizeof(t_room *))))
		ft_perror("malloc error");
	if (end->type == END)
		path_addend(avoid, *path);
	if (!(next = NULL) && end->type == START)
		return (1);
	neighbour = end->neighbour;
	while (neighbour)
	{
		tmp = *(t_room **)(neighbour->content);
		if ((tmp->type == START && (ft_lstlen((*avoid)->path) > 2
						|| !((*avoid)->next))) || (!room_lstinpath(*avoid, tmp)
					&& tmp->depth > 0 && (!next || next->depth > tmp->depth)))
			next = tmp;
		neighbour = neighbour->next;
	}
	res = !next ? 0 : path_claim(next, &((*path)->next), avoid);
	return (!res ? 0 : res + 1);
}

t_path		*path_get(t_list *rooms)
{
	t_room	*start;
	t_room	*end;
	t_list	*path;
	t_path	*path_all;
	t_path	**tail;

	start = (t_room *)(rooms->content);
	while (rooms)
	{
		end = (t_room *)(rooms->content);
		if (end->type == END)
			break ;
		rooms = rooms->next;
	}
	path_setdepth(start, 0);
	path_all = NULL;
	while (!(path = NULL) && path_claim(end, &path, &path_all))
		continue ;
	tail = &path_all;
	while (*tail && (*tail)->next)
		tail = &((*tail)->next);
	release_roompath(tail);
	if (!(*tail = NULL) && !path_all)
		ft_perror("ERROR: no path between #start and #end found.");
	return (path_all);
}
