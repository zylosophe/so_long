/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:33:48 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/08 15:16:01 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "room_utils.h"

void	room_fromfile3(t_room *room)
{
	int	x;
	int	y;

	x = -1;
	while (++x < room->width)
	{
		y = -1;
		while (++y < room->height)
		{
			if (y == 0 || y == room->height - 1)
			{
				room->surfaces[y * room->width + x] = sprite_init(CASE_WALL);
				room->objects[y * room->width + x] = NULL;
			}
			else
				room->surfaces[y * room->width + x] = sprite_init(
						CASE_FLOOR_1 + (x + y) % 2);
		}
	}
}
