/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:05:33 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/23 18:11:47 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;
	int result;

	if (nb < 0)
		return (0);
	i = 1;
	result = 1;
	while (i < nb + 1)
	{
		result *= i;
		i++;
	}
	return (result);
}
