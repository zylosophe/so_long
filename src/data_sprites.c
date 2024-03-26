/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:02:29 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/29 14:32:57 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_sprites.h"

const t_spriteinfo	g_spritesmap[NB_SPRITES] = {
{WALL_BORDER, 1, 50, 50, ANIMATION},
{FLOOR_1, 1, 50, 50, ANIMATION},
{OBJECT_SNAS, 0, 50, 50, CHARACTER_STILL},
{OBJECT_SNAS_DOWN, 1, 50, 50, ANIMATION},
{OBJECT_SNAS_UP, 1, 50, 50, ANIMATION},
{OBJECT_SNAS_LEFT, 1, 50, 50, ANIMATION},
{OBJECT_SNAS_RIGHT, 1, 50, 50, ANIMATION},
};
