/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:26:17 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/26 13:36:33 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libtf.h"
#include "env.h"
#include <X11/keysym.h>

void	input_init(void)
{
	g_env.up = false;
	g_env.down = false;
	g_env.left = false;
	g_env.right = false;
}

static void	setkey(int keycode, bool value)
{
	if (keycode == XK_Up || keycode == XK_Z || keycode == XK_z
		|| keycode == XK_W || keycode == XK_w)
		g_env.up = value;
	if (keycode == XK_Down || keycode == XK_S || keycode == XK_s)
		g_env.down = value;
	if (keycode == XK_Left || keycode == XK_Q || keycode == XK_q
		|| keycode == XK_A || keycode == XK_a)
		g_env.left = value;
	if (keycode == XK_Right || keycode == XK_D || keycode == XK_d)
		g_env.right = value;
}

int	key_press_hook(int keycode)
{
	setkey(keycode, true);
	return (0);
}

int	key_release_hook(int keycode)
{
	setkey(keycode, false);
	return (0);
}
