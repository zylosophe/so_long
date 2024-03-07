/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:27:06 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/11 15:54:15 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_assets.h"

/**
 * Path of each asset relative to assets/, without extension.
 */
const t_assetinfo	g_assetsmap[NB_ASSETS] = {
{"floor/1", 50, 100, 50, 100, true},
{"floor/2", 50, 100, 50, 100, true},
	// WALL
{"wall/border", 50, 100, 50, 100, true},
{"wall/inner", 50, 100, 30, 100, false},
	// OBJECTS
	// snas
{"object/snas/down", 50, 100, 30, 100, false},
{"object/snas/up", 50, 100, 30, 100, false},
{"object/snas/left", 50, 100, 30, 100, false},
{"object/snas/right", 50, 100, 30, 100, false},
	// firsk
{"object/firsk/down", 50, 110, 30, 100, false},
{"object/firsk/up", 40, 100, 30, 100, false},
{"object/firsk/left", 50, 100, 30, 100, false},
{"object/firsk/right", 50, 110, 30, 100, false},
	// ketchup
{"object/ketchup/still/1", 50, 100, 40, 110, false},
{"object/ketchup/still/2", 50, 100, 40, 110, false},
{"object/ketchup/still/3", 50, 100, 40, 110, false},
{"object/ketchup/still/4", 50, 100, 40, 110, false},
{"object/ketchup/fade/1", 50, 100, 40, 110, false},
{"object/ketchup/fade/2", 50, 100, 30, 120, false},
{"object/ketchup/fade/3", 50, 100, 20, 130, false},
	// exit
{"object/exit/inactive/1", 50, 100, 50, 100, false},
{"object/exit/inactive/2", 50, 100, 50, 100, false},
{"object/exit/active/1", 50, 100, 50, 100, false},
{"object/exit/active/2", 50, 100, 50, 100, false},
{"object/exit/active/3", 50, 100, 50, 100, false},
{"object/exit/active/4", 50, 100, 50, 100, false},
{"object/exit/using1/1", 50, 100, 50, 100, false},
{"object/exit/using1/2", 50, 100, 50, 100, false},
{"object/exit/using1/3", 50, 100, 50, 100, false},
{"object/exit/using1/4", 50, 100, 50, 100, false},
{"object/exit/using2/1", 40, 110, 40, 110, false},
{"object/exit/using2/2", 40, 110, 40, 110, false},
{"object/exit/using2/3", 30, 120, 30, 120, false},
{"object/exit/using2/4", 50, 100, 50, 100, false},
{"object/exit/using2/5", 50, 100, 50, 100, false},
{"object/exit/using2/6", 50, 100, 50, 100, false},
{"object/exit/using2/7", 50, 100, 50, 100, false}
};
