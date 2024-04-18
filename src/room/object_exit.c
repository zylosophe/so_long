/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:01:16 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/18 15:56:50 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static t_point	exit_loop(t_object *obj, t_point pos)
{
	t_exit_data *const	data = (t_exit_data *)(obj->data);

	(void)pos;
	if (!data->active && g_env.ketchup == g_env.max_ketchup)
	{
		data->active = true;
		data->spr = sprite_init(SPR_EXIT_ACTIVE);
	}
	return (point_init(0, 0));
}

static void	exit_draw(t_object *obj, t_point p)
{
	t_exit_data *const	data = (t_exit_data *)(obj->data);

	sprite_draw(p, &data->spr);
}

static bool	exit_walk_through(
		t_object *obj, t_character *character, t_point pos)
{
	t_exit_data *const	data = (t_exit_data *)(obj->data);

	(void)character;
	if (!data->active)
		return (false);
	visual_addtoroom(SPR_EXIT_USING, pos);
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
