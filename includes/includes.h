/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:53:41 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/15 17:41:18 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <fcntl.h>
# include <time.h>
# include <stdbool.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include <errno.h>
# include "libtf.h"
# include "mlx.h"

# include "utils/direction.h"
# include "utils/point.h"
# include "utils/map.h"

# include "display/pixel.h"
# include "display/data_assets.h"
# include "display/data_sprites.h"
# include "display/display.h"
# include "display/sprite.h"

# include "room/visual.h"
# include "room/object.h"
# include "room/character.h"
# include "room/objects.h"
# include "room/room.h"
# include "room/camera.h"
# include "room/pathfinding.h"

# include "main/env.h"
# include "main/error.h"
# include "main/input.h"
# include "main/timedloop.h"
# include "main/main.h"

#endif
