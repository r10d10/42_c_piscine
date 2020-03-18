/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:42:44 by aollero-          #+#    #+#             */
/*   Updated: 2020/02/23 22:48:39 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include "dict.h"
#include "dict_values.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//#include "misc.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


int		ft_putstr(const char *str)
{
	t_to_print *new;
	t_to_print *tmp;

	printf("0/n");
	new = malloc(sizeof(t_to_print));
	if (NULL == new)
		return (1);
	while (*str != '\0')
	{
		new->word = str;
		new->word++;
		str++;
	}
	new->next = NULL;
	if (begin == NULL)
		begin = new;
	else
	{
		tmp = begin;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
		printf("1/n");
	

	/*while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
	ft_putchar(' ');*/
	return (0);
}
int		solutlen(int row, int col)
{
	int i;

	i = 0;
	while (dict_get(row, col) != '\0')
		i++;
	return (i);
}



int		ft_print_3d(char *number3d)
{
	if (number3d[0] <= '9' && number3d[0] > '0')
	{
		ft_putstr(dict_get(0, number3d[0] - '0'));
		ft_putstr(dict_get(2, 10));
	}
	if (number3d[1] <= '9' && number3d[1] > '0')
	{
		if (number3d[1] != '1')
			ft_putstr(dict_get(2, number3d[1] - '0'));
		else
		{
			ft_putstr(dict_get(1, number3d[2] - '0'));
		}
	}
	if (number3d[2] <= '9' && number3d[2] > '0' && number3d[1] != '1')
	{
		ft_putstr(dict_get(0, number3d[2] - '0'));
	}
	return (0);
}

void	ft_print_mill(int i, int all, char *str)
{
	if ((str[0] > '0' && str[0] <= '9') || (str[1] > '0' && str[1] <= '9')
	|| (str[2] > '0' && str[2] <= '9'))
	{
		if (all - i >= 1)
			ft_putstr(dict_get(3, (all - i - 1) / 3));
	}
	//else
		//write(1, "\b", 1);
}

int		ft_print_all(char *number_all, int i, int all)
{
	char part[3];

	printf("-1/n");
	if (i <= 0)
		return (1);
	if (i == 2)
	{
		if (number_all[0] <= '9' && number_all[0] > '0')
		{
			if (number_all[0] != '1')
				ft_putstr(dict_get(2, number_all[0] - '0'));
			else
				ft_putstr(dict_get(1, number_all[1] - '0'));
		}
		if (number_all[1] <= '9' && number_all[1] > '0' && number_all[0] != '1')
		{
			ft_putstr(dict_get(0, number_all[1] - '0'));
		}
		ft_print_mill(i, all, number_all);
		return (0);
	}
	if (i == 1)
	{
		if (number_all[0] <= '9' && number_all[0] > '0')
			ft_putstr(dict_get(0, number_all[0] - '0'));
		ft_print_mill(i, all, number_all);
		return (0);
	}
	ft_print_all (number_all, i - 3, all);
	part[0] = number_all[i - 3];
	part[1] = number_all[i - 2];
	part[2] = number_all[i - 1];
	ft_print_3d(part);
	ft_print_mill(i, all, part);
	return (0);
}

int		solve(const char *path, char *number)
{
	int i;
	//int j;

	if (0 != dict_create(path))
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	//remove spaces
	i = 0;
	while (number[i] != '\0')
		i++;
	
	if (i < 2 && number[0] == '0')
	{
		ft_putstr(dict_get(0, 0));
		return (0);
	}
	printf("beg/n");
	ft_print_all(number, i, i);
	//ft_print_3d(number);

	i = 0; //remove  zeroes at the beginning
	while (number[i] != '0')
		i++;

	

	dict_destroy();

	return 0;
}
