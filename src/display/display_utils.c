/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:03:30 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/18 17:10:46 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

t_image	g_allassets[NB_ASSETS];
t_image	g_screenbuf;

t_pixel	*get_data_addr(void *img)
{
	int		bpp;
	int		size_line;
	int		endian;
	t_pixel	*r;

	r = (t_pixel *)mlx_get_data_addr(img, &bpp, &size_line, &endian);
	if (!r || bpp != 32 || endian != 0)
		error_err("wrong image format");
	return (r);
}

void	apply_mask_to_image(void *img, void *mask, int nb_px)
{
	const t_pixel	*addr_img = get_data_addr(img);
	const t_pixel	*addr_mask = get_data_addr(mask);
	int				i;

	i = -1;
	while (++i < nb_px)
		((t_component *)(addr_img + i))[3]
			= 255 - ((t_component *)(addr_mask + i))[1];
}

void	load_xpm_file_with_alpha(int i)
{
	t_string			tmp;
	t_string			src;
	t_string			src_mask;
	void				*mask;

	tmp = str_join(error_err, g_env.mc, "assets/", g_assetsmap[i].src);
	src = str_join(error_err, g_env.mc, tmp, ".xpm");
	src_mask = str_join(error_err, g_env.mc, tmp, ".alpha.xpm");
	g_allassets[i].img = mlx_xpm_file_to_image(g_env.mlx, src,
			&(g_allassets[i].width), &g_allassets[i].height);
	if (!g_allassets[i].img)
		error_str(g_assetsmap[i].src, "image loading failed");
	mask = mlx_xpm_file_to_image(g_env.mlx, src_mask,
			&(g_allassets[i].width), &g_allassets[i].height);
	if (!mask)
		error_str(g_assetsmap[i].src, "image loading failed");
	apply_mask_to_image(g_allassets[i].img, mask,
		g_allassets[i].width * g_allassets[i].height);
	mlx_destroy_image(g_env.mlx, mask);
	g_allassets[i].data = get_data_addr(g_allassets[i].img);
	g_allassets[i].asset = g_assetsmap[i];
	mem_free(tmp);
	mem_free(src);
	mem_free(src_mask);
}
