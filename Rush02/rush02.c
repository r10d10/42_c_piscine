/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:46:23 by aollero-          #+#    #+#             */
/*   Updated: 2020/02/23 22:47:03 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
//#include "misc.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_print(const char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

void	print_linked_list(void)
{
	t_to_print *current;
	
	printf("good/n");
	current  = NULL;
	while (current->next != NULL)
	{
		ft_print(current->word);
		current = current->next;
		ft_putchar(' ');
	}
	ft_print(current->word);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*zero_clean(char *str)
{
	int i;
	int j;
	char mat[ft_strlen(str)];
	char *aux;

	aux = mat;
	i = 0;
	j = 0;
	while (str[i] == '0')
		i++;
	while (str[i] != '\0')
	{
		aux[j] = str[i];
		i++;
		j++;
	}
	aux[j] ='\0';
	return (ft_strcpy(str, aux));
}

void ft_free_all(void)
{
	
}

int main(int argc, char *argv[])
{
	if (argc != 2 && argc !=3)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	printf("-112/n");
	if (argc == 2)
	{
		argv[1] = zero_clean (argv[1]);
		solve("numbers.dict",argv[1]);
	}
	else
	{
		argv[1] = zero_clean (argv[1]);
		solve(argv[1], argv[2]);
	}
	print_linked_list ();
	ft_free_all();
	//printf("\b\n");

	//else */
	//solve("numbers.dict", "*argv[]");


	//solve("numbers.dict", "000001");
	return (0);
}
