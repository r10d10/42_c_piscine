/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:06:32 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/19 21:50:36 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_strlen(char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int		ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dlen;
	unsigned int	remain;
	char			*d;
	char			*src_begin;

	d = dest;
	src_begin = src;
	remain = size;
	while (remain-- != 0 && *d != '\0')
		d++;
	dlen = d - dest;
	remain = size - dlen;
	if (remain == 0)
		return (dlen + ft_strlen(src));
	while (*src != '\0')
	{
		if (remain > 1)
		{
			*d++ = *src;
			remain--;
		}
		src++;
	}
	*d = '\0';
	return (dlen + (src - src_begin));
}
