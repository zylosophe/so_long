/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:02:29 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/17 17:49:13 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

const t_spritemeta	g_spritesmap[NB_SPRITES] = {
{WALL_BORDER_TOP, 50, 50, ANIMATION, 1, 1},
{WALL_BORDER_BOTTOM, 50, 50, ANIMATION, 1, 1},
{FLOOR_1, 50, 50, ANIMATION, 1, 1},
{FLOOR_2, 50, 50, ANIMATION, 1, 1},
{OBJECT_SNAS, 50, 50, CHARACTER_STILL, 0, 0},
{OBJECT_SNAS_WALK_DOWN_1, 50, 50, ANIMATION, 4, 3},
{OBJECT_SNAS_WALK_UP_1, 50, 50, ANIMATION, 4, 3},
{OBJECT_SNAS_WALK_RIGHT_1, 50, 50, ANIMATION, 2, 3},
{OBJECT_SNAS_WALK_LEFT_1, 50, 50, ANIMATION, 2, 3},
{WALL_INNER, 50, 50, ANIMATION, 1, 1},
{OBJECT_KETCHUP_STILL_1, 50, 50, ANIMATION, 4, 4},
{OBJECT_KETCHUP_FADE_1, 50, 50, ANIMATION_ONCE, 3, 1},
{OBJECT_EXIT_INACTIVE_1, 50, 50, ANIMATION, 2, 4},
{OBJECT_EXIT_ACTIVE_1, 50, 50, ANIMATION, 4, 2},
{OBJECT_EXIT_USING1_1, 50, 50, ANIMATION_ONCE, 11, 1},
{OBJECT_FIRSK, 50, 50, CHARACTER_STILL, 0, 0},
{OBJECT_FIRSK_WALK_DOWN_1, 50, 50, ANIMATION, 4, 3},
{OBJECT_FIRSK_WALK_UP_1, 50, 50, ANIMATION, 4, 3},
{OBJECT_FIRSK_WALK_RIGHT_1, 50, 50, ANIMATION, 2, 3},
{OBJECT_FIRSK_WALK_LEFT_1, 50, 50, ANIMATION, 2, 3},
{ANIM_KNIFEATTACK_1, 50, 50, ANIMATION_ONCE, 7, 2},
{ANIM_EXPLOSION_PART1_1, 23, 50, ANIMATION_ONCE, 8, 1},
{ANIM_EXPLOSION_PART2_1, 23, 50, ANIMATION_ONCE, 9, 1},
{TEXT_GAMEOVER, 0, 0, ANIMATION, 1, 1},
{TEXT_YOUDED, 0, 0, ANIMATION, 1, 1},
};
