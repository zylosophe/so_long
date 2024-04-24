/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:05:30 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/23 20:48:18 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "display_utils.h"

void	display_init(void)
{
	t_image *const	screenbuf = get_screenbuf();
	int				i;

	i = 0;
	while (i < NB_ASSETS)
	{
		load_xpm_file_with_alpha(i);
		i++;
	}
	screenbuf->img = mlx_new_image(g_env.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!screenbuf->img)
		error_err("on mlx_new_image()");
	screenbuf->width = WINDOW_WIDTH;
	screenbuf->height = WINDOW_HEIGHT;
	screenbuf->data = get_data_addr(screenbuf->img);
	display_erase();
}

void	display_erase(void)
{
	t_pixel *const		screenbuf_data = get_screenbuf()->data;
	const unsigned int	black = 0x00000000;
	int					i;

	i = -1;
	while (++i < WINDOW_WIDTH * WINDOW_HEIGHT)
		screenbuf_data[i] = black;
}

void	display_flush(void)
{
	mlx_put_image_to_window(g_env.mlx, g_env.win, get_screenbuf()->img, 0, 0);
}

void	display_destroyall(void)
{
	t_image *const	screenbuf = get_screenbuf();
	const t_image	*allassets = *get_allassets();
	int				i;
	void			*img;

	i = 0;
	while (i < NB_ASSETS)
	{
		img = allassets[i].img;
		if (img)
			mlx_destroy_image(g_env.mlx, img);
		i++;
	}
	if (screenbuf->img)
		mlx_destroy_image(g_env.mlx, screenbuf->img);
	if (g_env.win)
		mlx_destroy_window(g_env.mlx, g_env.win);
	if (g_env.mlx)
		free(g_env.mlx);
}
