/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:41:50 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/16 23:40:10 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "rush01.h"
#include "map0.h"
#include "map1.h"
#include "evaluate.h"

/*
** begging - Use next_candidate to store the next pointer, as the node is freed
** before the access.
**
** Norminette <3
**
** Go over all the candidates, creating new viable candidates
** after applying the round value.
*/

void					solve_round(unsigned int round, unsigned int value,
		struct s_solutions_t *candidates, struct s_solutions_t *solutions)
{
	struct s_map_t					*candidate;
	struct s_map_t					*next_candidate;

	candidate = candidates->first;
	while (candidate != NULL && ((next_candidate = candidate->next) || 1))
	{
		evaluate_candidate(round, value, candidate, solutions);
		free(candidate);
		candidate = next_candidate;
	}
}

/*
** returns NULL if there are no viable canditaes, exit.
** and then Go over the candidates again.
**
**in the end Return the first viable solution.
*/

struct s_map_t			*solve(struct s_conditions_t *conds)
{
	struct s_solutions_t			candidates;
	struct s_solutions_t			solutions;
	struct s_map_t					*initial_map;
	unsigned int					r;

	initial_map = malloc(sizeof(struct s_map_t));
	map_init(initial_map);
	solutions_init(&candidates);
	solutions_append(&candidates, initial_map);
	r = 0;
	while (r < 16)
	{
		solutions_init(&solutions);
		solve_round(r, conds->values[r], &candidates, &solutions);
		if (solutions.first == NULL)
			return (NULL);
		candidates = solutions;
		r++;
	}
	return (solutions.first);
}

void					parse_conditions(char *cmdline,
	struct s_conditions_t *conds)
{
	int								i;
	int								j;

	i = 0;
	j = 0;
	while ((cmdline[i] >= '0' && cmdline[i] <= '9') || cmdline[i] == ' ')
	{
		if (cmdline[i] >= '0' && cmdline[i] <= '9')
		{
			(*conds).values[j] = cmdline[i] - '0';
			j++;
		}
		i++;
	}
}

int						main(int argc, char *argv[])
{
	struct s_conditions_t			conds;
	struct s_map_t					*solution;

	if (argv[1][31] != '\0')
	{
		write(1, "Error\n", 6);
		return (1);
	}
	parse_conditions(argv[1], &conds);
	(void)argc;
	solution = solve(&conds);
	if (solution == NULL || argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	map_show(solution);
	return (0);
}
