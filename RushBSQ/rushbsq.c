/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:21:46 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/24 18:55:34 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "map.h"
#include "file.h"

//WARNING		---		REMOVE THIS
#include <stdio.h>
#include <stdbool.h>
//TO CREATE BOOL

/*
** In the case that more than one solution exists, we’ll choose to represent
** thesquare that’s closest to the top of the map, then the one that’s most to
** theleft
** x - left ot right, y - up/down
*/

static int is_square_valid(t_map *map, unsigned int row, unsigned int column,
			   unsigned int increase, int full_check)
{
	(void) full_check;

	unsigned int row_scan;
	unsigned int column_scan;

	if (((row + increase) > map->height) ||
	    ((column + increase) > map->width))
		return 0; // Square would be out of bounds.

	row_scan = row;
	while (row_scan < row + increase) { // Scan vertically for obstacles.
		column_scan = column;
		// Scan horizontally for obstacles.
		while (column_scan < column + increase) {
			if (map_is_obstacle(map, row_scan, column_scan))
				return 0; // Obstacle found.

			column_scan++;
		}
		row_scan++;
	}

	return 1; // Square fits OK.
}

static void point_check(t_map *map, unsigned int row, unsigned int column,
		 t_solution *solution)
{
	unsigned int increase; //increase index
	int full_check;

	increase = solution->best + 1;
	full_check = 1;
	while (1) // Try bigger and bigger squares.
	{
		if (!is_square_valid(map, row, column, increase, full_check))
			return;

		full_check = 0;
		solution->best = increase;
		solution->row = row;
		solution->column = column;
		increase++;
	}
}

static void solve(t_map *map, t_solution *solution)
{
	unsigned int row;
	unsigned int column;

	row = 0;
	column = 0;
	solution->best = 0;

	// Scan vertically.
	while(row < (map->height - solution->best + 1))
	{ // Don't go further down than the current best solution.
		column = 0;
		// Scan horizontally.
		while(column < (map->width - solution->best + 1))
		{ // Don't go further right than the current best solution.
			point_check(map, row, column, solution);
			column++;
		}
		row++;
	}
}

static void solve_path(const char *path)
{
	t_solution solution;
	t_map map;

	if (0 != file_get_map(path, &map)) {
		printf("Map error\n");
		return;
	}

	solve(&map, &solution);

	map_free(&map);

	printf("Solution is size %d, at %d:%d\n",
	       solution.best, solution.row, solution.column);
}

int main (int argc, char **argv)
{
	int map_counter = 1;

	if (argc == 1)
		solve_path(NULL);
	else
		while (map_counter < argc)
			solve_path(argv[map_counter++]);

	return 0;
}
