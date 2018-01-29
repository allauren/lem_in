/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <allauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 09:57:14 by allauren          #+#    #+#             */
/*   Updated: 2018/01/28 03:50:34 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "path.h"

void	ft_check_option(int ac, const char **av, t_options *s)
{
	if (ac > 1)
	{
		if (!ft_strcmp(av[1], "-v"))
			s->option = 1;
		else
			ft_usage();
	}
}

int		main(int ac, const char **av)
{
	t_link		f;
	t_parse		p;
	t_options	s;
	t_path		*paths;

	ft_bzero(&f, sizeof(t_link));
	ft_bzero(&p, sizeof(t_parse));
	ft_bzero(&s, sizeof(s));
	ft_check_option(ac, av, &s);
	ft_parser(&s, &f, &p);
	// ft_print_room(p.list);
	// ft_printf("\n=== PATH - GET ===\n");
	paths = path_get(p.list);
	if (paths)
		path_setup(paths, s.ants);
	// ft_printf("\n=== PATH - PRINT ===\n");
	 //path_printall(paths);
	// ft_printf("\n=== PATH - RUN ===\n");
	if (paths)
		while ((*(t_room **)(paths->path->content))->ant != s.ants)
			path_runcycle(paths, s.ants);
	ft_putendl("");
	// ft_printf("\n=== PATH - RELEASE ===\n");
	release_roompath(&paths);
	ft_room_del(p.list);
	return (0);
}
