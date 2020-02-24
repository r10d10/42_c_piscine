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

//To change:
unsigned int mapX = 2;
unsigned int mapY = 2;
unsigned char free_space = '0';
unsigned char obstacle = '1';

t_solution_trio		point_check(t_solution_trio current, char **workmap)
{
	int i_x;
	int i_y;
	int increse;//increce index
	bool is_obst;
	t_solution_trio new;

	increse = 0;
	is_obst = false;
	while (1)
	{
		i_x = current.x;
		printf("1\n");
		while ((i_x <= current.x + increse) && ((i_x < mapX))
		{
			printf("2\n");
			i_y = current.y;
			while ((i_y <= current.y + increse) && ((i_x < mapX))
			{
				printf("3\n");
				if (workmap[i_y][i_x] == obstacle)
				{
					printf("obstacle\n");
					is_obst = true;
					//break;
				}
				printf("%i, %i\n", i_x, i_y);
				i_y++;
			}
			if (is_obst == true)
				//break;
			i_x++;
		}
		if (is_obst == false)
			increse++;
		else
			break ;
		
	}
	new.x = current.x;
	new.y= current.y;
	new.best = increse;
	return (new);
}


t_solution_trio		solve(t_solution_trio sol, char **workmap)
{
	t_solution_trio current;
	
	current.x = 0;
	current.best = 0;

	while(current.x < mapX - sol.best)
	{
		current.y = 0;
		while(current.y < mapY - sol.best)
		{
			//printf("%i, %i\n", current.x, current.y);
			current = point_check(current, workmap);
			if (current.best > sol.best)
			{
				sol.best = current.best;
				sol.x = current.x;
				sol.y = current.y;
			}
			current.y++;
		}
		current.x++;
	}
	return (sol);
}

int main (int argc, char **argv)
{
	t_solution_trio solution;

	(void)argc;
	(void)argv;

	solution.x = -1;
	solution.y = -1;
	solution.best = 0;

/*	char work_map[7][7] = {
				{"000000"},
				{"000100"},
				{"000001"},
				{"000000"},
				{"000001"},
				{"100100"}
		};	*/
	char work_map[2][2];
	work_map[0][0] = '0';
	work_map[0][1] = '0';
	work_map[1][0] = '0';
	work_map[1][1] = '0';
	
	solution = solve(solution, work_map);
	printf("%i\n", solution.best);
	printf("%i\n", solution.x);
	printf("%i\n", solution.y);

}