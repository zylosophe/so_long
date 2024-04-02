/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:58:25 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/02 17:49:28 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

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
	bool			solid;
}					t_object;

typedef t_object		(*t_object_init)(t_memclass);

#endif
