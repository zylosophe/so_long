/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:04:41 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/11 17:24:53 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "room_utils.h"

static void	checkwall(t_const_string path, t_object *obj)
{
	if (!obj || obj->type.init != wall_init)
		error_str(path, "there must have walls all around the room");
}

void	room_checkwallsallaround(t_const_string path, t_room *room)
{
	int		i;

	i = -1;
	while (++i < room->width)
		checkwall(path, room->objects[i]);
	i = (room->height - 1) * room->width - 1;
	while (++i < room->width * room->height)
		checkwall(path, room->objects[i]);
	i = 0;
	while (i < room->width * room->height)
	{
		checkwall(path, room->objects[i]);
		i += room->width;
	}
	i = room->width - 1;
	while (i < room->width * room->height)
	{
		checkwall(path, room->objects[i]);
		i += room->width;
	}
}

t_point	to_camera_pos(t_point p)
{
	t_point	r;

	r.x = p.x * 50 - g_env.camera.pos.x;
	r.y = p.y * 50 - g_env.camera.pos.y;
	return (r);
}
