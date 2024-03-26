/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:00:45 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/26 16:06:02 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_H
# define ROOM_H

# include "sprite.h"
# include "libtf.h"
# include "object.h"

typedef struct s_room
{
	int			width;
	int			height;
	t_sprite	*surfaces;
	t_object	**objects;
	t_memclass	mc;
}				t_room;

typedef struct s_roomcase
{
	char			c;
	t_spriteid		surface_spr;
	t_object_init	object;
}					t_roomcase;

t_room	room_fromfile(t_const_string path);

void	room_loop(t_room room);

void	room_draw(t_room room);

void	room_free(t_room room);

#endif
