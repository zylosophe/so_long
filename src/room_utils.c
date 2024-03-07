/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:26:28 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/13 16:55:56 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "room_utils.h"
#include "error.h"

static t_roomcase	g_roomcases[] = {
{c: '0', surface_spr: CASE_FLOOR},
{c: '1', surface_spr: CASE_WALL},
{c: '\0'}
};

int	getlinelen(t_const_string line)
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
		err_perror(path);
	line = read_line(err_remember, mc, fd);
	if (err_get())
		err_perror(path);
	if (!line)
		err_perror_str(path, "room is empty");
	r->width = getlinelen(line);
	r->height = 1;
	while (true)
	{
		line = read_line(err_remember, mc, fd);
		if (err_get())
			err_perror(path);
		if (!line)
			break ;
		if (getlinelen(line) != r->width)
			err_perror_str(path, "the lines have different lengths");
		r->height++;
	}
}

t_roomcase	*getroomcase(t_const_string path, char c)
{
	int	i;

	i = -1;
	while (g_roomcases[++i].c)
	{
		if (g_roomcases[i].c == c)
			return (&g_roomcases[i]);
	}
	err_perror_str(path, "unknown char");
	return (NULL);
}
