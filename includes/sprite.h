/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:13:20 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/15 19:55:46 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "data_assets.h"
# include "data_sprites.h"

typedef struct s_sprite
{
	const t_spriteinfo	*info;
	int					index;
}						t_sprite;

t_sprite	sprite_init(t_spriteid spr);

void		sprite_draw(int x, int y, t_sprite *spr);

#endif
