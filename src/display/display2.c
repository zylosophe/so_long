/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:05:30 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/20 14:03:28 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "display_utils.h"

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

static inline t_imglimits	get_limits(t_point p, t_image img)
{
	t_imglimits	r;

	r.xmin = fmax(-p.x, fmax(img.asset.limit_left, 0));
	r.xmax = fmin(WINDOW_WIDTH - p.x, fmin(img.asset.limit_right, img.width));
	r.ymin = fmax(-p.y, fmax(img.asset.limit_up, 0));
	r.ymax = fmin(WINDOW_HEIGHT - p.y, fmin(img.asset.limit_down, img.height));
	return (r);
}

static inline void	display_draw_alpha(t_point p, t_image img)
{
	const t_image		*screenbuf = get_screenbuf();
	const t_imglimits	limits = get_limits(p, img);
	int					img_x;
	int					img_y;

	img_y = limits.ymin;
	while (img_y < limits.ymax)
	{
		img_x = limits.xmin;
		while (img_x < limits.xmax)
		{
			add_color(
				&screenbuf->data[(p.y + img_y) * WINDOW_WIDTH + (p.x + img_x)],
				img.data[img_y * img.width + img_x]);
			img_x++;
		}
		img_y++;
	}
}

static inline void	display_draw_opaque(t_point p, t_image img)
{
	const t_image		*screenbuf = get_screenbuf();
	const t_imglimits	limits = get_limits(p, img);
	int					img_x;
	int					img_y;

	img_y = limits.ymin;
	while (img_y < limits.ymax)
	{
		img_x = limits.xmin;
		while (img_x < limits.xmax)
		{
			screenbuf->data[(p.y + img_y) * WINDOW_WIDTH + (p.x + img_x)]
				= img.data[img_y * img.width + img_x];
			img_x++;
		}
		img_y++;
	}
}

void	display_draw(t_point p, t_assetsmap_id asset)
{
	const t_image	img = (*get_allassets())[asset];

	if (img.asset.opaque)
		display_draw_opaque(p, img);
	else
		display_draw_alpha(p, img);
}
