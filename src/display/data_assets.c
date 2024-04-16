/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:27:06 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/17 17:50:28 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

/**
 * Path of each asset relative to assets/, without extension.
 */
const t_assetmeta	g_assetsmap[NB_ASSETS] = {
{"floor/1", 50, 100, 50, 100, true},
{"floor/2", 50, 100, 50, 100, true},
	// WALL
{"wall/border_top", 50, 100, 50, 100, true},
{"wall/border_bottom", 50, 100, 50, 100, true},
{"wall/inner", 50, 100, 30, 100, false},
	// OBJECTS
	// snas
{"object/snas/down", 50, 100, 30, 100, false},
{"object/snas/up", 50, 100, 30, 100, false},
{"object/snas/left", 50, 100, 30, 100, false},
{"object/snas/right", 50, 100, 30, 100, false},
{"object/snas/walk_down_1", 50, 100, 30, 100, false},
{"object/snas/walk_down_2", 50, 100, 30, 100, false},
{"object/snas/walk_down_3", 50, 100, 30, 100, false},
{"object/snas/walk_down_4", 50, 100, 30, 100, false},
{"object/snas/walk_right_1", 50, 100, 30, 100, false},
{"object/snas/walk_right_2", 50, 100, 30, 100, false},
{"object/snas/walk_left_1", 50, 100, 30, 100, false},
{"object/snas/walk_left_2", 50, 100, 30, 100, false},
{"object/snas/walk_up_1", 50, 100, 30, 100, false},
{"object/snas/walk_up_2", 50, 100, 30, 100, false},
{"object/snas/walk_up_3", 50, 100, 30, 100, false},
{"object/snas/walk_up_4", 50, 100, 30, 100, false},
	// ketchup
{"object/ketchup/still/1", 50, 100, 40, 110, false},
{"object/ketchup/still/2", 50, 100, 40, 110, false},
{"object/ketchup/still/3", 50, 100, 40, 110, false},
{"object/ketchup/still/4", 50, 100, 40, 110, false},
{"object/ketchup/fade/1", 50, 100, 40, 110, false},
{"object/ketchup/fade/2", 50, 100, 30, 120, false},
{"object/ketchup/fade/3", 50, 100, 20, 130, false},
	// exit
{"object/exit/inactive/1", 50, 100, 50, 100, false},
{"object/exit/inactive/2", 50, 100, 50, 100, false},
{"object/exit/active/1", 50, 100, 50, 100, false},
{"object/exit/active/2", 50, 100, 50, 100, false},
{"object/exit/active/3", 50, 100, 50, 100, false},
{"object/exit/active/4", 50, 100, 50, 100, false},
{"object/exit/using1/1", 50, 100, 50, 100, false},
{"object/exit/using1/2", 50, 100, 50, 100, false},
{"object/exit/using1/3", 50, 100, 50, 100, false},
{"object/exit/using1/4", 50, 100, 50, 100, false},
{"object/exit/using2/1", 40, 110, 40, 110, false},
{"object/exit/using2/2", 40, 110, 40, 110, false},
{"object/exit/using2/3", 30, 120, 30, 120, false},
{"object/exit/using2/4", 50, 100, 50, 100, false},
{"object/exit/using2/5", 50, 100, 50, 100, false},
{"object/exit/using2/6", 50, 100, 50, 100, false},
{"object/exit/using2/7", 50, 100, 50, 100, false},
	// firsk
{"object/firsk/down", 50, 110, 30, 100, false},
{"object/firsk/up", 40, 100, 30, 100, false},
{"object/firsk/left", 50, 100, 30, 100, false},
{"object/firsk/right", 50, 110, 30, 100, false},
{"object/firsk/walk_down_1", 50, 110, 30, 100, false},
{"object/firsk/walk_down_2", 50, 110, 30, 100, false},
{"object/firsk/walk_down_3", 50, 110, 30, 100, false},
{"object/firsk/walk_down_4", 50, 110, 30, 100, false},
{"object/firsk/walk_right_1", 50, 110, 30, 100, false},
{"object/firsk/walk_right_2", 50, 110, 30, 100, false},
{"object/firsk/walk_left_1", 50, 100, 30, 100, false},
{"object/firsk/walk_left_2", 50, 100, 30, 100, false},
{"object/firsk/walk_up_1", 40, 100, 30, 100, false},
{"object/firsk/walk_up_2", 40, 100, 30, 100, false},
{"object/firsk/walk_up_3", 40, 100, 30, 100, false},
{"object/firsk/walk_up_4", 40, 100, 30, 100, false},
	// ANIM
	// knife attack
{"anim/knifeattack_1", 50, 100, 40, 110, false},
{"anim/knifeattack_2", 50, 100, 40, 110, false},
{"anim/knifeattack_3", 50, 100, 40, 110, false},
{"anim/knifeattack_4", 50, 100, 40, 110, false},
{"anim/knifeattack_5", 50, 100, 40, 110, false},
{"anim/knifeattack_6", 50, 100, 40, 110, false},
{"anim/knifeattack_7", 50, 100, 40, 110, false},
	// explosion
{"anim/explosion_part1_1", 0, 100, 0, 141, false},
{"anim/explosion_part1_2", 0, 100, 0, 141, false},
{"anim/explosion_part1_3", 0, 100, 0, 141, false},
{"anim/explosion_part1_4", 0, 100, 0, 141, false},
{"anim/explosion_part1_5", 0, 100, 0, 141, false},
{"anim/explosion_part1_6", 0, 100, 0, 141, false},
{"anim/explosion_part1_7", 0, 100, 0, 141, false},
{"anim/explosion_part1_8", 0, 100, 0, 141, false},
{"anim/explosion_part2_1", 0, 100, 0, 141, false},
{"anim/explosion_part2_2", 0, 100, 0, 141, false},
{"anim/explosion_part2_3", 0, 100, 0, 141, false},
{"anim/explosion_part2_4", 0, 100, 0, 141, false},
{"anim/explosion_part2_5", 0, 100, 0, 141, false},
{"anim/explosion_part2_6", 0, 100, 0, 141, false},
{"anim/explosion_part2_7", 0, 100, 0, 141, false},
{"anim/explosion_part2_8", 0, 100, 0, 141, false},
{"anim/explosion_part2_9", 0, 100, 0, 141, false},
	// TEXT
{"text/gameover", 100, 510, 120, 190, false},
{"text/youded", 240, 360, 230, 280, false},
};
