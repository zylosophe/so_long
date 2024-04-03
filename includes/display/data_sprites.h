/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sprites.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:56:31 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/03 15:53:40 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_SPRITES_H
# define DATA_SPRITES_H

# define NB_SPRITES 11

typedef enum e_spritetype
{
	ANIMATION, // loops through all the sprites
	ANIMATION_ONCE, // loops through all the sprites but only once
	CHARACTER_STILL, // down up left and right positions
}	t_spritetype;

typedef struct s_spritemeta
{
	t_assetsmap_id	first_frame;
	int				origin_x;
	int				origin_y;
	t_spritetype	type;
	int				nb_frames;
	int				delay_frame;
}					t_spritemeta;

extern const t_spritemeta	g_spritesmap[NB_SPRITES];

typedef enum e_spritesmap_id
{
	CASE_WALL,
	CASE_FLOOR_1,
	CASE_FLOOR_2,
	SPR_SNAS,
	SPR_SNAS_DOWN,
	SPR_SNAS_UP,
	SPR_SNAS_LEFT,
	SPR_SNAS_RIGHT,
	SPR_WALL,
	SPR_KETCHUP,
	SPR_KETCHUP_FADE,
}	t_spritesmap_id;

#endif
