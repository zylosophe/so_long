/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sprites.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:56:31 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/15 18:49:12 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_SPRITES_H
# define DATA_SPRITES_H

# include "data_assets.h"

# define NB_SPRITES 3

typedef struct s_spriteinfo
{
	t_assetid	first_frame;
	int			nb_frames;
	int			origin_x;
	int			origin_y;
}				t_spriteinfo;

extern const t_spriteinfo	g_spritesmap[NB_SPRITES];

typedef enum e_spriteid
{
	CASE_WALL,
	CASE_FLOOR,
	SPR_SNAS_DOWN
}	t_spriteid;

#endif