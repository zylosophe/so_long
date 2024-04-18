/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:47:01 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/18 18:17:16 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

// SNAS
typedef enum e_snas_state
{
	SNAS_STATE_DEFAULT,
	SNAS_STATE_GOING_TO_EXIT,
	SNAS_STATE_DISAPPEARS,
	SNAS_STATE_WAITING_TO_WIN,
}	t_snas_state;

typedef struct s_snas_data
{
	t_character		character;
	t_snas_state	state;
	t_sprite		tp_spr;
	int				wait_before_win;
}					t_snas_data;

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
