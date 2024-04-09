/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:00:45 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/09 14:22:51 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_H
# define ROOM_H

typedef struct s_room
{
	int			width;
	int			height;
	t_sprite	*surfaces;
	t_object	**objects;
	t_visual	**visuals;
	t_memclass	mc;
}				t_room;

void		room_init(t_const_string path);

void		room_loop(t_room room);

void		room_draw(t_room room);

void		room_free(t_room room);

t_object	*room_getobjectfaced(
				t_room room, t_character *character, t_point pos);

bool		room_canwalk(
				t_room room, t_character *character, t_point pos);

#endif
