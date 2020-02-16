/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:44:43 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/16 22:37:30 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

typedef struct	s_map_t
{
	int				values[4][4];
	struct s_map_t	*next;
}				t_map_t;

typedef struct	s_conditions_t
{
	int values[16];
}				t_conditions_t;

typedef struct	s_solutions_t
{
	struct s_map_t	*first;
	struct s_map_t	*last;
}				t_solutions_t;

typedef struct	s_possibilities_t
{
	unsigned int	count;
	unsigned int	values[11][4];
}				t_possibilities_t;

#endif
