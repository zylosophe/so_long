/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:05:03 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/11 18:05:53 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

t_point	point_init(int x, int y);
t_point	point_add(t_point point, int x);
void	point_addto(t_point *dest, t_point src);
t_point	point_fromdirection(t_direction direction);
t_point	point_multiply(t_point point, int x);
t_point	point_subpoint(t_point p1, t_point p2);

#endif
