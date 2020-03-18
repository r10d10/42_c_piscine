/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:34:24 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/18 16:03:59 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Create a function that transforms every letter to uppercase.
*/

char	*ft_strupcase(char *str)
{
	unsigned int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] = str[i] - 'a' + 'A';
		}
		i++;
	}
	return (str);
}
