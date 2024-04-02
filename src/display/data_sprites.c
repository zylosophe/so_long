/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:02:29 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/02 17:37:34 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

const t_spritemeta	g_spritesmap[NB_SPRITES] = {
{WALL_BORDER, 1, 50, 50, ANIMATION},
{FLOOR_1, 1, 50, 50, ANIMATION},
{FLOOR_2, 1, 50, 50, ANIMATION},
{OBJECT_SNAS, 0, 50, 50, CHARACTER_STILL},
{OBJECT_SNAS_DOWN, 1, 50, 50, ANIMATION},
{OBJECT_SNAS_UP, 1, 50, 50, ANIMATION},
{OBJECT_SNAS_LEFT, 1, 50, 50, ANIMATION},
{OBJECT_SNAS_RIGHT, 1, 50, 50, ANIMATION},
{WALL_INNER, 1, 50, 50, ANIMATION},
};
