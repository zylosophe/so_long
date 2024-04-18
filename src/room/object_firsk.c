/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_firsk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:55:04 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/18 18:37:10 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static t_direction	firsk_brain(t_point pos)
{
	return (pathfinding(pos, room_find(snas_init), true));
}

static t_point	firsk_loop(t_object *obj, t_point pos)
{
	t_point	r;

	r = character_loop(
			&((t_firsk_data *)obj->data)->character, pos, firsk_brain);
	return (r);
}

static void	firsk_draw(t_object *obj, t_point p)
{
	return (character_draw(&((t_firsk_data *)obj->data)->character, p));
}

t_object	firsk_init(t_memclass mc)
{
	static const t_objecttype			type
		= {solid_firsk: false, solid_snas: false,
		init: firsk_init, loop: firsk_loop, draw: firsk_draw,
		walk_through: NULL};
	static const t_character_sprites	sprites = {
		still: SPR_FIRSK,
		walk_left: SPR_FIRSK_WALK_LEFT,
		walk_right: SPR_FIRSK_WALK_RIGHT,
		walk_up: SPR_FIRSK_WALK_UP,
		walk_down: SPR_FIRSK_WALK_DOWN,
	};
	t_object							r;
	t_firsk_data						*data;

	r.type = type;
	data = mem_alloc(error_err, mc, sizeof(t_firsk_data));
	data->character = character_init((t_character_sprites *)&sprites, 4);
	r.data = data;
	return (r);
}
