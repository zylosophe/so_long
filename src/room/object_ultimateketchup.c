/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_ultimateketchup.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:27:03 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/22 12:45:46 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static t_point	ultimateketchup_loop(t_object *obj, t_point pos)
{
	(void)obj;
	(void)pos;
	if (g_env.room.ending)
		((t_ultimateketchup_data *)obj->data)->time++;
	return (point_init(0, 0));
}

static void	ultimateketchup_draw(t_object *obj, t_point p)
{
	sprite_draw(p, &((t_ultimateketchup_data *)obj->data)->spr);
}

t_object	ultimateketchup_init(t_memclass mc)
{
	static const t_objecttype			type
		= {.solid_firsk = true, .solid_snas = true,
		.init = ultimateketchup_init, .loop = ultimateketchup_loop,
		.draw = ultimateketchup_draw, .walk_through = NULL};
	t_object							r;
	t_ultimateketchup_data				*data;

	r.type = type;
	data = mem_alloc(error_err, mc, sizeof(t_ultimateketchup_data));
	data->spr = sprite_init(SPR_ULTIMATEKETCHUP);
	data->time = 0;
	r.data = data;
	return (r);
}
