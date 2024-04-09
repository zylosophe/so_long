/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:26:17 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/09 13:44:46 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int	g_input_i = 0;
static bool	g_to_unpress[4] = {false, false, false, false};
static bool	g_inputbuf[4] = {false, false, false, false};

static void	set_direction(t_direction direction, bool value)
{
	static int	last_press[4] = {0, 0, 0, 0};

	if (value)
	{
		last_press[direction] = g_input_i;
		g_to_unpress[direction] = false;
	}
	if (!value && last_press[direction] == g_input_i)
	{
		g_to_unpress[direction] = true;
		return ;
	}
	g_inputbuf[direction] = value;
}

static void	setkey(int keycode, bool value)
{
	static const int	keymap[] = {
		XK_Down, XK_S, XK_s, 0,
		XK_Up, XK_Z, XK_z, XK_W, XK_w, 0,
		XK_Left, XK_Q, XK_q, XK_A, XK_a, 0,
		XK_Right, XK_D, XK_d, 0};
	t_direction			direction;
	int					i;

	direction = -1;
	i = -1;
	while (++direction < 4)
		while (keymap[++i])
			if (keymap[i] == keycode)
				return (set_direction(direction, value));
}

int	key_press_hook(int keycode)
{
	if (keycode == XK_Escape)
		success();
	setkey(keycode, true);
	return (0);
}

int	key_release_hook(int keycode)
{
	setkey(keycode, false);
	return (0);
}

void	input_loop(void)
{
	t_direction	direction;

	g_input_i++;
	direction = -1;
	while (++direction < 4)
	{
		g_env.input[direction] = g_inputbuf[direction];
		if (g_to_unpress[direction])
			set_direction(direction, false);
	}
}
