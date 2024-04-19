/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameover_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:19:30 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/19 13:06:08 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEOVER_UTILS_H
# define GAMEOVER_UTILS_H

# include "includes.h"

typedef struct s_gameover_env
{
	t_point		snaspos;
	t_sprite	spr_snas;
	t_sprite	spr_attack;
	t_sprite	spr_explosion1;
	t_sprite	spr_explosion2;
	int			state;
}	t_gameover_env;

#endif
