/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:35:28 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/03 16:01:04 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	visual_loop(t_visual **visual, int x, int y)
{
	if (!(*visual))
		return ;
	if (!sprite_draw(x, y, &(*visual)->spr))
	{
		mem_free(*visual);
		*visual = 0;
	}
}

void	visual_addtoroom(t_spritesmap_id sprid, t_point pos)
{
	t_visual	*visual;
	t_sprite	spr;

	visual = mem_alloc(error_err, g_env.room.mc, sizeof(t_visual));
	spr = sprite_init(sprid);
	visual->spr = spr;
	g_env.room.visuals[pos.y * g_env.room.width + pos.x] = visual;
}
