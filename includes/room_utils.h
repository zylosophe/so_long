/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:34:01 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/13 16:46:44 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_UTILS_H
# define ROOM_UTILS_H

# include "libtf.h"
# include "room.h"

int			getlinelen(t_const_string line);
void		room_getsize(t_memclass mc, t_room *r, t_const_string path);
t_roomcase	*getroomcase(t_const_string path, char c);

#endif
