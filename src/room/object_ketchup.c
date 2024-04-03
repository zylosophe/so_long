/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_ketchup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:27:03 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/03 16:10:39 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static t_point	ketchup_loop(t_object *obj, t_point pos)
{
	(void)obj;
	(void)pos;
	return (point_init(0, 0));
}

static void	ketchup_draw(t_object *obj, int x, int y)
{
	sprite_draw(x, y, &((t_wall_data *)obj->data)->spr);
}

static bool	ketchup_walk_through(t_character *character, t_point pos)
{
	(void)character;
	g_env.ketchup++;
	tf_printf("Ketchup level: %i\n", g_env.ketchup);
	visual_addtoroom(SPR_KETCHUP_FADE, pos);
	return (true);
}

t_object	ketchup_init(t_memclass mc)
{
	static const t_objecttype			type
		= {loop: ketchup_loop, draw: ketchup_draw,
		walk_through: ketchup_walk_through};
	t_object							r;
	t_wall_data							*data;

	r.type = type;
	data = mem_alloc(error_err, mc, sizeof(t_wall_data));
	data->spr = sprite_init(SPR_KETCHUP);
	r.data = data;
	return (r);
}
