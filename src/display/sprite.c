/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:28:52 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/20 13:26:08 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

t_sprite	sprite_init(t_spritesmap_id id)
{
	t_sprite	r;

	r.meta = (t_spritemeta *)(g_consts.spritesmap + id);
	r.index = 0;
	return (r);
}

bool	sprite_draw(t_point p, t_sprite *spr)
{
	if (spr->meta->type == ANIMATION || spr->meta->type == ANIMATION_ONCE)
	{
		display_draw(
			point_init(p.x - spr->meta->origin_x, p.y - spr->meta->origin_y),
			spr->meta->first_frame + spr->index / spr->meta->delay_frame);
		spr->index++;
		if (spr->index >= spr->meta->nb_frames * spr->meta->delay_frame)
		{
			if (spr->meta->type == ANIMATION_ONCE)
				return (false);
			spr->index = 0;
		}
	}
	else
		display_draw(
			point_init(p.x - spr->meta->origin_x, p.y - spr->meta->origin_y),
			spr->meta->first_frame + spr->index);
	return (true);
}

void	sprite_character_set_direction(t_sprite *spr, t_direction value)
{
	if (spr->meta->type != CHARACTER_STILL)
		error_err("the sprite must be a CHARACTER_STILL sprite.");
	spr->index = value;
}
