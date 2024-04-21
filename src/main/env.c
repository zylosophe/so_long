/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:32:36 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/21 17:53:00 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

t_env			g_env;

const t_consts	g_consts = {
	roomcases: {
{c: '0', object: NULL, surface: CASE_FLOOR_1},
{c: '1', object: wall_init, surface: CASE_FLOOR_1},
{c: 'P', object: snas_init, surface: CASE_FLOOR_1},
{c: 'C', object: ketchup_init, surface: CASE_FLOOR_1},
{c: 'E', object: exit_init, surface: CASE_FLOOR_1},
{c: 'F', object: firsk_init, surface: CASE_FLOOR_1},
{c: 'B', object: NULL, surface: CASE_BRIDGE},
{c: 'A', object: activablewall_init, surface: CASE_FLOOR_1},
{c: 'U', object: ultimateketchup_init, surface: CASE_FLOOR_1},
{c: '\0'}
},
	levels: {
	"rooms/01.ber",
	"rooms/02.ber",
	"rooms/03.ber",
	"rooms/04.ber",
	"rooms/05.ber",
	"rooms/06.ber",
	"rooms/07.ber",
	"rooms/08.ber",
	"rooms/09.ber",
	"rooms/10.ber",
},
	assetsmap: {
{"floor/1", 50, 100, 50, 125, true},
{"floor/2", 50, 100, 50, 125, true},
	// WALL
{"wall/border_top", 50, 100, 50, 125, true},
{"wall/border_bottom", 50, 100, 50, 100, true},
{"wall/inner", 50, 100, 30, 100, false},
	// BRIDGE
{"wall/bridge", 50, 100, 50, 125, false},
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
{"object/exit/tp/1", 50, 100, 30, 100, false},
{"object/exit/tp/2", 50, 100, 30, 100, false},
{"object/exit/tp/3", 50, 100, 30, 100, false},
{"object/exit/tp/4", 50, 100, 30, 100, false},
{"object/exit/tp/5", 50, 100, 30, 100, false},
{"object/exit/tp/6", 50, 100, 30, 100, false},
{"object/exit/tp/7", 50, 100, 30, 100, false},
{"object/exit/tp/8", 50, 100, 30, 100, false},
{"object/exit/tp/9", 50, 100, 30, 100, false},
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
	// ultimate ketchup
{"object/ultimateketchup/1", 0, 900, 0, 900, false},
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
	// little
{"text/little/0", 0, 600, 0, 400, false},
{"text/little/1", 0, 600, 0, 400, false},
{"text/little/2", 0, 600, 0, 400, false},
{"text/little/3", 0, 600, 0, 400, false},
{"text/little/4", 0, 600, 0, 400, false},
{"text/little/5", 0, 600, 0, 400, false},
{"text/little/6", 0, 600, 0, 400, false},
{"text/little/7", 0, 600, 0, 400, false},
{"text/little/8", 0, 600, 0, 400, false},
{"text/little/9", 0, 600, 0, 400, false},
{"text/little/pressentertoretry", 0, 600, 0, 400, false},
	// regular
{"text/regular/0", 0, 600, 0, 400, false},
{"text/regular/1", 0, 600, 0, 400, false},
{"text/regular/2", 0, 600, 0, 400, false},
{"text/regular/3", 0, 600, 0, 400, false},
{"text/regular/4", 0, 600, 0, 400, false},
{"text/regular/5", 0, 600, 0, 400, false},
{"text/regular/6", 0, 600, 0, 400, false},
{"text/regular/7", 0, 600, 0, 400, false},
{"text/regular/8", 0, 600, 0, 400, false},
{"text/regular/9", 0, 600, 0, 400, false},
{"text/regular/in_x_moves_1", 0, 600, 0, 400, false},
{"text/regular/in_x_moves_2", 0, 600, 0, 400, false},
{"text/regular/youded", 0, 600, 0, 400, false},
{"text/regular/youfoundtheultimateketchup_1", 0, 600, 0, 400, false},
{"text/regular/youfoundtheultimateketchup_2", 0, 600, 0, 400, false},
	// big
{"text/big/youwin", 0, 600, 0, 400, false},
{"text/big/gameover", 0, 600, 0, 400, false},
},
	spritesmap: {
{WALL_BORDER_TOP, 50, 50, ANIMATION, 1, 1},
{WALL_BORDER_BOTTOM, 50, 50, ANIMATION, 1, 1},
{FLOOR_1, 50, 50, ANIMATION, 1, 1},
{FLOOR_2, 50, 50, ANIMATION, 1, 1},
{BRIDGE, 50, 50, ANIMATION, 1, 1},
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
{OBJECT_EXIT_ACTIVE_1, 50, 50, ANIMATION_ONCE, 2, 2},
{OBJECT_EXIT_TP_1, 50, 50, ANIMATION_ONCE, 9, 1},
{OBJECT_FIRSK, 50, 50, CHARACTER_STILL, 0, 0},
{OBJECT_FIRSK_WALK_DOWN_1, 50, 50, ANIMATION, 4, 3},
{OBJECT_FIRSK_WALK_UP_1, 50, 50, ANIMATION, 4, 3},
{OBJECT_FIRSK_WALK_RIGHT_1, 50, 50, ANIMATION, 2, 3},
{OBJECT_FIRSK_WALK_LEFT_1, 50, 50, ANIMATION, 2, 3},
{OBJECT_ULTIMATEKETCHUP, 300, 300, ANIMATION, 1, 1},
{ANIM_KNIFEATTACK_1, 50, 50, ANIMATION_ONCE, 7, 2},
{ANIM_EXPLOSION_PART1_1, 23, 50, ANIMATION_ONCE, 8, 1},
{ANIM_EXPLOSION_PART2_1, 23, 50, ANIMATION_ONCE, 9, 1},
},
};