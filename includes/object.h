/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:58:25 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/28 17:51:55 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "point.h"
# include "data_assets.h"
# include "libtf.h"
# include "display.h"
# include "sprite.h"

/**** OBJECT ****/
typedef struct s_object	t_object;

typedef struct s_objecttype
{
	t_point	(*loop)(t_object *, t_point pos);
	void	(*draw)(t_object *, int x, int y);
}			t_objecttype;

typedef struct s_object
{
	t_objecttype	type;
	void			*data;
}						t_object;

typedef t_object		(*t_object_init)(t_memclass);

/**** CHARACTER ****/
typedef struct s_character_sprites
{
	t_spriteid	still;
	t_spriteid	walk_left;
	t_spriteid	walk_right;
	t_spriteid	walk_up;
	t_spriteid	walk_down;
}						t_character_sprites;

typedef struct s_character
{
	t_direction			direction;
	t_sprite			spr;
	int					walk_remaining_steps;
	t_character_sprites	*sprites;
}	t_character;

void			character_draw(t_character *character, int x, int y);
t_point			character_loop(t_character *character, t_point pos,
					t_direction (*brain)(void));
t_character		character_init(t_character_sprites *sprites);

/**** SNAS ****/
typedef struct s_snas_data
{
	t_character	character;
}				t_snas_data;

t_object		snas_init(t_memclass mc);

#endif
