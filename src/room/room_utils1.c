/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:21:33 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/21 19:47:00 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "room_utils.h"

static int	getlinelen(t_const_string line)
{
	int	r;

	r = str_len(line);
	if (line[r - 1] == '\n')
		r--;
	return (r);
}

void	room_getsize(t_memclass mc, t_room *r, t_const_string path)
{
	int					fd;
	t_const_string		line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_perror(path);
	line = read_line(err_remember, mc, fd);
	if (err_get())
		error_perror(path);
	if (!line)
		error_str(path, "room is empty");
	r->width = getlinelen(line);
	r->height = 1;
	while (true)
	{
		line = read_line(err_remember, mc, fd);
		if (err_get())
			error_perror(path);
		if (!line)
			break ;
		if (getlinelen(line) != r->width)
			error_str(path, "the room must be rectangular");
		r->height++;
	}
}

const t_roomcase	*getroomcase(t_const_string path, char c)
{
	int	i;

	i = -1;
	while (g_consts.roomcases[++i].c)
	{
		if (g_consts.roomcases[i].c == c)
			return (&g_consts.roomcases[i]);
	}
	error_str(path, "unknown char");
	return (NULL);
}

void	room_checkaccessibilities(t_const_string path)
{
	t_point		p;
	t_object	*obj;
	t_point		snas_pos;

	snas_pos = room_find(snas_init);
	p.y = -1;
	while (++p.y < g_env.room.height)
	{
		p.x = -1;
		while (++p.x < g_env.room.width)
		{
			obj = g_env.room.objects[p.y * g_env.room.width + p.x];
			if (obj && obj->type.init == ketchup_init)
				if (pathfinding(snas_pos, p, false) == NO_DIRECTION)
					error_str(path, "all collectibles must be accessible.");
		}
	}
	if (pathfinding(snas_pos, room_find(exit_init), false) == NO_DIRECTION)
		error_str(path, "the exit must be accessible.");
}

void	room_endingdraw(void)
{
	const int	time = g_env.room.time_after_ending;
	t_point		p;

	g_env.room.time_after_ending++;
	if (time < 30)
		return ;
	p = point_init(200, 75);
	display_text(&p, TEXT_REGULAR_YOUFOUNDTHEULTIMATEKETCHUP_1);
	if (time < 60)
		return ;
	p = point_init(25, 125);
	display_text(&p, TEXT_REGULAR_YOUFOUNDTHEULTIMATEKETCHUP_2);
	if (time < 100)
		return ;
	p = point_init(235, 310);
	display_text(&p, TEXT_REGULAR_IN_X_MOVES_1);
	p.x += TEXT_SPACE;
	display_uint(&p, g_env.moves, false);
	p.x += TEXT_SPACE;
	display_text(&p, TEXT_REGULAR_IN_X_MOVES_2);
}
