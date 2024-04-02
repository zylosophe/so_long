/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:28:52 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/02 18:02:35 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

t_sprite	sprite_init(t_spritesmap_id id)
{
	t_sprite	r;

	r.meta = (t_spritemeta *)(g_spritesmap + id);
	r.index = 0;
	return (r);
}

void	sprite_draw(int x, int y, t_sprite *spr)
{
	display_draw(
		x - spr->meta->origin_x, y - spr->meta->origin_y,
		spr->meta->first_frame + spr->index);
	if (spr->meta->type == ANIMATION)
	{
		spr->index++;
		if (spr->index >= spr->meta->nb_frames)
			spr->index = 0;
	}
}

void	sprite_character_set_direction(t_sprite *spr, t_direction value)
{
	if (spr->meta->type != CHARACTER_STILL)
		error_err("the sprite must be a CHARACTER_STILL sprite.");
	spr->index = value;
}
