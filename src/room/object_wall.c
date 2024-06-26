/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:27:03 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/22 12:46:03 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static t_point	wall_loop(t_object *obj, t_point pos)
{
	(void)obj;
	(void)pos;
	return (point_init(0, 0));
}

static void	wall_draw(t_object *obj, t_point p)
{
	sprite_draw(p, &((t_wall_data *)obj->data)->spr);
}

t_object	wall_init(t_memclass mc)
{
	static const t_objecttype			type
		= {.solid_firsk = true, .solid_snas = true,
		.init = wall_init, .loop = wall_loop, .draw = wall_draw,
		.walk_through = NULL};
	t_object							r;
	t_wall_data							*data;

	r.type = type;
	data = mem_alloc(error_err, mc, sizeof(t_wall_data));
	data->spr = sprite_init(SPR_WALL);
	r.data = data;
	return (r);
}
