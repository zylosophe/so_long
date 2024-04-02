/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:47:01 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/02 17:48:38 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

// SNAS
typedef struct s_snas_data
{
	t_character	character;
}				t_snas_data;

t_object		snas_init(t_memclass mc);

// WALL
typedef struct s_wall_data
{
	t_sprite	spr;
}				t_wall_data;

t_object		wall_init(t_memclass mc);

#endif
