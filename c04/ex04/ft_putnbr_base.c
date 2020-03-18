/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:44:13 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/23 18:46:40 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_checks(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = 0;
		while (base[j] != '\0')
		{
			if ((base[j] == base[i]) && (i != j))
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int i;

	i = ft_checks(base);
	if (i <= 1)
		return ;
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
	}
	if (nbr >= i)
	{
		ft_putnbr_base(nbr / i, base);
		ft_putchar(base[nbr % i]);
		nbr = nbr / i;
	}
	else
	{
		if ((nbr >= 0) && (nbr < i))
		{
			ft_putchar(base[nbr]);
		}
	}
}
