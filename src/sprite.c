/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:28:52 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/28 16:02:01 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"
#include "display.h"
#include "error.h"

t_sprite	sprite_init(t_spriteid id)
{
	t_sprite	r;

	r.info = (t_spriteinfo *)(g_spritesmap + id);
	r.index = 0;
	return (r);
}

void	sprite_draw(int x, int y, t_sprite *spr)
{
	display_draw(
		x - spr->info->origin_x, y - spr->info->origin_y,
		spr->info->first_frame + spr->index);
	if (spr->info->type == ANIMATION)
	{
		spr->index++;
		if (spr->index >= spr->info->nb_frames)
			spr->index = 0;
	}
}

void	sprite_character_set_direction(t_sprite *spr, t_direction value)
{
	if (spr->info->type != CHARACTER_STILL)
		err("the sprite must be a CHARACTER_STILL sprite.");
	spr->index = value;
}
