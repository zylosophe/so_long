/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levels1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:49:39 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/19 13:18:45 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	ask_retry(bool current)
{
	t_point	p;

	p = point_init(WINDOW_WIDTH - 26 - 219, WINDOW_HEIGHT - 26 - 26);
	display_text(&p, TEXT_LITTLE_PRESSENTERTORETRY);
	if (g_env.enter)
	{
		if (!current)
		{
			g_env.moves = 0;
			g_env.level_current = 0;
		}
		init_level();
	}
}

void	init_levels(int count, t_const_string *srcs)
{
	g_env.moves = 0;
	g_env.levels = srcs;
	g_env.level_count = count;
	if (count <= 0)
		error_err("if you don't want to play any level don't start the game");
	init_level();
}

static void	end_loop(void)
{
}

static void	end_draw(void)
{
	t_point	p;

	p = point_init(200, 120);
	display_text(&p, TEXT_BIG_YOUWIN);
	p = point_init(200, 210);
	display_text(&p, TEXT_REGULAR_IN_X_MOVES_1);
	p.x += TEXT_SPACE;
	display_uint(&p, g_env.moves, false);
	p.x += TEXT_SPACE;
	display_text(&p, TEXT_REGULAR_IN_X_MOVES_2);
	g_env.level_current = 0;
	ask_retry(false);
}

void	win(void)
{
	g_env.level_current++;
	if (g_env.level_current >= g_env.level_count)
	{
		g_loopfunctions.loop = end_loop;
		g_loopfunctions.draw = end_draw;
	}
	else
		init_level();
}
