/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:58:25 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/18 15:56:04 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

typedef struct s_object		t_object;
typedef struct s_character	t_character;

typedef t_object			(*t_object_init)(t_memclass);

typedef struct s_objecttype
{
	t_object_init	init;
	bool			solid_snas;
	bool			solid_firsk;
	t_point			(*loop)(t_object *, t_point pos);
	void			(*draw)(t_object *, t_point p);
	// Called when a character want to walk through this object.
	// Returns false to block the character. If true, it will pass.
	// If walk_through is NULL, the character is blocked.
	bool			(*walk_through)(t_object *, t_character *, t_point pos);
}					t_objecttype;

typedef struct s_object
{
	t_objecttype	type;
	void			*data;
}					t_object;

#endif
