/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:27:03 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/15 20:00:25 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "error.h"
#include "sprite.h"

static t_point	snas_loop(t_object *obj, t_point pos)
{
	const t_point	r = {0, 0};

	(void)((void)obj, pos);
	return (r);
}

static void	snas_draw(t_object *obj, int x, int y)
{
	sprite_draw(x, y, &((t_snas_data *)obj->data)->spr);
}

t_object	snas_init(t_memclass mc)
{
	static const t_objecttype	type = {loop: snas_loop, draw: snas_draw};
	t_object					r;
	t_snas_data					*data;

	r.type = type;
	data = mem_alloc(err, mc, sizeof(t_snas_data));
	data->direction = DOWN;
	data->spr = sprite_init(SPR_SNAS_DOWN);
	r.data = data;
	return (r);
}
