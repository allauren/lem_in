/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_release.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:29:24 by gsmith            #+#    #+#             */
/*   Updated: 2018/01/25 17:23:47 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		release_roomlst(t_list *lst)
{
	if (lst)
	{
		release_roomlst(lst->next);
		free(lst->content);
		free(lst);
	}
}

void		release_roompath(t_path **lst)
{
	if (*lst)
	{
		release_roompath(&((*lst)->next));
		release_roomlst((*lst)->path);
		free((*lst));
		*lst = NULL;
	}
}
