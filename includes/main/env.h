/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:26:13 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/20 16:14:20 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 400
# define WINDOW_TITLE "undretale"
# define FPS 20
# define TEXT_SPACE 9
# define LEVEL_COUNT 10

typedef struct s_env
{
	// GLOBAL
	t_memclass				mc;
	t_loopfunctions			loopfunctions;

	// IO
	// display
	void					*mlx;
	void					*win;
	// input
	bool					input[4];
	bool					enter;

	// GAME
	// levels
	const t_const_string	*levels;
	int						level_count;
	int						level_current;
	int						level_to_load;
	// play
	t_room					room;
	t_camera				camera;
	int						ketchup;
	int						max_ketchup;
	bool					snas_moved;
	// moves
	int						moves;
}							t_env;
extern t_env				g_env;

typedef struct s_consts
{
	t_const_string	levels[LEVEL_COUNT];
	t_assetmeta		assetsmap[NB_ASSETS];
	t_spritemeta	spritesmap[NB_SPRITES];
	t_roomcase		roomcases[];
}	t_consts;
extern const t_consts		g_consts;

#endif
