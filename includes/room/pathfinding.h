/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:13:05 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/18 13:50:36 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHFINDING_H
# define PATHFINDING_H

# include "includes.h"

t_direction	pathfinding(t_point start, t_point finish, bool solid_bridge);

#endif
