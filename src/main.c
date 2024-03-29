/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:28:34 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/29 18:33:10 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "env.h"
#include "error.h"
#include "display.h"
#include "data_assets.h"
#include "room.h"
#include "input.h"
#include "timedloop.h"
#include <X11/Xlib.h>

int	expose_hook(void)
{
	display_flush();
	return (0);
}

int	close_hook(void)
{
	mlx_do_key_autorepeaton(g_env.mlx);
	finish();
	return (0);
}

static void	loop(void)
{
	input_loop();
	room_loop(g_env.room);
	display_erase();
	room_draw(g_env.room);
	display_flush();
}

int	loop_hook(void)
{
	timedloop(loop);
	return (0);
}

int	main(void)
{
	g_env.mc = mem_newclass(err);
	g_env.mlx = mlx_init();
	if (!g_env.mlx)
		err("mlx_init() failed");
	display_init();
	g_env.win = mlx_new_window(g_env.mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			WINDOW_TITLE);
	if (!g_env.win)
		err("mlx_new_window() failed");
	g_env.room = room_fromfile("room/room.ber");
	room_draw(g_env.room);
	mlx_expose_hook(g_env.win, expose_hook, NULL);
	mlx_hook(g_env.win, DestroyNotify, StructureNotifyMask, close_hook, NULL);
	mlx_loop_hook(g_env.mlx, loop_hook, NULL);
	mlx_do_key_autorepeatoff(g_env.mlx);
	mlx_hook(g_env.win, KeyPress, KeyPressMask, key_press_hook, NULL);
	mlx_hook(g_env.win, KeyRelease, KeyReleaseMask, key_release_hook, NULL);
	mlx_loop(g_env.mlx);
}
