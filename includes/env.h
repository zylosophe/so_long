/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:26:13 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/28 12:50:14 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "libtf.h"
# include "room.h"

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 400
# define WINDOW_TITLE "undretale"
# define FPS 20
# define WALK_STEPS_NB 4

typedef struct s_env
{
	t_memclass	mc;
	void		*mlx;
	void		*win;
	t_room		room;

	bool		up;
	bool		down;
	bool		left;
	bool		right;
}				t_env;

extern t_env	g_env;

#endif
