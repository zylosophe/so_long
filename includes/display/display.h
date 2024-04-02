/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:32:08 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/02 17:26:51 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

typedef struct s_image
{
	int			width;
	int			height;
	t_assetmeta	asset;
	void		*img;
	t_pixel		*data;
}				t_image;

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
void	display_draw(int x, int y, t_assetsmap_id asset);

/**
 * Draw all the screen in the buffer.
 */
void	display_flush(void);

/**
 * Destroy all assets and the screen buffer before finishing the program.
 */
void	display_destroyall(void);

#endif
