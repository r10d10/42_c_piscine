/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartin <omartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 12:30:18 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/08 17:22:55 by omartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

void		ft_horizontal(int x1, char a, char b, char c)
{
	int i;

	i = 0;
	while (i < x1)
	{
		if (i == 0)
		{
			ft_putchar(a);
		}
		else if (i > 0 && i < x1 - 1)
		{
			ft_putchar(b);
		}
		else if (i == x1 - 1)
		{
			ft_putchar(c);
		}
		i++;
	}
	ft_putchar('\n');
}

void		ft_vertical(int x2)
{
	int i;

	i = 0;
	while (i < x2)
	{
		if ((i == 0) || (i == x2 - 1))
		{
			ft_putchar('B');
		}
		else
		{
			ft_putchar(' ');
		}
		i++;
	}
	ft_putchar('\n');
}

void		rush(int x, int y)
{
	int i;

	if ((x > 0) && (y > 0))
	{
		ft_horizontal(x, 'A', 'B', 'C');
		if (y > 2)
		{
			i = 0;
			while (i < y - 2)
			{
				ft_vertical(x);
				i++;
			}
		}
		if (y > 1)
		{
			ft_horizontal(x, 'C', 'B', 'A');
		}
	}
}
