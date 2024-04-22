/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:46:05 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/15 17:58:02 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

typedef struct s_character_sprites
{
	t_spritesmap_id	still;
	t_spritesmap_id	walk_left;
	t_spritesmap_id	walk_right;
	t_spritesmap_id	walk_up;
	t_spritesmap_id	walk_down;
}						t_character_sprites;

typedef struct s_character
{
	t_direction			direction;
	t_sprite			spr;
	int					walk_remaining_steps;
	int					walk_steps_nb;
	t_character_sprites	*sprites;
}	t_character;

void			character_draw(t_character *character, t_point p);
t_point			character_loop(t_character *character, t_point pos,
					t_direction (*brain)(t_point));
t_character		character_init(t_character_sprites *sprites, int walk_steps_nb);

#endif
