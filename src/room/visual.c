/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:35:28 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/18 17:15:45 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	visual_loop(t_visual **visual, t_point p)
{
	if (!(*visual))
		return ;
	if (!sprite_draw(p, &(*visual)->spr))
	{
		mem_free(*visual);
		*visual = 0;
	}
}

void	visual_addtoroom(t_sprite spr, t_point pos)
{
	t_visual	*visual;

	visual = mem_alloc(error_err, g_env.room.mc, sizeof(t_visual));
	visual->spr = spr;
	g_env.room.visuals[pos.y * g_env.room.width + pos.x] = visual;
}
