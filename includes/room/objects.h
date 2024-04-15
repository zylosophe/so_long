/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:47:01 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/11 13:54:23 by mcolonna         ###   ########.fr       */
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

// KETCHUP
typedef struct s_ketchup_data
{
	t_sprite	spr;
}				t_ketchup_data;

t_object		ketchup_init(t_memclass mc);

// EXIT
typedef struct s_exit_data
{
	t_sprite	spr;
	bool		active;
}				t_exit_data;

// FIRSK
typedef struct s_firsk_data
{
	t_character	character;
}				t_firsk_data;

t_object		firsk_init(t_memclass mc);

t_object		exit_init(t_memclass mc);

#endif
