/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:31:22 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/29 17:32:47 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "room.h"
#include "error.h"
#include "libtf.h"
#include "env.h"
#include "room_utils.h"

t_object	*room_getobjectfaced(
				t_room room, t_character *character, t_point pos)
{
	point_addto(&pos, point_fromdirection(character->direction));
	return (room.objects[pos.y * room.width + pos.x]);
}

bool	room_canwalk(t_room room, t_character *character, t_point pos)
{
	t_point		after;
	t_object	*obj;

	after = pos;
	point_addto(&after, point_fromdirection(character->direction));
	if (after.y <= 0 || after.y >= room.height - 1
		|| after.x <= 0 || after.x >= room.width - 1)
		return (false);
	obj = room_getobjectfaced(room, character, pos);
	return (!obj || !obj->solid);
}
