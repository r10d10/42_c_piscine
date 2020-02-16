/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:27:52 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/16 23:20:46 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "misc.h"

const char			*get_string(unsigned int value)
{
	if (value == 0)
		return ("0");
	else if (value == 1)
		return ("1");
	else if (value == 2)
		return ("2");
	else if (value == 3)
		return ("3");
	else if (value == 4)
		return ("4");
	else
		return ("U");
}
