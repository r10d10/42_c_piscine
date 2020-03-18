/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:34:24 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/18 16:02:29 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Create a function that returns 1 if the string given as a parameter contains
** only printable characters, and 0 if it contains any other character.
*/

int		ft_str_is_printable(char *str)
{
	unsigned int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 32 && str[i] != 127))
		{
			i++;
		}
		else
		{
			return (0);
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
