/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:05:30 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/06 13:08:51 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "display_utils.h"
#include "env.h"
#include "error.h"
#include "mlx.h"
#include "libtf.h"
#include <stdlib.h>

void	display_init(void)
{
	int	i;

	i = 0;
	while (i < NB_ASSETS)
	{
		load_xpm_file_with_alpha(i);
		i++;
	}
	g_screenbuf.img = mlx_new_image(g_env.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	g_screenbuf.width = WINDOW_WIDTH;
	g_screenbuf.height = WINDOW_HEIGHT;
	g_screenbuf.data = get_data_addr(g_screenbuf.img);
	display_erase();
}

void	display_erase(void)
{
	const unsigned int	black = 0x00000000;
	int					i;

	i = -1;
	while (++i < WINDOW_WIDTH * WINDOW_HEIGHT)
		g_screenbuf.data[i] = black;
}

void	display_flush(void)
{
	mlx_put_image_to_window(g_env.mlx, g_env.win, g_screenbuf.img, 0, 0);
}

void	display_destroyall(void)
{
	int		i;
	void	*img;

	i = 0;
	while (i < NB_ASSETS)
	{
		img = g_allassets[i].img;
		if (img)
			mlx_destroy_image(g_env.mlx, img);
		i++;
	}
	if (g_screenbuf.img)
		mlx_destroy_image(g_env.mlx, g_screenbuf.img);
	if (g_env.win)
		mlx_destroy_window(g_env.mlx, g_env.win);
	if (g_env.mlx)
	{
		mlx_destroy_display(g_env.mlx);
		free(g_env.mlx);
	}
}
