/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <allauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 09:57:14 by allauren          #+#    #+#             */
/*   Updated: 2018/02/01 16:16:45 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "path.h"

void	ft_check_option(int ac, const char **av, t_options *s)
{
	if (ac > 1)
	{
		if (!ft_strcmp(av[1], "-vf"))
			s->option = 2;
		else if (!ft_strcmp(av[1], "-v"))
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
	paths = path_get(p.list);
	if (paths && s.ants > 0)
	{
		path_setup(paths, s.ants);
		if (s.option && ft_printf("\n"))
			path_printall(paths, &s);
		while ((*(t_room **)(paths->path->content))->ant != s.ants)
			path_runcycle(paths, s.ants);
		ft_putendl("");
	}
	if (s.option == 2 && ft_printf("\n"))
		path_printall(paths, &s);
	release_roompath(&paths);
	ft_room_del(p.list);
	return (0);
}
