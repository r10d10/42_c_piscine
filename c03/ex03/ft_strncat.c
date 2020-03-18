/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:06:32 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/19 21:15:11 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char *d;

	d = dest;
	while (*d != '\0')
	{
		d++;
	}
	while (*src != '\0' && nb > 0)
	{
		*d = *(unsigned char*)src;
		d++;
		src++;
		nb--;
	}
	*d = '\0';
	return (dest);
}
