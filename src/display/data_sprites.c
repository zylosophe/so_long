/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:02:29 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/05 18:45:02 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

const t_spritemeta	g_spritesmap[NB_SPRITES] = {
{WALL_BORDER, 50, 50, ANIMATION, 1, 1},
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
};
