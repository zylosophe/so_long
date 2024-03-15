/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:24:37 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/15 15:26:34 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

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
