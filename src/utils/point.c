/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:24:37 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/02 14:41:19 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

t_point	point_init(int x, int y)
{
	const t_point	r = {x, y};

	return (r);
}

void	point_addto(t_point *dest, t_point src)
{
	dest->x += src.x;
	dest->y += src.y;
}

t_point	point_fromdirection(t_direction direction)
{
	if (direction == LEFT)
		return (point_init(-1, 0));
	if (direction == RIGHT)
		return (point_init(+1, 0));
	if (direction == UP)
		return (point_init(0, -1));
	if (direction == DOWN)
		return (point_init(0, +1));
	return (point_init(0, 0));
}

t_point	point_multiply(t_point point, int x)
{
	point.x *= x;
	point.y *= x;
	return (point);
}
