/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:49:39 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/18 18:02:40 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static void	init_level_index(void)
{
	g_loopfunctions.loop = room_loop;
	g_loopfunctions.draw = room_draw;
	room_init(g_env.levels[g_env.level_current]);
}

void	init_levels(int count, t_const_string *srcs)
{
	g_env.levels = srcs;
	g_env.level_count = count;
	if (count <= 0)
		error_err("if you don't want to play any level don't start the game");
	g_env.level_current = 0;
	init_level_index();
}

void	win(void)
{
	g_env.level_current++;
	if (g_env.level_current >= g_env.level_count)
		error_err("end all levels!"); // TODO
	init_level_index();
}
