/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:58:30 by aollero-          #+#    #+#             */
/*   Updated: 2020/02/23 16:47:58 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "dict_values.h"
#include "file.h"
#include <stdlib.h>

int		dict_create(const char *path)
{
	char		*ptr;
	int			r;

	dict_values_init();
	int f = open_file(path);
	if (f != 0)
		return (f);
	while (0 == (r = read_file_line(&ptr)) && (ptr != NULL))
	{
		if ((*ptr != '\0') && (0 != dict_values_parse_line(ptr)))
		{
			dict_values_destroy();
			close_file();
			return (1);
		}
	}
	close_file();
	if (r != 0)
	{
		dict_values_destroy();
		return 1;
	}
	
	// remove dict_values_show();
	return (0);
}

void dict_destroy(void)
{
	dict_values_destroy();
}
