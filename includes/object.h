/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:58:25 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/15 20:06:45 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "point.h"
# include "data_assets.h"
# include "libtf.h"
# include "display.h"
# include "sprite.h"

typedef struct s_object	t_object;

typedef struct s_objecttype
{
	t_point	(*loop)(t_object *, t_point pos);
	void	(*draw)(t_object *, int x, int y);
}			t_objecttype;

typedef struct s_object
{
	t_objecttype	type;
	void			*data;
}					t_object;

typedef struct s_snas_data
{
	t_direction	direction;
	t_sprite	spr;
}				t_snas_data;

typedef t_object		(*t_object_init)(t_memclass);

t_object	snas_init(t_memclass mc);

#endif
