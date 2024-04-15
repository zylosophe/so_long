/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:34:56 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/15 18:09:36 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static t_point	find_snas_position(void)
{
	const t_room	room = g_env.room;
	t_point			pos;
	t_object		*obj;
	t_character		character;

	pos.y = -1;
	while (++pos.y < room.height)
	{
		pos.x = -1;
		while (++pos.x < room.width)
		{
			obj = room.objects[pos.y * room.width + pos.x];
			if (obj && obj->type.init == snas_init)
			{
				character = ((t_snas_data *)obj->data)->character;
				return (point_subpoint(point_add(point_multiply(pos, 50), 25),
						point_multiply(point_fromdirection(character.direction),
							character.walk_remaining_steps * 50
							/ character.walk_steps_nb
						)));
			}
		}
	}
	error_err("snas is nowhere");
	return (point_init(0, 0));
}

static void	limit(int *n, int min, int max)
{
	if (*n < min)
		*n = min;
	if (*n > max)
		*n = max;
}

void	camera_sync(void)
{
	const t_point	obj_pos = find_snas_position();
	const t_point	room_dims = point_multiply(
			point_init(g_env.room.width, g_env.room.height), 50);
	t_point *const	camera_pos = &g_env.camera.pos;

	if (room_dims.x <= WINDOW_WIDTH)
		camera_pos->x = -(WINDOW_WIDTH - room_dims.x) / 2;
	else
	{
		camera_pos->x = obj_pos.x - WINDOW_WIDTH / 2;
		limit(&camera_pos->x, 0, room_dims.x - WINDOW_WIDTH);
	}
	if (room_dims.y <= WINDOW_HEIGHT)
		camera_pos->y = -(WINDOW_HEIGHT - room_dims.y) / 2;
	else
	{
		camera_pos->y = obj_pos.y - WINDOW_HEIGHT / 2;
		limit(&camera_pos->y, 0, room_dims.y - WINDOW_HEIGHT);
	}
}
