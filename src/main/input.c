/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:26:17 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/20 15:40:29 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "input_utils.h"

static void	set_direction(t_direction direction, bool value)
{
	t_input_hidden *const	hidden = get_input_hidden();
	static int				last_press[4] = {0, 0, 0, 0};

	if (value)
	{
		last_press[direction] = hidden->input_i;
		hidden->to_unpress[direction] = false;
	}
	if (!value && last_press[direction] == hidden->input_i)
	{
		hidden->to_unpress[direction] = true;
		return ;
	}
	hidden->inputbuf[direction] = value;
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
	t_input_hidden *const	hidden = get_input_hidden();

	if (keycode == XK_Escape)
		success();
	if (keycode == XK_Return)
		hidden->enter = true;
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
	t_input_hidden *const	hidden = get_input_hidden();
	t_direction				direction;

	g_env.enter = hidden->enter;
	hidden->enter = false;
	hidden->input_i++;
	direction = -1;
	while (++direction < 4)
	{
		g_env.input[direction] = hidden->inputbuf[direction];
		if (hidden->to_unpress[direction])
			set_direction(direction, false);
	}
}
