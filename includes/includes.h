/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:53:41 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/23 01:11:25 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# define XK_Left 0xFF51
# define XK_Up 0xFF52
# define XK_Right 0xFF53
# define XK_Down 0xFF54
# define XK_S 0x0053
# define XK_Z 0x005a
# define XK_Q 0x0051
# define XK_D 0x0044
# define XK_W 0x0057
# define XK_A 0x0041
# define XK_s XK_S + 0x20
# define XK_z XK_Z + 0x20
# define XK_q XK_Q + 0x20
# define XK_d XK_D + 0x20
# define XK_w XK_W + 0x20
# define XK_a XK_A + 0x20
# define XK_Escape 0xFF1B
# define XK_Return 0xFF0D
# define DestroyNotify 17
# define StructureNotifyMask 1L<<17
# define KeyPress 2
# define KeyRelease 3
# define KeyPressMask 1L<<0
# define KeyReleaseMask 1L<<1

# include <windows.h>
# include <math.h>
# include <fcntl.h>
# include <time.h>
# include <stdbool.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>
# include <errno.h>
# include "libtf.h"
# include "mlx.h"

# include "main/main.h"

# include "utils/direction.h"
# include "utils/point.h"
# include "utils/map.h"

# include "display/pixel.h"
# include "display/data_assets.h"
# include "display/data_sprites.h"
# include "display/display.h"
# include "display/sprite.h"
# include "display/text.h"

# include "main/error.h"

# include "room/visual.h"
# include "room/object.h"
# include "room/character.h"
# include "gameover/gameover.h"
# include "room/objects.h"
# include "room/room.h"
# include "room/camera.h"
# include "room/pathfinding.h"

# include "main/levels.h"
# include "main/env.h"
# include "main/input.h"
# include "main/timedloop.h"

#endif
