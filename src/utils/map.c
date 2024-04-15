/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:14:26 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/15 15:01:01 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static void	set_null(t_point p, void **el, void *arg)
{
	(void)p;
	(void)arg;
	*el = NULL;
}

t_map	map_init(t_memclass mc, t_point dim)
{
	t_map	r;

	r.dim = dim;
	r.cases = mem_alloc(error_err, mc, dim.x * dim.y * sizeof(void *));
	map_foreach(&r, set_null, NULL);
	return (r);
}

void	**map_at(t_map *map, t_point p)
{
	return (&map->cases[p.y * map->dim.x + p.x]);
}

void	map_foreach(t_map *map, void (*f)(t_point p, void **el, void *arg),
			void *arg)
{
	t_point	p;

	p.y = -1;
	while (++p.y < map->dim.y)
	{
		p.x = -1;
		while (++p.x < map->dim.x)
			f(p, map_at(map, p), arg);
	}
}
