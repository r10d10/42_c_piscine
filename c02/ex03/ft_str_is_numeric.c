/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:34:24 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/18 13:40:54 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Create a function that returns 1 if the string given as a parameter contains
** only lowercase alphabetical characters, and 0 if it contains any other
** character.
*/

int		ft_str_is_numeric(char *str)
{
	unsigned int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9'))
		{
			return (0);
		}
		else
		{
			i++;
		}
	}
	if (i == 0)
	{
		return (1);
	}
	else
	{
		return (1);
	}
}
