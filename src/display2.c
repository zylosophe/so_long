/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:05:30 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/06 13:40:18 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "display_utils.h"
#include "env.h"
#include "error.h"
#include "mlx.h"
#include "libtf.h"
#include <stdlib.h>

static inline void	add_color(t_pixel *dest, t_pixel src)
{
	const uint16_t	transparency = (uint8_t)(src >> 24);
	const uint16_t	opacity = (uint8_t) ~ transparency;
	const t_pixel	dest_value = *dest;

	*dest = (
			(uint8_t)(dest_value >> 16) * transparency
			+ (uint8_t)(src >> 16) * opacity)
		>> 8 << 16
		| (
			(uint8_t)(dest_value >> 8) * transparency
			+ (uint8_t)(src >> 8) * opacity)
		>> 8 << 8
		| (
			(uint8_t)(dest_value >> 0) * transparency
			+ (uint8_t)(src >> 0) * opacity)
		>> 8;
}

static inline t_imglimits	get_limits(int x, int y, t_image img)
{
	t_imglimits	r;

	r.xmin = -x;
	if (img.asset.limit_left > r.xmin)
		r.xmin = img.asset.limit_left;
	r.xmax = WINDOW_WIDTH - x;
	if (img.asset.limit_right < r.xmax)
		r.xmax = img.asset.limit_right;
	r.ymin = -y;
	if (img.asset.limit_up > r.ymin)
		r.ymin = img.asset.limit_up;
	r.ymax = WINDOW_HEIGHT - y;
	if (img.asset.limit_down < r.ymax)
		r.ymax = img.asset.limit_down;
	return (r);
}

static inline void	display_draw_alpha(int x, int y, t_image img)
{
	const t_imglimits	limits = get_limits(x, y, img);
	int					img_x;
	int					img_y;

	img_y = limits.ymin;
	while (img_y < limits.ymax)
	{
		img_x = limits.xmin;
		while (img_x < limits.xmax)
		{
			add_color(
				&g_screenbuf.data[(y + img_y) * WINDOW_WIDTH + (x + img_x)],
				img.data[img_y * img.width + img_x]);
			img_x++;
		}
		img_y++;
	}
}

static inline void	display_draw_opaque(int x, int y, t_image img)
{
	const t_imglimits	limits = get_limits(x, y, img);
	int					img_x;
	int					img_y;

	img_y = limits.ymin;
	while (img_y < limits.ymax)
	{
		img_x = limits.xmin;
		while (img_x < limits.xmax)
		{
			g_screenbuf.data[(y + img_y) * WINDOW_WIDTH + (x + img_x)]
				= img.data[img_y * img.width + img_x];
			img_x++;
		}
		img_y++;
	}
}

void	display_draw(int x, int y, t_assetid asset)
{
	const t_image	img = g_allassets[asset];

	if (img.asset.opaque)
		display_draw_opaque(x, y, img);
	else
		display_draw_alpha(x, y, img);
}
