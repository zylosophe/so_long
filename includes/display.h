/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:32:08 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/06 14:20:39 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include <stdint.h>
# include "libtf.h"
# include "assets.h"

typedef uint32_t		t_pixel;
typedef uint8_t			t_component;

typedef struct s_asset
{
	t_const_string	src;
	int				limit_left;
	int				limit_right;
	int				limit_up;
	int				limit_down;
	bool			opaque;
}	t_asset;

typedef struct s_image
{
	int		width;
	int		height;
	t_asset	asset;
	void	*img;
	t_pixel	*data;
}			t_image;

extern const t_asset	g_assetsmap[];

/**
 * Load all assets at the start of the program and prepare the screen buffer.
 */
void	display_init(void);

/**
 * Fill the buffer with black.
 */
void	display_erase(void);

/**
 * Draw an image somewhere in the window.
 * You must call display_flush() after drawing all images.
 * x,y is the top-left position of the image.
 */
void	display_draw(int x, int y, t_assetid asset);

/**
 * Draw all the screen in the buffer.
 */
void	display_flush(void);

/**
 * Destroy all assets and the screen buffer before finishing the program.
 */
void	display_destroyall(void);

#endif
