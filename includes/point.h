/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:05:03 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/27 18:22:51 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "data_assets.h"

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

t_point	point_init(int x, int y);
void	point_addto(t_point *dest, t_point src);
t_point	point_fromdirection(t_direction direction);
t_point	point_multiply(t_point point, int x);

#endif
