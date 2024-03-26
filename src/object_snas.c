/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_snas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:27:03 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/29 13:54:55 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "error.h"
#include "sprite.h"
#include "libtf.h"
#include "env.h"

static t_direction	snas_brain(void)
{
	if (g_env.up && !g_env.down)
		return (UP);
	if (g_env.down && !g_env.up)
		return (DOWN);
	if (g_env.left && !g_env.right)
		return (LEFT);
	if (g_env.right && !g_env.left)
		return (RIGHT);
	return (NO_DIRECTION);
}

static t_point	snas_loop(t_object *obj, t_point pos)
{
	return (character_loop(
			&((t_snas_data *)obj->data)->character, pos, snas_brain));
}

static void	snas_draw(t_object *obj, int x, int y)
{
	return (character_draw(&((t_snas_data *)obj->data)->character, x, y));
}

t_object	snas_init(t_memclass mc)
{
	static const t_objecttype			type
		= {loop: snas_loop, draw: snas_draw};
	static const t_character_sprites	sprites = {
		still: SPR_SNAS,
		walk_left: SPR_SNAS_LEFT,
		walk_right: SPR_SNAS_RIGHT,
		walk_up: SPR_SNAS_UP,
		walk_down: SPR_SNAS_DOWN,
	};
	t_object							r;
	t_snas_data							*data;

	r.type = type;
	data = mem_alloc(err, mc, sizeof(t_snas_data));
	data->character = character_init((t_character_sprites *)&sprites);
	r.data = data;
	return (r);
}
