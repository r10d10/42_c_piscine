/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 21:39:06 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/16 21:40:58 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVALUATE_H
# define EVALUATE_H

/*
** we return 0 if Candidate does not accept the possibility.
*/
void			evaluate_possibility(unsigned int round,
		unsigned int *possibility,
		struct s_map_t *candidate, struct s_solutions_t *solutions);

void			evaluate_candidate(unsigned int round, unsigned int value,
		struct s_map_t *candidate, struct s_solutions_t *solutions);

#endif
