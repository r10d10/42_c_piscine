/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:34:24 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/19 16:41:02 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Create a function that capitalizes the first letter of each word and
** transforms all other letters to lowercase.
** A word is a string of alphanumeric character
*/

void	ft_prev(char *str, int i)
{
	int				prev;

	prev = 0;
	if (!((str[i] >= 'a' && str[i] <= 'z') ||
	(str[i] >= 'A' && str[i] <= 'Z')))
		prev = 1;
	if ((str[i - 1] >= '0' && str[i - 1] <= '9') || (str[i - 1] >= 'A'
	&& str[i - 1] <= 'Z') || (str[i - 1] >= 'a' && str[i - 1] <= 'z'))
		prev = 1;
	if (prev == 0)
		str[i] = str[i] + 'A' - 'a';
}

char	*ft_strcapitalize(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A' && str[i] <= 'Z'))
			str[i] = str[i] + 'a' - 'A';
		if (i == 0)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] + 'A' - 'a';
		}
		else
			ft_prev(str, i);
		i++;
	}
	return (str);
}
