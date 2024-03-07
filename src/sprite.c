/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:28:52 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/11 16:36:45 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"
#include "display.h"

t_sprite	sprite_init(t_spriteid id)
{
	t_sprite	r;

	r.info = g_spritesmap + id;
	r.index = 0;
	return (r);
}

void	sprite_draw(int x, int y, t_sprite *spr)
{
	display_draw(
		x - spr->info->origin_x, y - spr->info->origin_y,
		spr->info->first_frame + spr->index);
	spr->index++;
	if (spr->index >= spr->info->nb_frames)
		spr->index = 0;
}
