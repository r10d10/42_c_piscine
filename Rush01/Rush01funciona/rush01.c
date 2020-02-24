/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:41:50 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/16 22:17:54 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "rush01.h"
#include "map0.h"
#include "map1.h"
#include "evaluate.h"

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

/*
**reads the colums and then the rows
**rows - left to right else right to left
*/
//void				map_get_section2(struct s_map_t *map,
//				unsigned int round, unsigned int *values);

/*
**reads the colums and then the rows
**colums - top to bottom else bottom to top
*/
//void				map_get_section(struct s_map_t *map,
//				unsigned int round, unsigned int *values);

/*
**reads the colums and then the rows
**rows - left to right else right to left
*/
//void				map_update_section2(struct s_map_t *map,
//			unsigned int round, unsigned int *values);

/*
**reads the colums and then the rows
**colums - top to bottom else bottom to top
*/
//void				map_update_section(struct s_map_t *map,
//			unsigned int round, unsigned int *values);

//void				map_init(struct s_map_t *map);

//struct s_map_t		*map_clone(struct s_map_t *src);

//void				map_show(struct s_map_t *map);

//void				solutions_init(struct s_solutions_t *solutions);

//void				solutions_append(struct s_solutions_t *solutions, struct s_map_t *map);

/*
** we return 0 if Candidate does not accept the possibility.
*/
//void				evaluate_possibility(unsigned int round, unsigned int *possibility,
//			struct s_map_t *candidate, struct s_solutions_t *solutions);

//void				evaluate_candidate(unsigned int round, unsigned int value,
//		struct s_map_t *candidate, struct s_solutions_t *solutions);

/*
** begging - Use next_candidate to store the next pointer, as the node is freed
** before the access.
**
** Go over all the candidates, creating new viable candidates
** after applying the round value.
*/
void				solve_round(unsigned int round, unsigned int value,
		struct s_solutions_t *candidates, struct s_solutions_t *solutions)
{
	struct s_map_t				*candidate;
	struct s_map_t 				*next_candidate;

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
struct s_map_t		*solve(struct s_conditions_t *conds)
{
	struct s_solutions_t		candidates;
	struct s_solutions_t		solutions;
	struct s_map_t				*initial_map;
	unsigned int				r;

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

void 				parse_conditions(char *cmdline, struct s_conditions_t *conds)
{
	int							i;
	int							j;

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

int 				main(int argc, char *argv[])
{
	struct s_conditions_t		conds;
	struct s_map_t				*solution;

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
