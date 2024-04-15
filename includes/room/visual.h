/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:34:18 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/11 17:07:59 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

typedef struct s_visual
{
	t_sprite	spr;
}				t_visual;

void	visual_loop(t_visual **visual, t_point p);
void	visual_addtoroom(t_spritesmap_id sprid, t_point pos);

#endif
