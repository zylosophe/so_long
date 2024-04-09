/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:05:30 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/09 15:29:39 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "display_utils.h"

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
	if (!g_screenbuf.img)
		error_err("on mlx_new_image()");
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
	const t_memclass	mc = mem_subclass(error_err, g_env.mc);
	t_string			str;

	mlx_put_image_to_window(g_env.mlx, g_env.win, g_screenbuf.img, 0, 0);
	str = str_inttostr(error_err, mc, g_env.moves);
	mlx_string_put(g_env.mlx, g_env.win, 0, 10, 0xFFFFFF, str);
	mem_freeall(mc);
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
