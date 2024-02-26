/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:59:24 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/06 13:47:02 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_UTILS_H
# define DISPLAY_UTILS_H

# include "display.h"

extern t_image		g_allassets[NB_ASSETS];
extern t_image		g_screenbuf;

typedef struct s_imglimits
{
	int	xmin;
	int	xmax;
	int	ymin;
	int	ymax;
}		t_imglimits;

t_pixel	*get_data_addr(void *img);

void	apply_mask_to_image(void *img, void *mask, int nb_px);

void	load_xpm_file_with_alpha(int i);

#endif
