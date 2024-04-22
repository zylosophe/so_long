/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:13:20 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/11 17:06:52 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

typedef struct s_sprite
{
	t_spritemeta	*meta;
	int				index;
}					t_sprite;

t_sprite	sprite_init(t_spritesmap_id spr);

// Return false only if the image drawn was the last (end of the animation).
bool		sprite_draw(t_point p, t_sprite *spr);

void		sprite_character_set_direction(t_sprite *spr, t_direction value);

#endif
