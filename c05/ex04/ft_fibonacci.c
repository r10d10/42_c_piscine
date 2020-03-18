/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:05:33 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/25 19:46:03 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci_recursive(int index, int prev_to_prev, int prev, int count)
{
	if (index < count + 2)
		return (prev + prev_to_prev);
	return (ft_fibonacci_recursive(index, prev, prev_to_prev +
									prev, count + 1));
}

int		ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index < 1)
		return (0);
	return (ft_fibonacci_recursive(index, 0, 1, 1));
}
