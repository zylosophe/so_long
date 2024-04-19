/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levels2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:18:06 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/19 19:46:14 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	init_level(void)
{
	if (g_env.level_current >= g_env.level_count)
		win();
	g_loopfunctions.loop = room_loop;
	g_loopfunctions.draw = room_draw;
	room_init(g_env.levels[g_env.level_current]);
}
