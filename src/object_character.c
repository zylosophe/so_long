/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_character.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:27:03 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/29 13:56:58 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "error.h"
#include "sprite.h"
#include "libtf.h"
#include "env.h"

static void	character_initstate(t_character *character)
{
	const t_spriteid	walk_sprites[] = {
		character->sprites->walk_down,
		character->sprites->walk_up,
		character->sprites->walk_left,
		character->sprites->walk_right,
	};

	if (character->walk_remaining_steps)
		character->spr = sprite_init(walk_sprites[character->direction]);
	else
	{
		character->spr = sprite_init(SPR_SNAS);
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

	(void)pos;
	move = NO_DIRECTION;
	if (character->walk_remaining_steps)
		if (!--character->walk_remaining_steps)
			character_initstate(character);
	if (!character->walk_remaining_steps)
	{
		move = brain();
		if (move != NO_DIRECTION)
		{
			character->walk_remaining_steps = WALK_STEPS_NB - 1;
			character->direction = move;
			character_initstate(character);
		}
	}
	if (move != NO_DIRECTION)
		return (point_fromdirection(character->direction));
	return (point_init(0, 0));
}

t_character	character_init(t_character_sprites *sprites)
{
	t_character	r;

	r.direction = DOWN;
	r.sprites = sprites;
	r.walk_remaining_steps = 0;
	character_initstate(&r);
	return (r);
}
