/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 21:12:13 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/16 21:20:13 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "rush01.h"

/*
** we return 0 if Candidate does not accept the possibility.
*/
void			evaluate_possibility(unsigned int round,
		unsigned int *possibility,
		struct s_map_t *candidate, struct s_solutions_t *solutions)
{
	int					i;
	unsigned int		section[4];
	struct s_map_t		*new_candidate;

	map_get_section(candidate, round, section);
	i = 0;
	while (i < 4)
	{
		if ((0 != section[i]) && (section[i] != possibility[i]))
			return ;
		i++;
	}
	new_candidate = map_clone(candidate);
	map_update_section(new_candidate, round, possibility);
	solutions_append(solutions, new_candidate);
}

void			evaluate_candidate(unsigned int round, unsigned int value,
		struct s_map_t *candidate, struct s_solutions_t *solutions)
{
	unsigned int			p;

	p = 0;
	while (p < possibilities[value - 1].count)
	{
		evaluate_possibility(round, possibilities[value - 1].values[p],
					candidate, solutions);
		p++;
	}
}
