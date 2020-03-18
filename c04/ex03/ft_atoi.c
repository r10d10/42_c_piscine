/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 22:17:34 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/22 23:40:15 by vpetrova         ###   ########.fr       */
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
