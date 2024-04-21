/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:01:16 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/21 17:06:07 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static t_point	exit_loop(t_object *obj, t_point pos)
{
	t_exit_data *const	data = (t_exit_data *)(obj->data);

	data->finalexit = room_count(ultimateketchup_init) == 1;
	(void)pos;
	if (!data->finalexit
		&& !data->active && g_env.ketchup == g_env.max_ketchup)
	{
		data->active = true;
		data->spr = sprite_init(SPR_EXIT_ACTIVE);
	}
	return (point_init(0, 0));
}

static void	exit_draw(t_object *obj, t_point p)
{
	t_exit_data *const	data = (t_exit_data *)(obj->data);

	if (!data->finalexit)
		sprite_draw(p, &data->spr);
}

static bool	exit_walk_through(
		t_object *obj, t_character *character, t_point pos)
{
	t_exit_data *const	data = (t_exit_data *)(obj->data);
	const t_point		snas_p = room_find(snas_init);

	(void)character;
	(void)pos;
	if (data->finalexit)
	{
		g_env.room.ending = true;
		return (false);
	}
	if (!data->active)
		return (false);
	((t_snas_data *)g_env.room.objects[snas_p.y * g_env.room.width + snas_p.x]
			->data)->state++;
	visual_addtoroom(sprite_init(SPR_EXIT_REMAINING), pos);
	return (true);
}

t_object	exit_init(t_memclass mc)
{
	static const t_objecttype			type
		= {solid_firsk: true, solid_snas: true,
		init: exit_init, loop: exit_loop, draw: exit_draw,
		walk_through: exit_walk_through};
	t_object							r;
	t_exit_data							*data;

	r.type = type;
	data = mem_alloc(error_err, mc, sizeof(t_exit_data));
	data->spr = sprite_init(SPR_EXIT_INACTIVE);
	data->active = false;
	r.data = data;
	return (r);
}
