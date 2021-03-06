/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fact.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:47:15 by gsmith            #+#    #+#             */
/*   Updated: 2017/11/15 18:52:45 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fact(int nb)
{
	if (nb < 0 || nb > 12)
		return (0);
	if (!nb)
		return (1);
	return (nb * ft_fact(nb - 1));
}
