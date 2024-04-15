/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:14:26 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/15 16:36:45 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_map
{
	t_point	dim;
	void	**cases;
}			t_map;

t_map	map_init(t_memclass mc, t_point dim);
void	**map_at(t_map *map, t_point p);
void	map_foreach(t_map *map, void (*f)(t_point p, void **el, void *arg),
			void *arg);

#endif
