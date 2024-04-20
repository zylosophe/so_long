/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:28:34 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/20 13:30:47 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	expose_hook(void)
{
	display_flush();
	return (0);
}

int	close_hook(void)
{
	success();
	return (0);
}

static void	loop(void)
{
	if (g_env.loopfunctions.loop == room_loop
		&& g_env.level_to_load != g_env.level_current)
	{
		g_env.level_current = g_env.level_to_load;
		init_level();
	}
	input_loop();
	g_env.loopfunctions.loop();
	display_erase();
	g_env.loopfunctions.draw();
	display_flush();
}

int	loop_hook(void)
{
	timedloop(loop);
	return (0);
}

int	main(int argc, t_const_string *argv)
{
	if (argc > 2)
		error_str("so_long", "takes max 1 argument");
	g_env.mc = mem_newclass(error_err);
	g_env.mlx = mlx_init();
	if (!g_env.mlx)
		error_err("mlx_init() failed");
	mlx_do_key_autorepeatoff(g_env.mlx);
	display_init();
	g_env.win = mlx_new_window(g_env.mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			WINDOW_TITLE);
	if (!g_env.win)
		error_err("mlx_new_window() failed");
	if (argc == 2)
		init_levels(1, &argv[1]);
	else
		init_levels(LEVEL_COUNT, g_consts.levels);
	mlx_expose_hook(g_env.win, expose_hook, NULL);
	mlx_hook(g_env.win, DestroyNotify, StructureNotifyMask, close_hook, NULL);
	mlx_loop_hook(g_env.mlx, loop_hook, NULL);
	mlx_hook(g_env.win, KeyPress, KeyPressMask, key_press_hook, NULL);
	mlx_hook(g_env.win, KeyRelease, KeyReleaseMask, key_release_hook, NULL);
	mlx_loop(g_env.mlx);
}
