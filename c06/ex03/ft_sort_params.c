/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 00:34:13 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/27 01:28:14 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	int i;
	int r;

	i = 0;
	r = 0;
	while (1)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (r);
		if (s1[i] == s2[i])
			i++;
		else
		{
			r = (int)(s1[i] - s2[i]);
			return (r);
		}
	}
}

void	ft_swap(char **s1, char **s2)
{
	char *t;

	t = *s1;
	*s1 = *s2;
	*s2 = t;
}

void	ft_print(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (argc > i)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

int		main(int argc, char **argv)
{
	int i;
	int swaped;

	swaped = 1;
	while (swaped == 1)
	{
		swaped = 0;
		i = 1;
		while (argc - 1 > i)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				swaped = 1;
				ft_swap(&argv[i], &argv[i + 1]);
			}
			i++;
		}
	}
	ft_print(argc, argv);
}
