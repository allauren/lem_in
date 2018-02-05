/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:41:12 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/01 10:04:01 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H
# include "lem_in.h"

t_path		*path_get(t_list *rooms);
void		path_runcycle(t_path *path, int nb_ant);
void		path_setup(t_path *path, int nb_ant);

void		path_print(t_list *lst);
void		path_printall(t_path *lst, t_options *s);
void		path_addend(t_path **path, t_list *new_path);
t_bool		room_lstin(t_list *lst, t_room *room);
t_bool		room_lstinpath(t_path *lst, t_room *room);
void		release_roomlst(t_list *lst);
void		release_roompath(t_path **lst);

#endif
