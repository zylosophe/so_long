/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_character.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:27:03 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/05 19:44:45 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static void	character_initstate(t_character *character)
{
	const t_spritesmap_id	walk_sprites[] = {
		character->sprites->walk_down,
		character->sprites->walk_up,
		character->sprites->walk_left,
		character->sprites->walk_right,
	};
	t_sprite				new_spr;

	if (character->walk_remaining_steps)
	{
		new_spr = sprite_init(walk_sprites[character->direction]);
		if (character->spr.meta != new_spr.meta)
			character->spr = new_spr;
	}
	else
	{
		character->spr = sprite_init(character->sprites->still);
		sprite_character_set_direction(&character->spr, character->direction);
	}
}

void	character_draw(t_character *character, int x, int y)
{
	t_point	pos;

	pos = point_init(x, y);
	point_addto(&pos,
		point_multiply(
			point_fromdirection(character->direction),
			character->walk_remaining_steps * 50 / -WALK_STEPS_NB
			));
	sprite_draw(pos.x, pos.y, &character->spr);
}

t_point	character_loop(
	t_character *character, t_point pos, t_direction (*brain)(void))
{
	t_direction			move;

	move = NO_DIRECTION;
	if (character->walk_remaining_steps)
	{
		character_initstate(character);
		character->walk_remaining_steps--;
	}
	else
	{
		move = brain();
		if (move != NO_DIRECTION)
		{
			character->direction = move;
			if (room_canwalk(g_env.room, character, pos))
			{
				character->walk_remaining_steps = WALK_STEPS_NB - 1;
				character_initstate(character);
				return (point_fromdirection(character->direction));
			}
		}
		character_initstate(character);
	}
	return (point_init(0, 0));
}

t_character	character_init(t_character_sprites *sprites)
{
	t_character	r;

	r.direction = DOWN;
	r.sprites = sprites;
	r.walk_remaining_steps = 0;
	r.spr = sprite_init(r.sprites->still);
	character_initstate(&r);
	return (r);
}
