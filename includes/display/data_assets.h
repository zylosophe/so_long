/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_assets.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:43:01 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/18 17:05:31 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_ASSETS_H
# define DATA_ASSETS_H

# define NB_ASSETS 97

typedef struct s_assetmeta
{
	t_const_string	src;
	int				limit_left;
	int				limit_right;
	int				limit_up;
	int				limit_down;
	bool			opaque;
}	t_assetmeta;

extern const t_assetmeta	g_assetsmap[NB_ASSETS];

/**
 * Index for each asset. Must be in the same order than g_assetsmap.
 * The frames of an animation must be together and sorted.
 * The images of an object with directions must be in this order:
 *   down, up, left, right
 */
typedef enum e_assetsmap_id
{
	FLOOR_1,
	FLOOR_2,
	WALL_BORDER_TOP,
	WALL_BORDER_BOTTOM,
	WALL_INNER,
	BRIDGE,
	OBJECT_SNAS_DOWN,
	OBJECT_SNAS_UP,
	OBJECT_SNAS_LEFT,
	OBJECT_SNAS_RIGHT,
	OBJECT_SNAS_WALK_DOWN_1,
	OBJECT_SNAS_WALK_DOWN_2,
	OBJECT_SNAS_WALK_DOWN_3,
	OBJECT_SNAS_WALK_DOWN_4,
	OBJECT_SNAS_WALK_RIGHT_1,
	OBJECT_SNAS_WALK_RIGHT_2,
	OBJECT_SNAS_WALK_LEFT_1,
	OBJECT_SNAS_WALK_LEFT_2,
	OBJECT_SNAS_WALK_UP_1,
	OBJECT_SNAS_WALK_UP_2,
	OBJECT_SNAS_WALK_UP_3,
	OBJECT_SNAS_WALK_UP_4,
	OBJECT_KETCHUP_STILL_1,
	OBJECT_KETCHUP_STILL_2,
	OBJECT_KETCHUP_STILL_3,
	OBJECT_KETCHUP_STILL_4,
	OBJECT_KETCHUP_FADE_1,
	OBJECT_KETCHUP_FADE_2,
	OBJECT_KETCHUP_FADE_3,
	OBJECT_EXIT_INACTIVE_1,
	OBJECT_EXIT_INACTIVE_2,
	OBJECT_EXIT_ACTIVE_1,
	OBJECT_EXIT_ACTIVE_2,
	OBJECT_EXIT_ACTIVE_3,
	OBJECT_EXIT_ACTIVE_4,
	OBJECT_EXIT_USING1_1,
	OBJECT_EXIT_USING1_2,
	OBJECT_EXIT_USING1_3,
	OBJECT_EXIT_USING1_4,
	OBJECT_EXIT_USING2_1,
	OBJECT_EXIT_USING2_2,
	OBJECT_EXIT_USING2_3,
	OBJECT_EXIT_USING2_4,
	OBJECT_EXIT_USING2_5,
	OBJECT_EXIT_USING2_6,
	OBJECT_EXIT_USING2_7,
	OBJECT_EXIT_TP_1,
	OBJECT_EXIT_TP_2,
	OBJECT_EXIT_TP_3,
	OBJECT_EXIT_TP_4,
	OBJECT_EXIT_TP_5,
	OBJECT_EXIT_TP_6,
	OBJECT_EXIT_TP_7,
	OBJECT_EXIT_TP_8,
	OBJECT_EXIT_TP_9,
	OBJECT_FIRSK_DOWN,
	OBJECT_FIRSK_UP,
	OBJECT_FIRSK_LEFT,
	OBJECT_FIRSK_RIGHT,
	OBJECT_FIRSK_WALK_DOWN_1,
	OBJECT_FIRSK_WALK_DOWN_2,
	OBJECT_FIRSK_WALK_DOWN_3,
	OBJECT_FIRSK_WALK_DOWN_4,
	OBJECT_FIRSK_WALK_RIGHT_1,
	OBJECT_FIRSK_WALK_RIGHT_2,
	OBJECT_FIRSK_WALK_LEFT_1,
	OBJECT_FIRSK_WALK_LEFT_2,
	OBJECT_FIRSK_WALK_UP_1,
	OBJECT_FIRSK_WALK_UP_2,
	OBJECT_FIRSK_WALK_UP_3,
	OBJECT_FIRSK_WALK_UP_4,
	ANIM_KNIFEATTACK_1,
	ANIM_KNIFEATTACK_2,
	ANIM_KNIFEATTACK_3,
	ANIM_KNIFEATTACK_4,
	ANIM_KNIFEATTACK_5,
	ANIM_KNIFEATTACK_6,
	ANIM_KNIFEATTACK_7,
	ANIM_EXPLOSION_PART1_1,
	ANIM_EXPLOSION_PART1_2,
	ANIM_EXPLOSION_PART1_3,
	ANIM_EXPLOSION_PART1_4,
	ANIM_EXPLOSION_PART1_5,
	ANIM_EXPLOSION_PART1_6,
	ANIM_EXPLOSION_PART1_7,
	ANIM_EXPLOSION_PART1_8,
	ANIM_EXPLOSION_PART2_1,
	ANIM_EXPLOSION_PART2_2,
	ANIM_EXPLOSION_PART2_3,
	ANIM_EXPLOSION_PART2_4,
	ANIM_EXPLOSION_PART2_5,
	ANIM_EXPLOSION_PART2_6,
	ANIM_EXPLOSION_PART2_7,
	ANIM_EXPLOSION_PART2_8,
	ANIM_EXPLOSION_PART2_9,
	TEXT_GAMEOVER,
	TEXT_YOUDED,
}	t_assetsmap_id;

# define OBJECT_SNAS OBJECT_SNAS_DOWN
# define OBJECT_FIRSK OBJECT_FIRSK_DOWN

#endif
