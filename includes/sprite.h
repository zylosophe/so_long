/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:13:20 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/28 15:59:30 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "data_assets.h"
# include "data_sprites.h"

typedef struct s_sprite
{
	t_spriteinfo	*info;
	int				index;
}					t_sprite;

t_sprite	sprite_init(t_spriteid spr);

void		sprite_draw(int x, int y, t_sprite *spr);

void		sprite_character_set_direction(t_sprite *spr, t_direction value);

#endif
