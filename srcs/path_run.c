/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:45:46 by gsmith            #+#    #+#             */
/*   Updated: 2018/01/26 14:06:00 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#include "path.h"

static int	path_dup(t_path *src, t_path **dst)
{
	*dst = NULL;
	if (!src)
		return (0);
	if (src->used)
	{
		if (!(*dst = (t_path *)malloc(sizeof(t_path))))
			ft_perror("malloc error");
		(*dst)->path = src->path;
		while ((*dst)->path && (*dst)->path->next
			&& !((*(t_room **)((*dst)->path->next->content))->ant))
			(*dst)->path = (*dst)->path->next;
		(*dst)->ant = src->used > src->ant ? src->ant : src->used;
		(*dst)->used = src->used;
		src->used = src->used - 1;
		return (1 + path_dup(src->next, &((*dst)->next)));
	}
	return (path_dup(src->next, dst));
}

void		path_setup(t_path *path, int nb_ant)
{
	t_path		*cur;

	cur = path;
	while (cur && cur->used)
		if (cur->next && ((cur->next->used && cur->used >= cur->next->used)
				|| (!(cur->next->used)
					&& cur->used >= ft_lstlen(cur->next->path) - 2)))
			cur = cur->next;
		else
			break ;
	if (!(cur->next))
		cur = ((cur->used && path->used >= cur->used)
				|| (!(cur->used) && path->used >= ft_lstlen(cur->path) - 2))
			? cur : path;
	cur->ant++;
	cur->used = !(cur->used) ? ft_lstlen(cur->path) - 1 : cur->used + 1;
	if (nb_ant > 1)
		path_setup(path, nb_ant - 1);
}

t_bool		path_runlink(t_list *lst, int nb_ant, t_bool first)
{
	t_room	*current;
	t_room	*prev;
	int		ant;

	if (lst && lst->next)
	{
		current = *(t_room **)(lst->content);
		prev = *(t_room **)(lst->next->content);
		if (prev->ant && (current->type == END || !(current->ant)))
		{
			ant = prev->type == START ? nb_ant - prev->ant + 1 : prev->ant;
			current->ant = current->type == END ? current->ant + 1 : ant;
			prev->ant = prev->type == START ? prev->ant - 1 : 0;
			ft_printf("%cL%d-%s", first ? '\n' : ' ', ant, current->name);
			return (TRUE);
		}
	}
	return (FALSE);
}

void		path_runcycle(t_path *paths, int nb_ant)
{
	t_path		*tmp;
	int			nb_path;
	t_bool		last;
	t_bool		first;

	nb_path = path_dup(paths, &tmp);
	first = TRUE;
	paths = tmp;
	while (nb_path)
	{
		tmp = paths;
		while (tmp)
		{
			last = tmp->ant ? path_runlink(tmp->path, nb_ant, first) : FALSE;
			first = first && !last ? TRUE : FALSE;
			tmp->ant = last ? tmp->ant - 1 : tmp->ant;
			nb_path = tmp->path && !(tmp->path->next) ? nb_path - 1 : nb_path;
			tmp->path = tmp->path ? tmp->path->next : NULL;
			tmp = tmp->next;
		}
	}
	release_roompath(&paths);
}
