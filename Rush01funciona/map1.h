/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 21:34:27 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/16 21:38:34 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP1_H
# define MAP1_H

/*
**reads the colums and then the rows
**rows - left to right else right to left
*/

void				map_get_section2(struct s_map_t *map,
				unsigned int round, unsigned int *values);

/*
**reads the colums and then the rows
**colums - top to bottom else bottom to top
*/

void				map_get_section(struct s_map_t *map,
				unsigned int round, unsigned int *values);

/*
**reads the colums and then the rows
**rows - left to right else right to left
*/

void				map_update_section2(struct s_map_t *map,
			unsigned int round, unsigned int *values);

/*
**reads the colums and then the rows
**colums - top to bottom else bottom to top
*/
void				map_update_section(struct s_map_t *map,
			unsigned int round, unsigned int *values);

void				map_init(struct s_map_t *map);

#endif
