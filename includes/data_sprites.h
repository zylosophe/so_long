/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sprites.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:56:31 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/29 13:55:24 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_SPRITES_H
# define DATA_SPRITES_H

# include "data_assets.h"

# define NB_SPRITES 7

typedef enum e_assettype
{
	ANIMATION, // loops through all the sprites
	CHARACTER_STILL, // down up left and right positions
}	t_assettype;

typedef struct s_spriteinfo
{
	t_assetid	first_frame;
	int			nb_frames;
	int			origin_x;
	int			origin_y;
	t_assettype	type;
}				t_spriteinfo;

extern const t_spriteinfo	g_spritesmap[NB_SPRITES];

typedef enum e_spriteid
{
	CASE_WALL,
	CASE_FLOOR,
	SPR_SNAS,
	SPR_SNAS_DOWN,
	SPR_SNAS_UP,
	SPR_SNAS_LEFT,
	SPR_SNAS_RIGHT,
}	t_spriteid;

#endif
