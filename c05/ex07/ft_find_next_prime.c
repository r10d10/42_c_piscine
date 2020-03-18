/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:57:44 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/27 00:29:08 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	while (i * i < nb)
	{
		i++;
	}
	return (i - 1);
}

int		ft_is_prime(int nb)
{
	int i;
	int s;

	if (nb <= 1)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	i = 2;
	s = ft_sqrt(nb);
	while (i <= s)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (i > s);
}

int		ft_find_next_prime(int nb)
{
	int i;

	i = 0;
	while (1)
	{
		if (ft_is_prime(nb + i))
			return (nb + i);
		i++;
	}
}
