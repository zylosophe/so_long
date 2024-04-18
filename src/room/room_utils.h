/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:23:43 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/18 21:08:02 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_UTILS_H
# define ROOM_UTILS_H

typedef struct s_roomcase
{
	char			c;
	t_object_init	object;
	t_spritesmap_id	surface;
}					t_roomcase;

void		room_getsize(t_memclass mc, t_room *r, t_const_string path);
t_roomcase	*getroomcase(t_const_string path, char c);
int			room_count(t_object_init objtype);
void		room_checkwallsallaround(t_const_string path, t_room *room);
t_point		to_camera_pos(t_point p);
void		room_checkaccessibilities(t_const_string path);
void		room_drawsurfaceandobjects(void);

#endif
