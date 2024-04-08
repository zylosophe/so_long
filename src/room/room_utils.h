/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:34:01 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/08 15:13:43 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_UTILS_H
# define ROOM_UTILS_H

typedef struct s_roomcase
{
	char			c;
	t_object_init	object;
}					t_roomcase;

int			getlinelen(t_const_string line);
void		room_getsize(t_memclass mc, t_room *r, t_const_string path);
t_roomcase	*getroomcase(t_const_string path, char c);
void		moveobject(t_room room, t_point start, t_point move);
bool		isinlist(void *addr, t_list list);
void		room_fromfile3(t_room *room);

#endif
