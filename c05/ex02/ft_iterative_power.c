/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:05:33 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/24 00:28:57 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int i;
	int result;

	if (power < 0)
		return (0);
	if ((power == 0) && (nb == 0))
		return (1);
	i = 1;
	result = 1;
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}
