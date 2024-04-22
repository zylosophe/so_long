/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_activablewall.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:27:03 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/22 12:44:28 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static t_point	activablewall_loop(t_object *obj, t_point pos)
{
	(void)obj;
	(void)pos;
	return (point_init(0, 0));
}

static void	activablewall_draw(t_object *obj, t_point p)
{
	if (g_env.ketchup < g_env.max_ketchup)
		sprite_draw(p, &((t_activablewall_data *)obj->data)->spr);
}

static bool	activablewall_walk_through(
		t_object *obj, t_character *character, t_point pos)
{
	(void)obj;
	(void)character;
	(void)pos;
	return (g_env.ketchup == g_env.max_ketchup);
}

t_object	activablewall_init(t_memclass mc)
{
	static const t_objecttype			type
		= {.solid_firsk = false, .solid_snas = false,
		.init = activablewall_init, .loop = activablewall_loop,
		.draw = activablewall_draw, .walk_through = activablewall_walk_through};
	t_object							r;
	t_wall_data							*data;

	r.type = type;
	data = mem_alloc(error_err, mc, sizeof(t_activablewall_data));
	data->spr = sprite_init(SPR_WALL);
	r.data = data;
	return (r);
}
