/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:54:10 by gsmith            #+#    #+#             */
/*   Updated: 2017/11/15 18:35:13 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_pow(int nb, int pow)
{
	if (pow < 0 || pow > 20)
		return (0);
	if (!pow)
		return (1);
	return (nb * ft_pow(nb, pow - 1));
}
