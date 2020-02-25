/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:41:25 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/24 17:54:12 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

#include <stdlib.h>

int map_init(t_map *map, unsigned int height, unsigned int width,
	     char empty_symbol, char obstacle_symbol, char solution_symbol)
{
	map->positions = malloc(sizeof(char) * width * height);
	if (NULL == map->positions)
		return 1;
	map->height = height;
	map->width = width;
	map->empty_symbol = empty_symbol;
	map->obstacle_symbol = obstacle_symbol;
	map->solution_symbol = solution_symbol;

	unsigned int byte;
	byte = 0;
	while (byte < height * width) {
		map->positions[byte] = empty_symbol;
		byte++;
	}

	return 0;
}

int map_is_obstacle(t_map *src, unsigned int row, unsigned int column)
{
	if (row >= src->height)
		return 1;
	if (column >= src->width)
		return 1;

	char value = *(src->positions + (row * src->width) + column);

	return value == src->obstacle_symbol;
}

void map_set_obstacle(t_map *src, unsigned int row, unsigned int column)
{
	if (row >= src->height)
		return;
	if (column >= src->width)
		return;

	*(src->positions + (row * src->width) + column) = src->obstacle_symbol;
}

void map_free(t_map *map)
{
	if (NULL != map->positions)
		free(map->positions);
	map->positions = NULL;
}

