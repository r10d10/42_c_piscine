/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:42:55 by aollero-          #+#    #+#             */
/*   Updated: 2020/02/22 18:56:45 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict_values.h"
#include "parse.h"
#include <stdlib.h>
#include <stdio.h>
#define DICT_ROWS 4
#define DICT_COLUMNS 12

static char		*g_dict_values[DICT_ROWS][DICT_COLUMNS];

const char		*dict_get(unsigned int order, unsigned int idx)
{
	if ((order >= DICT_ROWS) || (idx >= DICT_COLUMNS))
		return (NULL);
	return (g_dict_values[order][idx]);
}

void		dict_values_init(void)
{
	unsigned int	rows;
	unsigned int	columns;

	rows = 0;
	while (rows < DICT_ROWS)
	{
		columns = 0;
		while (columns < DICT_COLUMNS)
		{
			g_dict_values[rows][columns] = NULL;
			columns++;
		}
		rows++;
	}
}

int				dict_values_parse_line(char *line)
{
	unsigned int	cursor;
	unsigned int	order;
	unsigned int	idx;

	if (0 == (cursor = get_number_length(line)))
		return (1);
	if (0 != parse_dict_number(line, cursor, &order, &idx))
		return (0); // Not a key we want.
	cursor += get_spaces(line + cursor);
	if (line[cursor++] != ':')
		return (1);
	cursor += get_spaces(line + cursor);
	get_words(line + cursor);
	if (NULL != g_dict_values[order][idx])
		free(g_dict_values[order][idx]);
	g_dict_values[order][idx] = dupstr(line + cursor);
	return (0);
}

void		dict_values_destroy(void)
{
	unsigned int	rows;
	unsigned int	columns;

	rows = 0;
	while (rows < DICT_ROWS)
	{
		columns = 0;
		while (columns < DICT_COLUMNS)
		{
			if (NULL != g_dict_values[rows][columns])
			{
				free(g_dict_values[rows][columns]);
				g_dict_values[rows][columns] = NULL;
			}
			columns++;
		}
		rows++;
	}
}

// REMOVE THIS

void		dict_values_show(void)
{
	unsigned int	rows;
	unsigned int	columns;

	rows = 0;
	while (rows < DICT_ROWS)
	{
		columns = 0;
		while (columns < DICT_COLUMNS)
		{
			printf("%d:%d:%s\n", rows, columns,
				dict_get(rows, columns));
			columns++;
		}
		rows++;
	}
}
