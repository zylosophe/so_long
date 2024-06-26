/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sprites.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:56:31 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/21 15:25:26 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_SPRITES_H
# define DATA_SPRITES_H

# define NB_SPRITES 26

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

typedef enum e_spritesmap_id
{
	CASE_BORDER_TOP,
	CASE_BORDER_BOTTOM,
	CASE_FLOOR_1,
	CASE_FLOOR_2,
	CASE_BRIDGE,
	SPR_SNAS,
	SPR_SNAS_WALK_DOWN,
	SPR_SNAS_WALK_UP,
	SPR_SNAS_WALK_RIGHT,
	SPR_SNAS_WALK_LEFT,
	SPR_WALL,
	SPR_KETCHUP,
	SPR_KETCHUP_FADE,
	SPR_EXIT_INACTIVE,
	SPR_EXIT_ACTIVE,
	SPR_EXIT_REMAINING,
	SPR_EXIT_TP,
	SPR_FIRSK,
	SPR_FIRSK_WALK_DOWN,
	SPR_FIRSK_WALK_UP,
	SPR_FIRSK_WALK_RIGHT,
	SPR_FIRSK_WALK_LEFT,
	SPR_ULTIMATEKETCHUP,
	SPR_KNIFEATTACK,
	SPR_EXPLOSION_1,
	SPR_EXPLOSION_2,
}	t_spritesmap_id;

#endif
