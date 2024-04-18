/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_snas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:27:03 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/18 15:58:11 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static bool	snas_walk_through(t_object *obj, t_character *character,
	t_point pos)
{
	(void)obj;
	(void)character;
	(void)pos;
	gameover_byfirskattack(&((t_snas_data *)obj->data)->character);
	return (false);
}

static t_direction	snas_brain(t_point pos)
{
	(void)pos;
	if (g_env.input[UP] && !g_env.input[DOWN])
		return (UP);
	if (g_env.input[DOWN] && !g_env.input[UP])
		return (DOWN);
	if (g_env.input[LEFT] && !g_env.input[RIGHT])
		return (LEFT);
	if (g_env.input[RIGHT] && !g_env.input[LEFT])
		return (RIGHT);
	return (NO_DIRECTION);
}

static t_point	snas_loop(t_object *obj, t_point pos)
{
	t_point	r;

	r = character_loop(&((t_snas_data *)obj->data)->character, pos, snas_brain);
	if (r.x || r.y)
		g_env.moves++;
	return (r);
}

static void	snas_draw(t_object *obj, t_point p)
{
	return (character_draw(&((t_snas_data *)obj->data)->character, p));
}

t_object	snas_init(t_memclass mc)
{
	static const t_objecttype			type
		= {solid_firsk: false, solid_snas: false,
		init: snas_init, loop: snas_loop, draw: snas_draw,
		walk_through: snas_walk_through};
	static const t_character_sprites	sprites = {
		still: SPR_SNAS,
		walk_left: SPR_SNAS_WALK_LEFT,
		walk_right: SPR_SNAS_WALK_RIGHT,
		walk_up: SPR_SNAS_WALK_UP,
		walk_down: SPR_SNAS_WALK_DOWN,
	};
	t_object							r;
	t_snas_data							*data;

	r.type = type;
	data = mem_alloc(error_err, mc, sizeof(t_snas_data));
	data->character = character_init((t_character_sprites *)&sprites, 4);
	r.data = data;
	return (r);
}
