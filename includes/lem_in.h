/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <allauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 09:58:36 by allauren          #+#    #+#             */
/*   Updated: 2018/02/01 16:36:00 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdlib.h>
# include <stdbool.h>
# include "libft_adv.h"

typedef struct		s_options
{
	char	*str;
	int		option;
	int		start;
	int		ants;
	int		end;
	int		init;
	int		path;
	int		command;
}					t_options;
typedef enum		e_rtype
{
	DEFAULT,
	START,
	END
}					t_rtype;

typedef struct		s_spit
{
	char	**ptr;
	int		size1;
	int		size2;
	int		i;
	int		count;
}					t_spit;

typedef struct		s_room
{
	t_rtype			type;
	int				x;
	int				y;
	char			*name;
	int				ant;
	int				depth;
	t_list			*neighbour;
}					t_room;

typedef struct		s_link
{
	char			*room;
	struct s_link	*next;
}					t_link;

typedef struct		s_parse
{
	char		*name;
	int			error;
	t_rtype		type;
	t_list		*list;
}					t_parse;

typedef struct		s_path
{
	int				ant;
	int				used;
	t_list			*path;
	struct s_path	*next;
}					t_path;

typedef struct		s_norm
{
	char	**ptr;
	int		i;
	t_room	*r1;
	t_room	*r2;
	int		z;
}					t_norm;

/*
** Usage functions
*/
void				ft_usage(void);
/*
** Parsing functions
*/
void				ft_parser(t_options *s, t_link *f, t_parse *p);
void				ft_comment(char *str, t_parse *p, t_options *s);
void				ft_room(char *str, t_parse *p, t_options *s);
void				ft_is_first(char *str, t_options *f, t_parse *p);
void				ft_link(char *str, t_parse *p, t_options *s);
void				ft_error(char *str, t_parse *p, t_options *s);
/*
** utils functions
*/
char				*ft_trim_int(const char *str);
/*
** path functions
*/
void				ft_setlink(t_room *r1, t_room *r, t_parse *p, t_options *s);
t_room				*first_room(char *str, t_list *list, t_parse *p);
char				**ft_strsplittwo(char *str, int begin, char c);
/*
** room functions
*/
void				ft_set_xcoord(char *ptr, t_parse *p, t_room **value);
void				ft_set_name(char *ptr, t_options *s, t_parse *p
						, t_room **value);
void				ft_set_ycoord(char *ptr, t_parse *p, t_room **value);
int					ft_is_redundant(t_room *value, t_list *list);
void				ft_fill_room(char **ptr, t_options *s, t_parse *p
						, t_room *value);
/*
** exit functions
*/
void				ft_alexis_exit(void);
void				ft_forgot_option(void);
void				ft_usage(void);
void				ft_errorp(char *str, t_parse *p);
/*
**	print functions
*/
void				ft_set_values(char *ptr, int taille);
/*
** fonctions de lem_in
*/
void				ft_room_del(t_list *list);
void				ft_lstroomdel(t_list *list);
void				ft_room_add(t_room **r, t_room *value);
/*
** print functions
*/
void				ft_print_link(t_list *l);
void				ft_print_room(t_list *r);

#endif
