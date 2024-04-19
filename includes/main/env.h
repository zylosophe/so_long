/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:26:13 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/19 12:29:10 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 400
# define WINDOW_TITLE "undretale"
# define FPS 20
# define TEXT_SPACE 9

typedef struct s_env
{
	t_memclass		mc;
	void			*mlx;
	void			*win;
	t_room			room;
	bool			input[4];
	bool			enter;
	int				ketchup;
	int				max_ketchup;
	int				moves;
	t_camera		camera;
	t_const_string	*levels;
	int				level_count;
	int				level_current;
}					t_env;

extern t_env	g_env;

#endif
