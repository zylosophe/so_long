/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sprites.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:56:31 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/02 17:38:37 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_SPRITES_H
# define DATA_SPRITES_H

# define NB_SPRITES 9

typedef enum e_spritetype
{
	ANIMATION, // loops through all the sprites
	CHARACTER_STILL, // down up left and right positions
}	t_spritetype;

typedef struct s_spritemeta
{
	t_assetsmap_id	first_frame;
	int				nb_frames;
	int				origin_x;
	int				origin_y;
	t_spritetype	type;
}					t_spritemeta;

extern const t_spritemeta	g_spritesmap[NB_SPRITES];

typedef enum e_spritesmap_id
{
	CASE_WALL,
	CASE_FLOOR_1,
	CASE_FLOOR_2,
	SPR_SNAS,
	SPR_SNAS_DOWN,
	SPR_SNAS_UP,
	SPR_SNAS_LEFT,
	SPR_SNAS_RIGHT,
	SPR_WALL,
}	t_spritesmap_id;

#endif
