/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:23:43 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/21 19:29:37 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_UTILS_H
# define ROOM_UTILS_H

void				room_getsize(t_memclass mc, t_room *r, t_const_string path);
const t_roomcase	*getroomcase(t_const_string path, char c);
void				room_checkwallsallaround(t_const_string path, t_room *room);
t_point				to_camera_pos(t_point p);
void				room_checkaccessibilities(t_const_string path);
void				room_drawsurfaceandobjects(void);
void				room_endingdraw(void);

#endif
