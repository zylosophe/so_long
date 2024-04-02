/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:13:20 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/02 17:37:12 by mcolonna         ###   ########.fr       */
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

void		sprite_draw(int x, int y, t_sprite *spr);

void		sprite_character_set_direction(t_sprite *spr, t_direction value);

#endif
