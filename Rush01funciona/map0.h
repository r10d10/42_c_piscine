/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map0.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 21:29:43 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/16 21:33:59 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP0_H
# define MAP0_H

struct s_map_t		*map_clone(struct s_map_t *src);

void				map_show(struct s_map_t *map);

void				solutions_init(struct s_solutions_t *solutions);

void				solutions_append(struct s_solutions_t *solutions,
								struct s_map_t *map);

#endif
