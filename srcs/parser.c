/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <allauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 10:35:57 by allauren          #+#    #+#             */
/*   Updated: 2018/01/28 03:56:20 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_count_space(char *str)
{
	int		i;
	int		space;

	space = 0;
	i = -1;
	while (str[++i])
	{
		if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		{
			while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
				i++;
			if (str[i])
				space++;
		}
	}
	if (space == 2 || (space == 0 && ft_strchr(str, '-')))
		return (space);
	return (-1);
}

void	ft_select_error(t_parse *p, t_options *s)
{
	if (!s->path && !p->error)
		ft_perror("no path written\n");
	else if (!p->list && !p->error)
		ft_perror("no room written\n");
	else if (!s->start && !p->error)
		ft_perror("no start written\n");
	else if (!s->end && !p->error)
		ft_perror("no end written\n");
}

int		ft_smart_pars(char *str, t_parse *p, t_options *s)
{
	int		space;

	space = 0;
	if (p->error)
		return (0);
	else if (str[0] == '#')
		return (1);
	else if ((space = ft_count_space(str)) == 2)
		return (2);
	else if (space == 0 && (s->path = 1))
		return (3);
	return (0);
}

void	ft_init_ants(char *str, t_options *s, t_parse *p)
{
	while (get_next_line(0, &str) && str[0] == '#')
	{
		ft_comment(str, p, s);
		if (s->start || s->end)
			ft_errorp("Invalid number of ants\n", p);
		if (!p->error)
			ft_set_values(str, 1);
		ft_strdel(&str);
	}
	if (!p->error)
		ft_is_first(str, s, p);
	if (p->error)
	{
		ft_errorp(NULL, NULL);
		ft_set_values(NULL, 0);
		exit(1);
	}
}

void	ft_parser(t_options *s, t_link *f, t_parse *p)
{
	static void (*tab[4])(char*, t_parse*, t_options*) = {ft_error, ft_comment,
		ft_room, ft_link};

	(void)f;
	ft_init_ants(s->str, s, p);
	while (!p->error && get_next_line(0, &s->str))
	{
		tab[(s->init = ft_smart_pars(s->str, p, s))](s->str, p, s);
		if (!p->error)
			ft_set_values(s->str, 1);
		ft_strdel(&s->str);
	}
	ft_strdel(&(s->str));
	ft_errorp(NULL, NULL);
	ft_set_values(NULL, 0);
	if (!p->error)
		ft_select_error(p, s);
}
