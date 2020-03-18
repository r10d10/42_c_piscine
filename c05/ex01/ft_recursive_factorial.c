/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:05:33 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/24 00:12:21 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		recurs(int nb, int result)
{
	if (nb <= 1)
		return (result);
	else
		result = recurs(nb - 1, result) * nb;
	return (result);
}

int		ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	return (recurs(nb, 1));
}
