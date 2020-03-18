/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:44:13 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/23 16:00:29 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
	|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int		ft_negative(char c)
{
	if (c == '-')
		return (-1);
	if (c == '+')
		return (1);
	else
		return (0);
}

int		ft_atoi(char *str)
{
	int minus;
	int result;

	result = 0;
	minus = 1;
	while (ft_is_space(*str))
		str++;
	while (ft_negative(*str) == -1 || ft_negative(*str) == 1)
	{
		minus *= ft_negative(*str);
		str++;
	}
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			result *= 10;
			result += ((int)(*str - '0'));
		}
		else
			break ;
		str++;
	}
	return (result * minus);
}

int		ft_recursive(int nbr, char *base, int i)
{
	int result;
	int minus;
	int dec_count;

	result = 0;
	minus = 1;
	dec_count = 1;
	if (nbr < 0)
	{
		minus = -1;
		nbr = -nbr;
	}
	while (nbr >= i)
	{
		result += (-'0' + base[nbr % i]) * dec_count;
		nbr = nbr / i;
		dec_count *= 10;
	}
	if ((nbr >= 0) && (nbr < i))
	{
		result += (-'0' + base[nbr % i]) * dec_count;
	}
	return (result * minus);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int nbr;
	int j;
	int result;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = 0;
		while (base[j] != '\0')
		{
			if ((base[j] == base[i]) && (i != j))
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	nbr = ft_atoi(str);
	result = ft_recursive(nbr, base, i);
	return (result);
}
