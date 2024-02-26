/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:26:13 by mcolonna          #+#    #+#             */
/*   Updated: 2024/02/27 16:47:57 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "libtf.h"

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 400
# define WINDOW_TITLE "undretale"

typedef struct s_env
{
	t_memclass	mc;
	void		*mlx;
	void		*win;
}				t_env;

extern t_env	g_env;

#endif
