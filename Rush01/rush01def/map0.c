/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 21:11:15 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/16 23:14:00 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "rush01.h"
#include "map0.h"
#include "misc.h"

struct s_map_t	*map_clone(struct s_map_t *src)
{
	int				r;
	int				c;
	struct s_map_t	*new_map;

	new_map = malloc(sizeof(struct s_map_t));
	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			(*new_map).values[r][c] = src->values[r][c];
			c++;
		}
		r++;
	}
	(*new_map).next = NULL;
	return (new_map);
}

void			map_show(struct s_map_t *map)
{
	int				r;
	int				c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			write(1, get_string((*map).values[r][c]), 1);
			if (c < 3)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
			c++;
		}
		r++;
	}
}

void			solutions_init(struct s_solutions_t *solutions)
{
	(*solutions).first = NULL;
	(*solutions).last = NULL;
}

void			solutions_append(struct s_solutions_t *solutions,
							struct s_map_t *map)
{
	if (NULL == (*solutions).first)
		(*solutions).first = map;
	if (NULL == (*solutions).last)
	{
		(*solutions).last = map;
	}
	else
	{
		(*solutions).last->next = map;
		(*solutions).last = map;
	}
}
